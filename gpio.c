#include<lpc21xx.h>
#include"gpio.h"
void gpio_init(void)
{
//select gpio functions
PINSEL0 &=0X0000FFFF;
PINSEL1 &=~0X000000FC;
//configure keypad rows as o/p
IODIR0|=(1<<R1)|(1<<R2)|(1<<R3)|(1<<R4);
//configure keypad cols as I/P
IODIR0|=(1<<C1)|(1<<C2)|(1<<C3)|(1<<C4);
//Configure LED as O/P
IODIR0|=(1<<G)|(1<<R)|(1<<B);
//turn off active low leds
IOSET0=(1<<G)|(1<<R)|(1<<B);
}