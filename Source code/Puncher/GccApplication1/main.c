/*
 * GccApplication1.c
 *
 * Created: 20-Dec-19 7:30:45 PM
 * Author : Chandeepa
 */
#include <avr/io.h>
#include <util/delay.h>
int columns= 8;
int rows = 3;
int main(void)
{
   DDRD=0xFF;
   DDRB=0xFF;
   DDRC=0xff;
   DDRA=0xFF;
   int c[]={1,0,1,1,0,0,1,1};
   float tz =2;
  
   float tx=1.5;
  int i,j ,z ,y;
  
  
for(int r=0 ;r<rows;r++)
{
	
for( z=0 ; z<columns ;z++) // y axis moves bit by bit
{
	

	
	if(z !=columns -1 )
	{
		if(c[z]==1)
		{
			//puncher
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
				
				
				PORTB = 0x08;
				_delay_ms(tx);
				PORTB = 0x02;
				_delay_ms(tx);
				PORTB = 0x04;
				_delay_ms(tx);
				PORTB = 0x01;
				_delay_ms(tx);
			}
			
			//puncher lifting upwards
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
				
				

		}else
		//puncher lifting upwards
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
			for( j=0;j<56;j++) //449
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
		
		
	}else
		{
			//puncher is at the end of the row
		
			if(c[z] ==1)
			{
				//Giving only one punch
			//puncher
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

		
				// coming back to the starting point
				for(y=0; y<columns-1 ;y++) //y moves backwards
				{
					for( i= 0; i<56 ;i++)
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
				}
			}
			else
			{
		
				for(y=0; y<columns -1;y++) //y moves backwards
				{
					for( i= 0; i<56 ;i++)
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
				}
			}
	}
	}

	//x axis moves forward
	for(z=0 ;z<57;z++)
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
}
//x coming back
//puncher lifts 
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
for(j=0 ; j<3;j++)
{
	for(z=0 ;z<57;z++)
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
	//final
	
	


}


   
   
 