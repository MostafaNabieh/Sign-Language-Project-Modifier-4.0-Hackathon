/*
 * sign_language.c
 *
 * Created: 3/23/2020 10:57:59 PM
 *  Author: abdul
 */ 


#include <avr/io.h>
#include "lcd.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "adc.h"
#include "std_macros.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include "USART.h"

int main(void)
{
	LCD_vInit();
	ADC_vinit();
	UART_vInit(9600);
	_delay_ms(300);
	

	

unsigned  int x ,y,z,a,b,c,d,e ;

 // char arr[11] = "0123456789" ;
	
    while(1)
    {
		
		ww:
	
		
  a=ADC_u16Read(0) ;
  b=ADC_u16Read(1) ;
 c=ADC_u16Read(2) ;
 d=ADC_u16Read(3) ;	
 e=ADC_u16Read(4) ;
 x =ADC_u16Read(5);
 y = ADC_u16Read(6);
 z=ADC_u16Read(7);
 _delay_ms(50);

if((a<350)&&(d > 415)&&(y<286)&&(e> 415)&&(b<350)&&(c<350))
{
	
	LCD_vSend_string("w");
	LCD_movecursor(1,1);
	UART_vSendstring('w') ;
	goto ww;
}

 
 
	
if((a<350)&&(y<296)&&(b<350)&&(c<350)&&(d>415)&&(350<e<390))
{
	
   LCD_vSend_string("B");
	LCD_movecursor(1,1);
     UART_vSendstring("B") ;
    goto ww;
 }		
	
if((a<350)&&(y<296)&&(c>410)&&(b<350)&&(d>410))
{
	
	LCD_vSend_string("c");
	LCD_movecursor(1,1);
	UART_vSendstring("c") ;
   goto ww;

}	
if((a<350)&&(y<296)&&(d>410)&&(b>410)&&(c>410))
	{
		
		LCD_vSend_string("d");
		LCD_movecursor(1,1);
		UART_vSendstring("d") ;
		goto ww;


	}
	if((a<350)&&(x>368)&&(b<350)&&(c<350)&&(d<350))
	{
		LCD_vSend_string("a" );
		LCD_movecursor(1,1);
		UART_vSendstring("b");
		goto ww;
	}
	
if((360<a<397)&&(270<z<307)&&(e<372)&&(360<b<397)&&(360<c<397)&&(360<d<397))
	{
		
		LCD_vSend_string("e");
		LCD_movecursor(1,1);
		UART_vSendstring("e") ;
		goto ww;


	}
	if((390<e)&&(399<a<410)&&(z<307)&&(399<b<410)&&(399<c<410)&&(399<d<410))
	{
		
		LCD_vSend_string("g");
		LCD_movecursor(1,1);
		UART_vSendstring("g") ;
		goto ww;


	}
	
	if((360<e<385)&&(399<a<410)&&(z<307)&&(399<b<410)&&(399<c<410)&&(399<d<410))
	{
		
		LCD_vSend_string("f");
		LCD_movecursor(1,1);
		UART_vSendstring("f") ;
		goto ww;


	}
		
		if((a<350)&&(z<307)&&(d>410)&&(e>410)&&(b<350)&&(c<350))
		{
			
			LCD_vSend_string("h");
			LCD_movecursor(1,1);
			UART_vSendstring("h") ;
             goto ww;

		}
	
	if((a<370)&&(z<307)&&(d>405)&&(373<c<410)&&(b<370)&&(e>405))
	{
		
		LCD_vSend_string("i");
		LCD_movecursor(1,1);
		UART_vSendstring("i") ;
         goto ww;

	}
	if( (c<350) && (280<y<307) &&(380<d<410)&& (a<350) && (b<350))
	{
		
		LCD_vSend_string("j");
		LCD_movecursor(1,1);
		UART_vSendstring("j") ;
         goto ww;

	}
	if((a<350)&&(280<y<307)&&(350<c<420)&&(380<d<420)&&(b<350))
	{
		
		LCD_vSend_string("k");
		LCD_movecursor(1,1);
		UART_vSendstring("k") ;
		goto ww;


	}
	if((a>410)&&(y<280)&&(b>410)&&(c>410)&&(d>410)&&(e>410))
	{
		
		LCD_vSend_string("l");
		LCD_movecursor(1,1);
		UART_vSendstring("l") ;
        goto ww;

	}
	if((a>410)&&(280<y<327)&&(b>410)&&(c>410)&&(d>410)&&(e>410))
	{
		
		LCD_vSend_string("m");
		LCD_movecursor(1,1);
		UART_vSendstring("m") ;
        goto ww;

	}
	if((a<350)&&(y>388)&&(e<370)&&(b<350)&&(c<350)&&(d<350))
	{
		
		LCD_vSend_string("n");
		LCD_movecursor(1,1);
		UART_vSendstring("n") ;
          goto ww;

	}
	if((a<350)&&(y>388)&&(e>407)&&(b<350)&&(c<350)&&(d<350))
	{
		
		LCD_vSend_string("o");
		LCD_movecursor(1,1);
		UART_vSendstring("o") ;
          goto ww;

}
  if((b<365)&&(y<292)&&(e<400)&&(a<365)&&(c<400))
  {
	
	LCD_vSend_string("p");
	LCD_movecursor(1,1);
	UART_vSendstring("p") ;
    goto ww;

}
	if((b<360)&&(y<292)&&(390<c)&&(e>400)&&(a<360))
	{
		
		LCD_vSend_string("q");
		LCD_movecursor(1,1);
		UART_vSendstring("q") ;
        goto ww;

	}
	if((b<370)&&(x>389)&&(c>400)&&(d>400)&&(a<370))
	{
		
		LCD_vSend_string("r");
		LCD_movecursor(1,1);
		UART_vSendstring("r") ;
		goto ww;


	}
	if((a<370)&&(x>389)&&(c>400)&&(b<370)&&(d>400)&&(e>400))
	{
		
		LCD_vSend_string("s");
		LCD_movecursor(1,1);
		UART_vSendstring("s") ;
         goto ww;

	}
	if((a<370)&&(380<e<420)&&(b<370)&&(c<370)&&(380<d<420))
	{
		
		LCD_vSend_string("t");
		LCD_movecursor(1,1);
		UART_vSendstring("t") ;

          goto ww;
	}
	if((a<370)&&(380<c)&&(380<e)&&(380<d)&&(b<370))
	{
		
		LCD_vSend_string("u");
		LCD_movecursor(1,1);
		UART_vSendstring("u") ;
		goto ww;
	}
	if((a>415)&&(e<400)&&(y<286)&&(b>415)&&(c>415)&&(d>415))
	{
		
		LCD_vSend_string("v");
		LCD_movecursor(1,1);
		UART_vSendstring("v") ;
		goto ww;
}

if((b<360)&&(e < 380)&&(a>404)&&(c<360)&&(d<360))
{
	
	LCD_vSend_string("x");
	LCD_movecursor(1,1);
	UART_vSendstring("x") ;
	goto ww;
}
if((b<360)&&(348<z<406)&&(y<348)&&(a<360)&&(c<360))
{
	
	LCD_vSend_string("y");
	LCD_movecursor(1,1);
	UART_vSendstring("y") ;
	goto ww;
}
if((377<a<409)&&(z<306)&&(377<b<409)&&(377<c<409)&&(377<d<409)&&(377<e<409))
{
	
	LCD_vSend_string("z");
	LCD_movecursor(1,1);
	UART_vSendstring("z") ;
	goto ww;
}
if((b<360)&&(375<e<400)&&(a>415)&&(y<307)&&(c<360)&&(d>415))
{
	
	LCD_vSend_string("Ac");
	LCD_movecursor(1,1);
	UART_vSendstring("Ac") ;
	goto ww;
}

if((a<350)&&(d>410)&&(x<307)&&(b<350)&&(c<350))
{
	
	LCD_vSend_string("0");
	LCD_movecursor(1,1);
	UART_vSendstring("0") ;
	goto ww;
}
if((a<360)&&(e>409)&&(z>368)&&(b<360)&&(c<360)&&(d<360))
{
	
	LCD_vSend_string("AA");
	LCD_movecursor(1,1);
	UART_vSendstring("AA") ;
	goto ww;
}
if((b<360)&&(a>409)&&(c<360)&&(d<360)&&(e>409))
{
	
	LCD_vSend_string("AB");
	LCD_movecursor(1,1);
	UART_vSendstring("AB") ;
	goto ww;
}
	}
	return 0 ;

}	
	

	
	