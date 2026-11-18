#include<lpc21xx.h>
#include"gpio.h"
#include"keypad.h"
#include"servo.h"
#include"rfid.h"
#include"header.h"
#include"string.h"

int main()
{
int i,key;
char password[5];
char card[13];
gpio_init();
keypad_init();
servo_init();
void rfid_read(char *card);
while(1)
{
//read rfid card
lcd_cmd(0x01);
lcd_string("scan your card");
rfid_read(card);
//verify rfid card
if(strcmp(card,"123456789012")==0)                                                   
{
IOCLR0=(1<<G);
lcd_cmd(0x01);
lcd_string("card accepted");
//enter password
lcd_cmd(0xc0);
lcd_string("enter password");
for(i=0;i<4;i++)
{
key=keypad_read();
password[i]=key;
}
password[4]='\0';
//verify password
if(strcmp(password,"1234")==0)
{
IOSET0=(1<<G);
IOCLR0=(1<<B);
lcd_cmd(0x01);
lcd_string("access granted");
//open door
servo_open();
delay_ms(30000);
servo_close();
IOSET0=(1<<B);
}
else
{
IOCLR0=(1<<R);
lcd_cmd(0x01);
lcd_string("wrong password");
delay_ms(20000);
IOSET0=(1<<R);
}
}
else
{
IOCLR0=(1<<R);
lcd_cmd(0x01);
lcd_string("invalid card");
delay_ms(20000);
IOSET0=(1<<R);
}
}
}