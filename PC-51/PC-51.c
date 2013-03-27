# pragma db code
# include<reg51.h>
# define uchar unsigned char
void rece(void);
void init(void);
uchar re[17];
/*主程序*/
void main(void)
{ 
uchar temp;
init();
do{
   while(RI==0);
   temp=SBUF;
   if(temp==0x00)
    {rece();}
   else break; 
  }while(1);	
}
/*串口初始化*/
void init(void)
{
TMOD=0x20;           //定时器1--方式2 
PCON=0x80;           //电源控制
SCON=0x50;           //方式1
TL1=0xFA;             
TH1=0xFA;            //22.1184MHz晶振，波特率为4800 0xf3   9600	0xfa   19200 0xfd 
TR1=1;               //Timer1开始计数
}
/*接收返回数据*/
void rece(void)
{
char i;
i=0;
do{
  while(RI==0);
  re[i]=SBUF;
  RI=0;
  SBUF=re[i];
  while(TI==0);
  TI=0;
  i++; 
  }while(re[i-1]!=255);
}
