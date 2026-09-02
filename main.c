#include <LPC21xx.H>
#include "header.h"

int main()
{
	char rfid[]="4900C8FDDCA0",key[]="1234";
	char scan[13],password[5],f1=0,f2=0;

	int i;
	init();// in delay.c
	servo_0deg();
	IODIR0&=~(1<<15);

	while(1)
	{
		uart0_tx_strin("Waiting for motion\r\n");
		if(pir)
		{
			uart0_tx_string("Motion detected\r\n");
			lcd_string("Scan RFID");
			uart0_tx_string("Scan rfid : ");
			for(i=0;i<13;i++)
				scan[i]='\0';
			for(i=0;i<12;i++)
				scan[i]=uart0_rx();
			scan[12]='\0';
			if(strcmp(rfid,scan)==0)
			{
				gettime();
				getdate();
				f1=1;
				lcd_cmd(0x01);
				lcd_string("RFID Valid");
				uart0_tx_string("RFID valid\r\n");
				uart0_tx_string("Door open\r\n");
				displaytime_uart();
				delay_sec(1);
				servo_180deg();
				delay_sec(4);
				entry_log();
			}else
			{
				uart0_tx_string("Invalid ID scanned \r\n");
				uart0_tx_string("Acess denied\r\n");
				uart0_tx_string("Enter key :");
				for(i=0;i<4;i++)
				{
					password[i]=keypad_read();
					//password[i]=uart0_rx();
					uart0_tx(password[i]);
					delay_ms(200);
				}
				password[4]='\0';
				uart0_tx_string("\r\n");
				if(strcmp(password,key)==0)
				{
					f2=1;
					gettime();getdate();
					uart0_tx_string("Valid key acess granted\r\n");
					uart0_tx_string("Door opened at ");
					displaytime_uart();
					servo_90deg();
					delay_sec(5);
					entry_log();
				}
				else
				{
					uart0_tx_string("Wrong password\r\n");
					uart0_tx_string("Acess denied\r\n");
				}
			}
		}
		if(f1==1||f2==1)
		{
			uart0_tx_string("Entry logged successfully at : \r\n");
			displaytime_uart();
			displaydate_uart();
			servo_0deg();
			f1=0,f2=0;

		}
	}
}


