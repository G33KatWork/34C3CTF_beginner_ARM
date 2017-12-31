#ifndef _UART_H_
#define _UART_H_

void uart_init(void);
void uart_putc(char c);
void uart_puts(const char* s);
char uart_getc(void);

#endif
