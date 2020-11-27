/*
 * reader.c
 *
 * Created: 09-Feb-20 10:25:03 AM
 * Author : Chandeepa
 */ 





#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>




#include "lcd.h"

void InitADC()
{
	ADMUX=(1<<REFS0);									// For Aref=AVcc;
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);	//  div factor =128
}

int ReadADC0( int ch0) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch0=ch0&0b00000000;
	ADMUX&=0b11100000;
	ADMUX|=ch0;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}
int ReadADC1( int ch1) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch1=ch1&0b00000001;
	ADMUX&=0b11100000;
	ADMUX|=ch1;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

int ReadADC2(int ch2) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch2=ch2&0b00000010;
	ADMUX&=0b11100000;
	ADMUX|=ch2;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

int ReadADC3( int ch3) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch3=ch3&0b00000011;
	ADMUX&=0b11100000;
	ADMUX|=ch3;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

int ReadADC4( int ch4) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch4=ch4&0b00000100;
	ADMUX&=0b11100000;
	ADMUX|=ch4;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

int ReadADC5( int ch5) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch5=ch5&0b00000101;
	ADMUX&=0b11100000;
	ADMUX|=ch5;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

int ReadADC6( int ch6) // uint8_t
{
	//Select ADC Channel ch must be 0-7
	ch6=ch6&0b00000110;
	ADMUX&=0b11100000;
	ADMUX|=ch6;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));


	ADCSRA|=(1<<ADIF);

	return(ADC);
}

int ReadADC7( int ch7) // uint8_t
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
//	LCDInit(LS_NONE);
//	LCDClear();
	LCD_Init();
	
	//Initialize ADC
	InitADC();

	//LCDClear();
	LCD_Clear();
//LCDWriteFStringXY(0,1,PSTR("*  Enter your  *"));
 LCD_String_xy( 0,0 ,"*  Enter your  *");
 LCD_String_xy( 1,0 ,"**    Card    **");

	_delay_ms(500);
	LCD_Clear();


	
	
LCD_String_xy( 0,0 ,"**   Prescription   **");
	
while(1){
	int x1 = ReadADC0(1) ;
	int x2 = ReadADC1(2);
	int x3 = ReadADC2(3);
	int x4 = ReadADC3(4);
	int q1 = ReadADC4(5);
	int q2 = ReadADC5(6);
	int q3 = ReadADC6(7);
	int d =  ReadADC7(0);  //d is considered as the start bit

if(d>800)
{
	
//*****************getting the Correct medicine************************
	if(x4<800 && x3<800 && x2<800 && x1<800)  //0000
	{
		 LCD_String_xy( 1,0 ,"             ");
	}
	else if(x4<800 && x3<800 && x2<800 && x1>800) //0001
	{
			LCD_String_xy( 1,0, " Panadol ");
		
	}else if(x4<800 && x3<800 && x2>800 && x1<800) //0010
	{
		LCD_String_xy( 1,0 ," Nizoral ");
 
		
	}else if(x4<800 && x3<800 && x2>800 && x1>800)    //0011
	{
		LCD_String_xy( 1,0 ," Amoxicillin ");
		      	
	}else if(x4<800 && x3>800 && x2<800 && x1<800)     //0100
	{
		LCD_String_xy( 1,0 ," Cetirizine ");
		   
	}else if(x4<800 && x3>800 && x2<800 && x1>800)   //0101
	{
		LCD_String_xy( 1,0 ," Thyroxine ");
	 
	}else if(x4<800 && x3>800 && x2>800 && x1<800)  //0110
	{
		LCD_String_xy( 1,0 ," Losartan "); 
		
	}else if(x4<800 && x3>800 && x2>800 && x1>800)   //0111
	{
		LCD_String_xy( 1,0 ," Atorvastatin ");  
		
	}else if(x4>800 && x3<800 && x2<800 && x1<800)    //1000
	{
		LCD_String_xy( 1,0 ," Piriton "); 
		
	}else if(x4>800 && x3<800 && x2<800 && x1>800)   //1001
	{
		LCD_String_xy( 1,0 ," Vitamin C ");  
		
	}else if(x4>800 && x3<800 && x2>800 && x1<800)  //1010
	{
		LCD_String_xy( 1,0 ," Zincovit  ");   
	  
	}else if(x4>800 && x3<800 && x2>800 && x1>800)   //1011
	{
		LCD_String_xy( 1,0 ," Digene  ");  
		 
	}else if(x4>800 && x3>800 && x2<800 && x1<800)   //1100
	{
		LCD_String_xy( 1,0 ," Gaviscon  ");    
		
	}else if(x4>800 && x3>800 && x2<800 && x1>800)   //1101
	{
		LCD_String_xy( 1,0 ," Imodium   ");    
	  
	}else if(x4>800 && x3>800 && x2>800 && x1<800)   //1110
	{
		LCD_String_xy( 1,0 ," Mefenamic Acid  ");   

	}else
	{
		LCD_String_xy( 1,0 ,"   ");      //1111

		
		
		
	}
//*****************Getting the quantity************************************

	if(q3<800 && q2<800 && q1<800 )   //000
	{
		LCD_String_xy( 16,0 ,"   ");  

	}
	else if(q3<800 && q2<800 && q1>800 )   //001
	{
		LCD_String_xy( 16,0 ," Qty   5mg  ");  
	
	}else if(q3<800 && q2>800 && q1<800 )   //010  Qty 100mg
	{
		LCD_String_xy( 16,0 ," Qty   100mg  "); 
		
	}else if(q3<800 && q2>800 && q1>800 )
	{
		LCD_String_xy( 16,0 ," Qty   200mg  ");  //011 Qty 200mg
	
	}else if(q3>800 && q2<800 && q1<800 )
	{
		LCD_String_xy( 16,0 ," Qty   500mg  ");  //100  Qty 500mg
		
	}else if(q3>800 && q2<800 && q1>800 )
	{
		LCD_String_xy( 16,0 ," Qty   150mg  "); //101  Qty 150mg
		
	}else if(q3>800 && q2>800 && q1<800 )
	{
		LCD_String_xy( 16,0 ," Qty   250mg  ");;  //110  Qty 250mg
		
	}else
	{
 		LCDWriteFStringXY(16,1,PSTR("            "));
	}



	}

		

	

	
	}
	}




