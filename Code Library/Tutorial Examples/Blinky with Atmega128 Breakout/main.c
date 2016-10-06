/*
 * Blinky with Atmega128 Breakout.c
 *
 * Created: 04-Apr-16 4:09:09 PM
 * Author : exploreembedded
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define LED 0

int main()
{
	DDRB = (1<<LED);           // Configure PORTB0 as output

	while(1)
	{
		PORTB = (1<<LED);        // Turn ON Led connected to PORTB0
		_delay_ms(5000);      // Wait for some time
		PORTB = (0<<LED);        // Turn OFF Led connected to PORTB0
		_delay_ms(5000);      // Wait for some time
	}
	return 0;
}