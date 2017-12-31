#include "system.h"
#include "uart.h"

int main(int argc, char const *argv[])
{
    system_init();

    uart_init();
    uart_puts("The flag is: 34C3_I_4dm1t_it_1_f0und_th!s_with_str1ngs\r\n");

    while(1);

    return 0;
}
