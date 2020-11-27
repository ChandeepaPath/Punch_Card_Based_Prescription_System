/*
 * final1.c
 *
 * Created: 1/18/2020 12:02:34 PM
 * Author : Chandeepa
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include "uart.c"

#include <util/delay.h>

#include <string.h>
#include <stdlib.h>



void splstring(char str[] , char a[]);
void binary(int a ,int c ,int b[]);
void printit(int c[]);
void come();


	char data[50];
	char split[11];
	int print[8];
int main(void)
{
    UART_Init(2400);
	DDRB=0xFF;
	PORTB=0xFF;

    while (1) 
    {
		
		for(int i=0;i<19;i++)
		{
			data[i]=UART_RxChar();
		}
		splstring(data,split);
		
		
		for(int i=0;i<10;i+=2)
		{	
			int x,z;
			
			 z= split[i]-'0';
			 x= split[i++]-'0';
			
			binary(z,x,print);
		
			printit(print);
		}
		 come();
		
		
    }
}


void splstring(char str[] , char a[])
{
	

	int b=0;
	for(int i=0;i<= strlen(str);i++)
	{
		if(str[i]!=',')
		{
			a[b]=str[i];
			b++;
		}
		
	}

}
void binary(int a ,int c ,int b[])
{
	 
	 //int b[8];
	 
	 for(int i=0;i<4;i++)
	 {
		 b[i]=a%2;
		 a=a/2;
	 }
	 
	 for(int i=4;i<7;i++)
	 {
		 b[i]=c%2;
		 c=c/2;
	 }
	 
	
	
}


	 //-------------------------------

void printit(int c[])
{
int columns= 8;
int rows = 6;
DDRD=0xFF;
DDRB=0xFF;
DDRC=0xFF;
DDRA=0xFF;
float tz =2;
float tx=2.8;
int i,j ,z ,y;

		
		
		
			
			for( z=0 ; z<columns ;z++) // y axis moves bit by bit
			{
				if(z !=columns -1 )
				{
					if(c[z]==1)
					{
						//puncher
						for(int j=0;j<50;j++)
						{
							
							
							PORTA = 0x01;
							_delay_ms(tz);
							PORTA = 0x04;
							_delay_ms(tz);
							PORTA = 0x02;
							_delay_ms(tz);
							PORTA = 0x08;
							_delay_ms(tz);
						}
						
						//y -move forward
						for( j=0;j<56;j++) //449
						{
							
							
							PORTB = 0x01;
							_delay_ms(tx);
							PORTB = 0x04;
							_delay_ms(tx);
							PORTB = 0x02;
							_delay_ms(tx);
							PORTB = 0x08;
							_delay_ms(tx);
						}
					}else
					for( j=0;j<56;j++) //449
					{
						
						
						PORTB = 0x01;
						_delay_ms(tx);
						PORTB = 0x04;
						_delay_ms(tx);
						PORTB = 0x02;
						_delay_ms(tx);
						PORTB = 0x08;
						_delay_ms(tx);
					}
					
				}else
				{
					//puncher is at the end of the row
					for( j=0;j<56;j++) //449
					{
						
						
						PORTB = 0x01;
						_delay_ms(tx);
						PORTB = 0x04;
						_delay_ms(tx);
						PORTB = 0x02;
						_delay_ms(tx);
						PORTB = 0x08;
						_delay_ms(tx);
					}
					if(c[z] ==1)
					{
						//Giving only one punch
						//puncher
						for(int j=0;j<50;j++)
						{
							
							
							PORTA = 0x01;
							_delay_ms(tz);
							PORTA = 0x04;
							_delay_ms(tz);
							PORTA = 0x02;
							_delay_ms(tz);
							PORTA = 0x08;
							_delay_ms(tz);
						}
						// coming back to the starting point
						for(y=0; y<columns ;y++) //y moves backwards
						{
							for( i= 0; i<56 ;i++)
							{
								PORTB = 0x08;
								_delay_ms(tx);
								PORTB = 0x02;
								_delay_ms(tx);
								PORTB = 0x04;
								_delay_ms(tx);
								PORTB = 0x01;
								_delay_ms(tx);
							}
						}
					}
					else
					{
						
						for(y=0; y<columns ;y++) //y moves backwards
						{
							for( i= 0; i<56 ;i++)
							{
								PORTB = 0x08;
								_delay_ms(tx);
								PORTB = 0x02;
								_delay_ms(tx);
								PORTB = 0x04;
								_delay_ms(tx);
								PORTB = 0x01;
								_delay_ms(tx);
							}
						}
					}
				}
			}

			//x axis moves forward
			for(z=0 ;z<56;z++)
			{
				
				PORTD = 0x80;
				_delay_ms(tx);
				PORTD = 0x20;
				_delay_ms(tx);
				PORTD = 0x40;
				_delay_ms(tx);
				PORTD = 0x10;
				_delay_ms(tx);
				
			}
	
		//x coming back
		
		

	
}
void come()
{
	float tx=2.8;
	int j ,z;
	for(j=0 ; j<4;j++)
		{
			for(z=0 ;z<56;z++)
			{
				
				PORTD = 0x10;
				_delay_ms(tx);
				PORTD = 0x40;
				_delay_ms(tx);
				PORTD = 0x20;
				_delay_ms(tx);
				PORTD = 0x80;
				_delay_ms(tx);
			}
		}
}
