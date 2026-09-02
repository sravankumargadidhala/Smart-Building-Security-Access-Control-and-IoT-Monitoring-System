#include "header.h"
void entry_log(void)
{
	//	gettime();
	//	getdate();
	i2c_write(0xA0,0x01,hours);
	delay_ms(10);
	i2c_write(0xA0,0x02,minutes);
	delay_ms(10);
	i2c_write(0xA0,0x03,seconds);
	delay_ms(10);
	if(hours<0x12)
		i2c_write(0xA0,0x04,'A');
	else
		i2c_write(0xA0,0x04,'P');
	delay_ms(10);
	i2c_write(0xA0,0x05,date);
	delay_ms(10);
	i2c_write(0xA0,0x06,month);
	delay_ms(10);
	i2c_write(0xA0,0x07,year);
	delay_ms(10);
}

