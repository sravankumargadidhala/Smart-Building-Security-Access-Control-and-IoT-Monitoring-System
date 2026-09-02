#include "header.h"
void uart0_init(unsigned int baud)
{
	int pclk,result=0;
	if(VPBDIV==0x0)
		pclk=15000000;
	else if(VPBDIV==0x01)
		pclk=60000000;
	else if(VPBDIV==0x02)
		pclk=30000000;
	result=pclk/(16*baud);
	PINSEL0|=5;
	U0LCR=0x83;
	U0DLL=(result&0xff);
	U0DLM=((result>>8)&0xff);
	U0LCR=0x03;
}
#define THRE ((U0LSR>>5)&1)

void uart0_tx(unsigned char data)
{
	U0THR=data;
	while(THRE==0);
}
#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
	while(RDR==0);
	return U0RBR;
}
void uart0_tx_string(char *ptr)
{
	while(*ptr)
	{
		uart0_tx(*ptr);
		ptr++;
	}
}

void uart0_int(int num )
{
	if(num>10)
		uart0_int(num/10);
	uart0_tx((num%10)+48); 
}

void uart0_rx_string(char *ptr)
{
	char ch;
	int i=0;
	while(1)
	{
		ch=uart0_rx();
		uart0_tx(ch);
		if(ch=='\r'||ch=='\n')
			break;
		ptr[i++]=ch;
	}
	ptr[i]='\0';
}

int uart0_rx_integer(void)
{
	int i,num1;
	char s[10];
	uart0_rx_string(s);
	if(s[0]=='-'||s[0]=='+')
		i=1;
	else
		i=0;
	for(i=0,num1=0;s[i];i++)
	{
		num1=num1*10+(s[i]-48);
	}
	if(s[0]=='-')
		num1=-num1;
	return num1;
}

