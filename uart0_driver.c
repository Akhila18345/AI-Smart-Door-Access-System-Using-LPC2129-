#include<lpc21xx.h>
void uart0_init(unsigned int baud)
{
unsigned int pclk,result=0;
if(VPBDIV==0X0)
pclk=15000000;
else if(VPBDIV==0X1)
pclk=6000000;
else if(VPBDIV==0X2)
pclk=3000000;
result=(pclk/(16*baud));
PINSEL0 |=0X5;
U0LCR=0X83;
U0DLL=(result&0xff);
U0DLM=(result>>8)&0xff;
U0LCR=0X03;
}
//TRANSMIT 1 BYTE DATA
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
U0THR =data;
while(THRE == 0);
}
//RECIEVE DATA
#define RDR (U0LSR&1)
unsigned char uart0_rx()
{
while(RDR == 0);
return U0RBR;
}
//TX STRING 
void uart0_tx_string(char *ptr)
{
while(*ptr!=0)
{
uart0_tx(*ptr);
ptr++;
}
}
//binary 
void uart0_binary(int num)
{
int temp,i;
for(i=7;i>=0;i--)
{
temp=((num>>i)&1);
uart0_tx(temp+48);
}
}

