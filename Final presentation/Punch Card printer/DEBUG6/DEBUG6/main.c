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
		
		for(int i=0;i<=16;i+=4)
		{
			int x,z;
			
			int a[2],b[2];
			a[0]=data[i]-'0';
			a[1]=data[i+1]-'0';
			b[0]=data[i+2]-'0';
			b[1]=data[i+3]-'0';
			
			 x=a[0]*10+a[1];
			 z=b[0]*10+b[1];
			
		
			
			binary(x,z,print);
			
			
			printit(print);
			
		}
		come();
		
		

		
		
    }
}
void binary(int a ,int c ,int b[])
{
	
	
	for(int i=4;i>=1;i--)
	{
		b[0]=1;
		b[i]=a%2;
		a=a/2;
	}
	
	for(int i=7;i>=5;i--)
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
	   DDRC=0xff;
	   DDRA=0xFF;
	   float tz =1.5;
	   
	   float tx=1.5;
	   int i,j ,z ,y;
	   
	   
		   
		 for( z=0 ; z<columns ;z++) // y axis moves bit by bit
		 {
			 

			 
			 if(z !=columns -1 )
			 {
				 if(c[z]==1)
				 {
					 // PUNCHER IS AT THE TOP
					 for(int j=0;j<25;j++)
					 {
						 
						 
						 PORTA = 0x08;
						 _delay_ms(tz);
						 PORTA = 0x02;
						 _delay_ms(tz);
						 PORTA = 0x04;
						 _delay_ms(tz);
						 PORTA = 0x01;
						 _delay_ms(tz);
					 }
					 _delay_ms(200);
					 
					 //puncher is rotating 360*3
					 
					 for(int j=0;j<150;j++)
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
					 _delay_ms(200);
					 for(int j=0;j<25;j++)
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
					 _delay_ms(200);
					 
					 
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
				 // y-move forward
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
				 
				 if(c[z] ==1)
				 {
					 //Giving only one punch
					 //puncher
					 for(int j=0;j<25;j++) // down
					 {
						 
						 
						 PORTA = 0x08;
						 _delay_ms(tz);
						 PORTA = 0x02;
						 _delay_ms(tz);
						 PORTA = 0x04;
						 _delay_ms(tz);
						 PORTA = 0x01;
						 _delay_ms(tz);
					 }
					 _delay_ms(200);
					 for(int j=0;j<150;j++)
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
					 _delay_ms(200);
					 for(int j=0;j<25;j++) //up
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
					 _delay_ms(200);

					 
					 // coming back to the starting point
					 for(y=0; y<columns-1 ;y++) //y moves backwards
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
					 
					 for(y=0; y<columns -1;y++) //y moves backwards
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
}
void come()
{
	float tx=1.5;
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
