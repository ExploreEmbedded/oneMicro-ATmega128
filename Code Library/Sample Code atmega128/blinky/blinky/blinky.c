/*
 * blinky.c
 * 
 * Created: 8/14/2015 9:29:24 AM
 * Author: sandeep, reach me at sandeep@exploreembedded.com
 * www.exploreembedded.com
 * This example demonstrates blinking LEDs connected to all ports of atmega128
 *
 *  IMPORTANT NOTE:
 * Atmega128 is a wierd MCU. Read the tutorial below to understand how to set it up properly at
 * http://exploreembedded.com/wiki/Setting_up_ATmega128
 *
 * If you're using Explore Atmega128 breakout board, you need not setup anything. We have done all of it for you.
 * Or if you're planning to buy a board, do check out our nice little board.
 * https://www.exploreembedded.com/product/Explore%20ATMEGA128%20Breakout
 */ 


#include <avr/io.h>
#include "delay.h" //EE delay library

int main(void)
{
	//let's set all ports as output
	
	DDRA = DDRB =DDRC =DDRD = DDRD =DDRE = DDRF = 0xFF;
    while(1)
    {
		//here goes the blinky
	   PORTA =  PORTB = PORTC = PORTD = PORTE= PORTF = 0xFF; //turn them  all on!
	   DELAY_ms(100);
	   PORTA =  PORTB = PORTC = PORTD = PORTE= PORTF = 0x00; //turn them  all OFF!
       DELAY_ms(100); 
    }
}