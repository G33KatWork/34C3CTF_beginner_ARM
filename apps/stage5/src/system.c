#include "system.h"
#include "stm32f1xx.h"

void system_init()
{
    // Enable prefetch buffer and set flash latency to 2
    FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_2;

    /* Configure system clock
     * External oscillator: 8MHz
     * Max PLL multiplicator: x9
     * Max SYSCLK: 72MHz
     * Max AHB: SYSCLK = 72MHz
     * Max APB1: SYSCLK/2 = 36MHz
     * Max APB2: SYSCLK = 72MHz
     * Max ADC: SYSCLK/6 = 12MHz (max freq 14) */
    RCC->CFGR =
          RCC_CFGR_PLLMULL9             /* PLL multiplicator is 9 */
        | RCC_CFGR_PLLXTPRE_HSE         /* oscillator prescaler is /1 */
        | RCC_CFGR_PLLSRC               /* PLL input is external oscillator */
        | RCC_CFGR_ADCPRE_DIV6          /* ADC prescaler is 6 */
        | RCC_CFGR_PPRE2_DIV1           /* APB2 prescaler is 1 */
        | RCC_CFGR_PPRE1_DIV2           /* APB1 prescaler is 2 */
        | RCC_CFGR_HPRE_DIV1;           /* AHB prescaler is 1 */

    // Enable external oscillator
    RCC->CR = RCC_CR_HSEON;

    // Wait for lock on external oscillator
    while((RCC->CR & RCC_CR_HSERDY) != RCC_CR_HSERDY);

    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;

    // Wait for PLL lock
    while((RCC->CR & RCC_CR_PLLRDY) != RCC_CR_PLLRDY);

    // Switch system clock source to PLL
    RCC->CFGR &= ~(RCC_CFGR_SW);
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    // Wait for switch to complete
    while((RCC->CFGR & RCC_CFGR_SW) != RCC_CFGR_SW_PLL);
}
