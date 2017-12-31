#include "system.h"
#include "uart.h"
#include "aes.h"

#include <string.h>

//34C3___I_kn0w_dis_th1s_1s_A3S___

char entered[32] = {0};
const char enc_flag[] = {'\xd9', '5', '\x0f', '\xb8', ';', '\xef', '\xee', '\x00', '\xfb', '\xcf', '\x8b', '\xea', '\xa3', '\x18', '\x9c', '\xeb', '\xaf', '\xa9', ')', '\xd4', '\x90', '\xe1', '\x8c', '\x98', 'r', '\x0e', '|', '\x1b', '\x9f', '3', 'T', '<'};

int main(int argc, char const *argv[])
{
    system_init();
    uart_init();

    uart_puts("Enter flag: ");

    for(int i = 0; i < sizeof(entered); i++)
    {
        entered[i] = uart_getc();
        uart_putc(entered[i]);
    }

    uart_puts("\r\n");

    struct AES_ctx aes_ctx;
    AES_init_ctx(&aes_ctx, "EGh4UW2chae4Eeng");
    AES_ECB_encrypt(&aes_ctx, entered);
    AES_ECB_encrypt(&aes_ctx, &entered[sizeof(entered)/2]);

    if(memcmp(entered, enc_flag, sizeof(entered)) == 0)
        uart_puts("Correct!\r\n");
    else
        uart_puts("Wrong!\r\n");

    while(1);
    return 0;
}
