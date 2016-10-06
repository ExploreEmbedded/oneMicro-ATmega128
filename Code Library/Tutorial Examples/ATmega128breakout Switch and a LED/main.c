/*
 * ATmega128breakout Switch and a LED.c
 *
 * Created: 05-Apr-16 1:32:33 PM
 * Author : exploreembedded
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define LED PB0
#define SWITCH PC0

int main()
{
	
	
	DDRB = (1 << LED);           // Configure PORTC as output to connect Leds
	DDRC = (0 << SWITCH);           // Configure PORTA as INput to connect switches
	PORTC = (1 << SWITCH);          // Enable The PullUps of PORTA.
	
	while(1)
	{
		
		
		while(((PINC) & (1<<SWITCH)) == 1)
		{
			PORTB |= (1<<LED);
		}
		PORTB &= ~(1<<LED);
	}
	
	return 0;
}
