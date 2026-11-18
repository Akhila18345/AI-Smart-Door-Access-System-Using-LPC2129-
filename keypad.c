#include<lpc21xx.h>
#include"keypad.h"
#include"header.h"
#include"gpio.h"
char key[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
void keypad_init(void)
{
//make all rows high initially
IOSET1=(1<<R1)|(1<<R2)|(1<<R3)|(1<<R4);
}
char keypad_read(void)
{
int row,col;
unsigned int row_pin[4]={R1,R2,R3,R4};
unsigned int col_pin[4]={C1,C2,C3,C4};
while(1)
{
for(row=0;row<4;row++)
{
IOSET0=(1<<R1)|(1<<R2)|(1<<R3)|(1<<R4);
IOCLR0=(1<<row_pin[row]);
for(col=0;col<4;col++)
{
//check whether col is low
if((IOPIN0 & (1 << col_pin[col])) == 0)
{
//wait until key is pressed or released
while((IOPIN0&(1<<col_pin[col]))==0);
return key[row][col];
}
}
}
}
}

