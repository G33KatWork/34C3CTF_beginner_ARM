#include "system.h"
#include "uart.h"

//34C3_L00k_ma!_1_c4n_d0_ARM_now

char entered[30] = {0};

int main(int argc, char const *argv[])
{
    system_init();
    uart_init();

    uart_puts("Enter flag: ");

    for(int i = 0; i < 30; i++)
    {
        entered[i] = uart_getc();
        uart_putc(entered[i]);
    }

    uart_puts("\r\n");

    if(
        entered[9] == 95 && 
        entered[21] == 48 && 
        entered[26] == 95 && 
        entered[2] == 67 && 
        entered[14] == 49 && 
        entered[0] == 51 && 
        entered[28] == 111 && 
        entered[11] == 97 && 
        entered[4] == 95 && 
        entered[27] == 110 && 
        entered[17] == 52 && 
        entered[8] == 107 && 
        entered[3] == 51 && 
        entered[23] == 65 && 
        entered[15] == 95 && 
        entered[7] == 48 && 
        entered[1] == 52 && 
        entered[24] == 82 && 
        entered[18] == 110 &&
        entered[5] == 76 &&
        entered[20] == 100 &&
        entered[12] == 33 &&
        entered[22] == 95 &&
        entered[13] == 95 &&
        entered[10] == 109 &&
        entered[29] == 119 && 
        entered[16] == 99 && 
        entered[19] == 95 && 
        entered[25] == 77
    )
        uart_puts("Correct!\r\n");
    else
        uart_puts("Wrong!\r\n");

    while(1);
    return 0;
}
