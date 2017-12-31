#include "system.h"
#include "uart.h"

const char flag[] = {102, 97, 22, 102, 10, 13, 101, 39, 10, 102, 59, 54, 39, 44, 37, 33, 60, 101, 59, 10, 100, 38, 10, 55, 102, 38, 33, 10, 54, 39, 44, 37, 33, 101, 0};

int main(int argc, char const *argv[])
{
    system_init();
    uart_init();

    uart_puts("The flag is: ");
    const char* s = flag;
    while(*s)
    {
        uart_putc(*s ^ 0x55);
        s++;
    }
    uart_puts("\r\n");

    while(1);

    return 0;
}
