/*
 * adc.c
 *
 * Created: 3/23/2020 10:59:15 PM
 *  Author: abdul
 */ 
#include <avr/io.h>
#include "std_macros.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
 void ADC_vinit(void)
{
	SET_BIT(ADMUX,REFS0);
 //configure VREF
	SET_BIT(ADCSRA,ADEN); // enable ADC
	/* adjust ADC clock*/
	SET_BIT(ADCSRA,ADPS2);
     SET_BIT(ADCSRA,ADPS1);
}

unsigned short ADC_u16Read(char pin )
{
	unsigned short read_val ;
	
 if(pin == 0){
	  ADMUX&=(~(1<<(pin))) ;
	  ADMUX&=(~(1<<1));
  ADMUX&=(~(1<<2));
   ADMUX&=(~(1<<3));}
   
if(pin ==1){ ADMUX|=(1<<(pin-1));
	   ADMUX&=(~(1<<1));
	   ADMUX&=(~(1<<2));
	   ADMUX&=(~(1<<3));
  }	   
  
if(pin == 2){	ADMUX&=(~(1<<(pin-2))) ;
	ADMUX|=(1<<(pin-1));
	
	
	 ADMUX&=(~(1<<2));
	 
}
	
if(pin ==3){ ADMUX|=(1<<(pin-3)); 
	ADMUX|=(1<<(pin-2));
	ADMUX&=(~(1<<(pin-1))) ;
	 }
		
if(pin ==4){ ADMUX|=(1<<(pin-2));
			ADMUX&=(~(1<<(pin-3))) ;
			ADMUX&=(~(1<<(pin-4))) ;
			
		}
if(pin ==5){ ADMUX|=(1<<2);
			ADMUX|=(1<<0);
		ADMUX&=(~(1<<1)) ;
		
	}
if(pin ==6){ ADMUX|=(1<<(pin-4));
	ADMUX|=(1<<(pin-5));
	ADMUX&=(~(1<<(pin-6))) ;
}
if(pin ==7){ ADMUX|=(1<<(pin-5));
ADMUX|=(1<<(pin-6));
ADMUX|=(1<<(pin-7));
}
				
	
	SET_BIT(ADCSRA,ADSC);

	while(IS_BIT_CLR(ADCSRA,ADIF));//stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); // clear ADIF
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
	
	
}