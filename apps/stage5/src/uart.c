#include "uart.h"
#include "stm32f1xx.h"

#define UART_BUS_FREQ 72000000

#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)         (((_PCLK_)*25)/(4*(_BAUD_)))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)     (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)     (((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100)) * 16 + 50) / 100)
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)         ((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4)|(UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0F))

void uart_init()
{
    //Enable USART1 clock
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

    //Enable GPIOA clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    //PA9: TX
    //PA10: RX

    //PA9 Push/Pull alternate function, Output max speed
    GPIOA->CRH &= ~(GPIO_CRH_CNF9 | GPIO_CRH_MODE9);
    GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_MODE9_1;

    //PA10
    GPIOA->CRH &= ~(GPIO_CRH_CNF10 | GPIO_CRH_MODE10);
    GPIOA->CRH |= GPIO_CRH_CNF10_1;
    
    //No remapping on USART1 -> PA9/PA10
    AFIO->MAPR &= ~AFIO_MAPR_USART1_REMAP;

    //USART1 enable, RX enable, TX enable
    USART1->CR1 |= (USART_CR1_UE | USART_CR1_RE | USART_CR1_TE);

    //8 bit, no parity
    USART1->CR1 &= ~(USART_CR1_M | USART_CR1_PCE);

    //1 stop bit
    USART1->CR2 &= ~(USART_CR2_STOP);

    //set baudrate
    USART1->BRR = UART_BRR_SAMPLING16(UART_BUS_FREQ, 115200);
}

void uart_putc(char c)
{
    while((USART1->SR & USART_SR_TXE) == 0);
    USART1->DR = c;
}

void uart_puts(const char* s)
{
    while(*s)
        uart_putc(*s++);
}

char uart_getc()
{
    while((USART1->SR & USART_SR_RXNE) == 0);
    return (char)USART1->DR;
}
