#include "header.h"
void delay_sec(unsigned int num)
{
	T0PR=15000000-1;
	T0TC=0;
	T0PC=0;
	T0TCR=2;
	T0TCR=1;
	while(T0TC<num);
	T0TCR=0;
}
void delay_ms(unsigned int num)
{
	T0PR=15000-1;
	T0TC=0;
	T0PC=0;
	T0TCR=2;
	T0TCR=1;
	while(T0TC<num);
	T0TCR=0;
}
void init(void)
{
	uart0_init(9600);
	uart0_tx_string("Smart Security System\r\n");
	uart0_tx_string("Welcome...\r\n");
	i2c_init();
	lcd_init();
	servo_init();
	keypad_init();
	settime(0x12,0x59,0x55);
	setdate(0x19,0x08,0x26);
}

