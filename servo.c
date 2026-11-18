#include<lpc21xx.h>
#include"servo.h"
void servo_init(void)
{
//select pwm2 function for p0.7
PINSEL0 &=~(3<<14);
PINSEL0 |=(2<<14);
//CONFIGURE PWM
PWMTCR=0X02;
PWMPR=14;
PWMMR0=20000;
PWMMR2=1500;
PWMMCR=(1<<1);
PWMPCR=(1<<10);
PWMLER=(1<<0)|(1<<2);
PWMTCR=0X09;
}
void servo_open(void)
{
    PWMMR2 = 1000;
    PWMLER = (1 << 2);
}

void servo_close(void)
{
    PWMMR2 = 2000;
    PWMLER = (1 << 2);
}