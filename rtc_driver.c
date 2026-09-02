#include "header.h"
u8 hours,minutes,seconds;
u8 date,month,year;

void settime(u8 hours,u8 minutes,u8 seconds)
{
	i2c_write(0XD0,0x00,seconds);
	i2c_write(0XD0,0x01,minutes);
	i2c_write(0XD0,0x02,hours);
}
void setdate(u8 date,u8 month,u8 year)
{
	i2c_write(0XD0,0x04,date);
	i2c_write(0XD0,0x05,month);
	i2c_write(0XD0,0x06,year);
}
void gettime(void)
{
	seconds = i2c_read(0XD1,0x00);
	minutes = i2c_read(0XD1,0x01);
	hours  = i2c_read(0XD1,0x02);
}
void getdate(void)
{
	date  = i2c_read(0XD1,0x04);
	month = i2c_read(0XD1,0x05);
	year  = i2c_read(0XD1,0x06);
}
void displaytime(void)
{
	// gettime();
	lcd_cmd(0xc0);
	lcd_cmd(0x80);

	lcd_data((hours>>4)+'0');
	lcd_data((hours&0x0F)+'0');
	lcd_data(':');

	lcd_data((minutes>>4)+'0');
	lcd_data((minutes&0x0F)+'0');
	lcd_data(':');

	lcd_data((seconds>>4)+'0');
	lcd_data((seconds&0x0F)+'0');
	if(hours<0x12)
		lcd_data('A');
	else
		lcd_data('P');
}
void displaydate(void)
{
	//getdate();
	lcd_cmd(0xc0);
	lcd_data((date>>4)+'0');
	lcd_data((date&0x0F)+'0');
	lcd_data('/');
	lcd_data((month>>4)+'0');
	lcd_data((month&0x0F)+'0');
	lcd_data('/');
	lcd_data('2');
	lcd_data('0');
	lcd_data((year>>4)+'0');
	lcd_data((year&0x0F)+'0');
}

void displaytime_uart(void)
{
	// gettime();

	uart0_tx((hours >> 4) + '0');
	uart0_tx((hours & 0x0F) + '0');
	uart0_tx(':');
	uart0_tx((minutes >> 4) + '0');
	uart0_tx((minutes & 0x0F) + '0');
	uart0_tx(':');
	uart0_tx((seconds >> 4) + '0');
	uart0_tx((seconds & 0x0F) + '0');
	uart0_tx_string(" ");
	if(hours<=0x12)
		uart0_tx('A');
	else
		uart0_tx('P');
}

void displaydate_uart(void)
{
	// gettime();
	uart0_tx((date >> 4) + '0');
	uart0_tx((date & 0x0F) + '0');
	uart0_tx('/');
	uart0_tx((month >> 4) + '0');
	uart0_tx((month & 0x0F) + '0');
	uart0_tx('/');
	uart0_tx((year >> 4) + '0');
	uart0_tx((year & 0x0F) + '0');
	uart0_tx_string("\r\n");
}

