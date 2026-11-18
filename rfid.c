#include<lpc21xx.h>
#include"rfid.h"
#include"header.h"
void rfid_read(char * card)
{
int i;
for(i=0;i<12;i++)
{
card[i]=uart0_rx();
}
card[12]='\0';
}
