#include<lpc21xx.h>
#include<string.h>
typedef unsigned char u8;
typedef unsigned int   u32;
#define pir ((IOPIN0>>15)&1)
extern u8 hours,minutes,seconds;
extern u8 date,month,year;
extern void init(void);
extern void entry_log(void);
//delay functions
extern void delay_ms(unsigned int num);
extern void delay_sec(unsigned int num);
//keypad functions
extern void keypad_init(void);
extern char keypad_scan(void);
//lcd functions
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(char *ptr);
//uart0 functions
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *ptr);
extern void uart0_rx_string(char *ptr);
extern int uart0_rx_integer(void);
//i2c functions
extern void i2c_init(void);
extern void i2c_write(u8 sa, u8 mr, u8 data);
extern u8 i2c_read(u8 sa,u8 mr);
//rtc functions
extern void settime(u8 hr,u8 min,u8 sec);
extern void setdate(u8 date,u8 month,u8 year);
extern void gettime(void);
extern void getdate(void);
extern void displaydate(void);
extern void displaytime(void);
extern void displaytime_uart(void);
extern void displaydate_uart(void);
//servo functions
extern void servo_init(void);
extern void servo_0deg(void);
extern void servo_90deg(void);
extern void servo_180deg(void);

