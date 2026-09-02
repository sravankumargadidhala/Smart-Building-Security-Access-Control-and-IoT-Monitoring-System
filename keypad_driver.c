#include<lpc21xx.h>
#include"header.h"
#include<string.h>



#define R1 (1<<8)
#define R2 (1<<9)
#define R3 (1<<10)
#define R4 (1<<11)

#define C1 (1<<4)
#define C2 (1<<5)
#define C3 (1<<6)
#define C4 (1<<24)
void keypad_init(void)
{
        IO0DIR |= (R1|R2|R3|R4);
        IO0DIR &= ~(C1|C2|C3|C4);
}

char keypad_read(void)
{
        while(1)
        {
                IO0SET = R2|R3|R4;
                IO0CLR = R1;

                if((IO0PIN & C1)==0){
                        delay_ms(20);
                        while((IO0PIN&C1)==0);
                        return '1';
                }
                if((IO0PIN & C2)==0){
                        delay_ms(20);
                        while((IO0PIN&C2)==0);
                        return '2';
                }
                if((IO0PIN & C3)==0){
                        delay_ms(20);
                        while((IO0PIN&C3)==0);
                        return '3';
                }
                if((IO0PIN & C4)==0){
                        delay_ms(20);
                        while((IO0PIN&C4)==0);
                        return 'A';
                }


                IO0SET = R1|R3|R4;
                IO0CLR = R2;

                if((IO0PIN & C1)==0){
                        delay_ms(20);
                        while((IO0PIN&C1)==0);
                        return '4';
                }
                if((IO0PIN & C2)==0){
                        delay_ms(20);
                        while((IO0PIN&C2)==0);
                        return '5';
                }
                if((IO0PIN & C3)==0){
                        delay_ms(20);
                        while((IO0PIN&C3)==0);
                        return '6';
                }
                if((IO0PIN & C4)==0){
                        delay_ms(20);
                        while((IO0PIN&C4)==0);
                        return 'B';
                }


                IO0SET = R1|R2|R4;
                IO0CLR = R3;

                if((IO0PIN & C1)==0){
                        delay_ms(20);
                        while((IO0PIN&C1)==0);
                        return '7';
                }
                if((IO0PIN & C2)==0){
                        delay_ms(20);
                        while((IO0PIN&C2)==0);
                        return '8';
                }

                if((IO0PIN & C3)==0){
                        delay_ms(20);
                        while((IO0PIN&C3)==0);
                        return '9';
                }
                if((IO0PIN & C4)==0){
                        delay_ms(20);
                        while((IO0PIN&C4)==0);
                        return 'C';
                }


                IO0SET = R1|R2|R3;
                IO0CLR = R4;

                if((IO0PIN & C1)==0){
                        delay_ms(20);
                        while((IO0PIN&C1)==0);
                        return '*';
                }
                if((IO0PIN & C2)==0){
                        delay_ms(20);
                        while((IO0PIN&C2)==0);
                        return '0';
                }
                if((IO0PIN & C3)==0){
                        delay_ms(20);
                        while((IO0PIN&C3)==0);
                        return '#';
                }
                if((IO0PIN & C4)==0){
                        delay_ms(20);
                        while((IO0PIN&C4)==0);
                        return 'D';
                }
        }
}
