#include "system.h"
#include "uart.h"

#include <stdint.h>

//34C3_1_d0_m4th

char flag[14] = {0};

int main(int argc, char const *argv[])
{
    system_init();
    uart_init();

    uart_puts("Enter flag: ");

    for(int i = 0; i < sizeof(flag); i++)
    {
        flag[i] = uart_getc();
        uart_putc(flag[i]);
    }

    uart_puts("\r\n");

    if(
        ((20 * flag[0]) + (-4 * flag[1]) + (64 * flag[2]) + (-12 * flag[3]) + (-73 * flag[4]) + (-65 * flag[5]) + (77 * flag[6]) + (20 * flag[7]) + (-66 * flag[8]) + (4 * flag[9]) + (-58 * flag[10]) + (-6 * flag[11]) + (94 * flag[12]) + (34 * flag[13]) == 8701) &&
        ((-66 * flag[0]) + (56 * flag[1]) + (-37 * flag[2]) + (-8 * flag[3]) + (-26 * flag[4]) + (-79 * flag[5]) + (-28 * flag[6]) + (-99 * flag[7]) + (-87 * flag[8]) + (-86 * flag[9]) + (71 * flag[10]) + (-69 * flag[11]) + (-43 * flag[12]) + (-48 * flag[13]) == -40417) &&
        ((93 * flag[0]) + (77 * flag[1]) + (-43 * flag[2]) + (-19 * flag[3]) + (99 * flag[4]) + (61 * flag[5]) + (5 * flag[6]) + (-67 * flag[7]) + (-60 * flag[8]) + (88 * flag[9]) + (41 * flag[10]) + (19 * flag[11]) + (70 * flag[12]) + (38 * flag[13]) == 34075) &&
        ((-44 * flag[0]) + (-32 * flag[1]) + (-30 * flag[2]) + (5 * flag[3]) + (56 * flag[4]) + (-28 * flag[5]) + (61 * flag[6]) + (9 * flag[7]) + (80 * flag[8]) + (40 * flag[9]) + (-66 * flag[10]) + (-42 * flag[11]) + (62 * flag[12]) + (64 * flag[13]) == 17090) &&
        ((-61 * flag[0]) + (46 * flag[1]) + (35 * flag[2]) + (-33 * flag[3]) + (91 * flag[4]) + (-13 * flag[5]) + (-39 * flag[6]) + (7 * flag[7]) + (51 * flag[8]) + (93 * flag[9]) + (55 * flag[10]) + (49 * flag[11]) + (94 * flag[12]) + (-40 * flag[13]) == 31516) &&
        ((17 * flag[0]) + (-61 * flag[1]) + (51 * flag[2]) + (26 * flag[3]) + (75 * flag[4]) + (14 * flag[5]) + (-32 * flag[6]) + (-46 * flag[7]) + (-10 * flag[8]) + (-36 * flag[9]) + (81 * flag[10]) + (69 * flag[11]) + (-32 * flag[12]) + (33 * flag[13]) == 10846) &&
        ((69 * flag[0]) + (-92 * flag[1]) + (24 * flag[2]) + (-33 * flag[3]) + (16 * flag[4]) + (57 * flag[5]) + (-31 * flag[6]) + (91 * flag[7]) + (85 * flag[8]) + (72 * flag[9]) + (23 * flag[10]) + (21 * flag[11]) + (45 * flag[12]) + (29 * flag[13]) == 31883) &&
        ((-22 * flag[0]) + (21 * flag[1]) + (52 * flag[2]) + (71 * flag[3]) + (76 * flag[4]) + (-80 * flag[5]) + (-97 * flag[6]) + (4 * flag[7]) + (99 * flag[8]) + (-7 * flag[9]) + (-43 * flag[10]) + (-13 * flag[11]) + (37 * flag[12]) + (-66 * flag[13]) == -2288) &&
        ((-59 * flag[0]) + (74 * flag[1]) + (65 * flag[2]) + (61 * flag[3]) + (-21 * flag[4]) + (-9 * flag[5]) + (44 * flag[6]) + (13 * flag[7]) + (30 * flag[8]) + (13 * flag[9]) + (-69 * flag[10]) + (-2 * flag[11]) + (9 * flag[12]) + (-63 * flag[13]) == 891) &&
        ((51 * flag[0]) + (58 * flag[1]) + (16 * flag[2]) + (58 * flag[3]) + (83 * flag[4]) + (30 * flag[5]) + (-57 * flag[6]) + (-27 * flag[7]) + (-28 * flag[8]) + (94 * flag[9]) + (55 * flag[10]) + (72 * flag[11]) + (-96 * flag[12]) + (74 * flag[13]) == 24772) &&
        ((68 * flag[0]) + (-5 * flag[1]) + (19 * flag[2]) + (-85 * flag[3]) + (38 * flag[4]) + (84 * flag[5]) + (17 * flag[6]) + (77 * flag[7]) + (-98 * flag[8]) + (-37 * flag[9]) + (-38 * flag[10]) + (32 * flag[11]) + (-45 * flag[12]) + (56 * flag[13]) == 7094) &&
        ((13 * flag[0]) + (99 * flag[1]) + (-21 * flag[2]) + (58 * flag[3]) + (26 * flag[4]) + (18 * flag[5]) + (-87 * flag[6]) + (26 * flag[7]) + (-77 * flag[8]) + (-47 * flag[9]) + (33 * flag[10]) + (-45 * flag[11]) + (-78 * flag[12]) + (59 * flag[13]) == -4767) &&
        ((-95 * flag[0]) + (63 * flag[1]) + (18 * flag[2]) + (-12 * flag[3]) + (56 * flag[4]) + (-77 * flag[5]) + (68 * flag[6]) + (70 * flag[7]) + (54 * flag[8]) + (41 * flag[9]) + (25 * flag[10]) + (-78 * flag[11]) + (43 * flag[12]) + (31 * flag[13]) == 27400) &&
        ((22 * flag[0]) + (-33 * flag[1]) + (-31 * flag[2]) + (-46 * flag[3]) + (20 * flag[4]) + (80 * flag[5]) + (-54 * flag[6]) + (55 * flag[7]) + (77 * flag[8]) + (94 * flag[9]) + (-89 * flag[10]) + (51 * flag[11]) + (-27 * flag[12]) + (-78 * flag[13]) == -4494)
    )
        uart_puts("Correct!\r\n");
    else
        uart_puts("Wrong!\r\n");

    while(1);
    return 0;
}
