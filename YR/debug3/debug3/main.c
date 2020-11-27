/*
 * debug3.c
 *
 * Created: 1/21/2020 11:42:49 PM
 * Author : yashi
 */ 

#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#define  F_CPU 1000000UL
#include "uart.c"
#include <util/delay.h>

void binary(int a ,int c ,int b[]);
void printit(int c[]);
void come();

int main(void)
{
   
	
	char data[50];
	int print[8];
	
	
	UART_Init(2400);// uart initialize
	
    while (1) 
    {
		for(int i=0;i<20;i++)
		{
			
			data[i]=UART_RxChar();
		}
		
		for(int i=0;i<=12;i+=4)
		{
			int x,z;
			
			char a[2],b[2];
			a[0]=data[i];
			a[1]=data[i+1];
			b[0]=data[i+2];
			b[1]=data[i+3];
			
			
			
			x=atoi(a);
			z=atoi(b);
			
			/*if(z==2)
			{
				PORTB=0x00;
			}*/
			
			binary(x,z,print);
			/*if((print[1]==1)&&(print[3]==1)&&(print[4]==1)&&(print[5]==1)&&(print[6]==1))
			{
				PORTB=0x00;
			}*/
			printit(print);
			
		}
		come();
		
		

		
		
    }
}
void binary(int a ,int c ,int b[])
{
	
	
	for(int i=1;i<=4;i++)
	{
		b[0]=1;
		b[i]=a%2;
		a=a/2;
	}
	
	for(int i=5;i<=7;i++)
	{
		b[i]=c%2;
		c=c/2;
	}
}
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
	for(j=0 ; j<5;j++)
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
