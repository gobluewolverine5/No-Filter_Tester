# pragma db code
# include<reg51.h>
# define uchar unsigned char
void rece(void);
void init(void);
uchar re[17];
/*������*/
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
/*���ڳ�ʼ��*/
void init(void)
{
TMOD=0x20;           //��ʱ��1--��ʽ2 
PCON=0x80;           //��Դ����
SCON=0x50;           //��ʽ1
TL1=0xFA;             
TH1=0xFA;            //22.1184MHz���񣬲�����Ϊ4800 0xf3   9600	0xfa   19200 0xfd 
TR1=1;               //Timer1��ʼ����
}
/*���շ�������*/
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
