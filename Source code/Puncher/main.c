


#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "lib/lcd/lcd_hd44780_avr.h"

void InitADC()
{
	ADMUX=(1<<REFS0);									// For Aref=AVcc;
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);	//  div factor =128
}

uint16_t ReadADC0( uint8_t ch0) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch0=ch0&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch0;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}
uint16_t ReadADC1( uint8_t ch1) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch1=ch1&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch1;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

uint16_t ReadADC2( uint8_t ch2) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch2=ch2&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch2;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

uint16_t ReadADC3( uint8_t ch3) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch3=ch3&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch3;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

uint16_t ReadADC4( uint8_t ch4) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch4=ch4&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch4;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

uint16_t ReadADC5( uint8_t ch5) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch5=ch5&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch5;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

uint16_t ReadADC6( uint8_t ch6) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch6=ch6&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch6;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

uint16_t ReadADC7( uint8_t ch7) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch7=ch7&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch7;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

void main()
{
	
	//Initialize LCD
	LCDInit(LS_NONE);
	LCDClear();

	//Initialize ADC
	InitADC();

	LCDClear();
LCDWriteFStringXY(0,1,PSTR("*  Enter your  *"));
LCDWriteFStringXY(16,1,PSTR("**   Card     **"));
	_delay_ms(500);
	LCDClear();

	
	
	LCDWriteFStringXY(0,0,PSTR("* Prescription *"));
	LCDWriteFStringXY(0,1,PSTR("****************"));
while(1){
	uint16_t x1 = ReadADC0(1) ;
	uint16_t x2 = ReadADC1(2);
	uint16_t x3 = ReadADC2(3);
	uint16_t x4 = ReadADC3(4);
	uint16_t q1 = ReadADC4(5);
	uint16_t q2 = ReadADC5(6);
	uint16_t q3 = ReadADC6(7);
	uint16_t d =  ReadADC7(0);  //d is considered as the start bit

if(d>800)
{
	
//*****************getting the Correct medicine************************
	if(x4<800 && x3<800 && x2<800 && x1<800)  //0000
	{
		LCDWriteFStringXY(16,0,PSTR("                      "));
	}
	else if(x4<800 && x3<800 && x2<800 && x1>800) //0001
	{
		LCDWriteFStringXY(16,0,PSTR("Panadol       "));
	
	}else if(x4<800 && x3<800 && x2>800 && x1<800) //0010
	{
		LCDWriteFStringXY(16,0,PSTR("Nizoral      "));  
		
	}else if(x4<800 && x3<800 && x2>800 && x1>800)    //0011
	{
		LCDWriteFStringXY(16,0,PSTR("Amoxicillin")); 
		
	}else if(x4<800 && x3>800 && x2<800 && x1<800)     //0100
	{
		LCDWriteFStringXY(16,0,PSTR("Cetirizine  "));
	
	}else if(x4<800 && x3>800 && x2<800 && x1>800)   //0101
	{
		LCDWriteFStringXY(16,0,PSTR("Thyroxine "));
	 
	}else if(x4<800 && x3>800 && x2>800 && x1<800)  //0110
	{
		LCDWriteFStringXY(16,0,PSTR("Losartan  ")); 
		
	}else if(x4<800 && x3>800 && x2>800 && x1>800)   //0111
	{
		LCDWriteFStringXY(16,0,PSTR("Atorvastatin  ")); 
		
	}else if(x4>800 && x3<800 && x2<800 && x1<800)    //1000
	{
		LCDWriteFStringXY(16,0,PSTR("Piriton    "));  
		
	}else if(x4>800 && x3<800 && x2<800 && x1>800)   //1001
	{
		LCDWriteFStringXY(16,0,PSTR("Vitamin C     "));  
		
	}else if(x4>800 && x3<800 && x2>800 && x1<800)  //1010
	{
		LCDWriteFStringXY(16,0,PSTR("Zincovit       "));
	  
	}else if(x4>800 && x3<800 && x2>800 && x1>800)   //1011
	{
		LCDWriteFStringXY(16,0,PSTR("Digene        ")); 
		 
	}else if(x4>800 && x3>800 && x2<800 && x1<800)   //1100
	{
		LCDWriteFStringXY(16,0,PSTR("Gaviscon        "));  
		
	}else if(x4>800 && x3>800 && x2<800 && x1>800)   //1101
	{
		LCDWriteFStringXY(16,0,PSTR("Imodium         "));
	  
	}else if(x4>800 && x3>800 && x2>800 && x1<800)   //1110
	{
		LCDWriteFStringXY(16,0,PSTR("Mefenamic Acid")); 

	}else
	{
		LCDWriteFStringXY(16,0,PSTR(""));    //1111

		
		
		
	}
//*****************Getting the quantity************************************

	if(q3<800 && q2<800 && q1<800 )   //000
	{
		LCDWriteFStringXY(16,1,PSTR(""));  

	}
	else if(q3<800 && q2<800 && q1>800 )   //001
	{
		LCDWriteFStringXY(16,1,PSTR("Qty   5mg"));
	
	}else if(q3<800 && q2>800 && q1<800 )   //010
	{
		LCDWriteFStringXY(16,1,PSTR("Qty 100mg")); //011
		
	}else if(q3<800 && q2>800 && q1>800 )
	{
		LCDWriteFStringXY(16,1,PSTR("Qty 200mg"));  //100
	
	}else if(q3>800 && q2<800 && q1<800 )
	{
		LCDWriteFStringXY(16,1,PSTR("Qty 500mg"));  //101
		
	}else if(q3>800 && q2<800 && q1>800 )
	{
		LCDWriteFStringXY(16,1,PSTR("Qty 150mg")); //110
		
	}else if(q3>800 && q2>800 && q1<800 )
	{
		LCDWriteFStringXY(16,1,PSTR("Qty 250mg"));  //111
		
	}else
	{
 		LCDWriteFStringXY(16,1,PSTR("            "));
	}



	}
	else
	{
		LCDWriteFStringXY(16,0,PSTR("                    "));   //0
		LCDWriteFStringXY(16,1,PSTR("                    "));   //0
	}

		

	

	
	}
	}



