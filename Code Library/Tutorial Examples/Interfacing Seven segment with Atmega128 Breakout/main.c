/*
 * Interfacing Seven segment with Atmega128 Breakout.c
 *
 * Created: 06-Apr-16 2:32:54 PM
 * Author : exploreembedded
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define Segment   PD0


int main() {
	char seg_code[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	int cnt;

	/* Configure the ports as output */
	DDRB = 0xff;               // Data 
	//DDRD |= (1 << Segment );               // Control signal PORTD0
	DDRD = (1 << Segment);

	while (1)
	{
		
		for (cnt = 0x00; cnt < 0x0f; cnt++)   // loop to display 0-F
		{
			
			PORTD = ( 1<< Segment);
			PORTB = seg_code[cnt];
			_delay_ms(1000);
			
		}
	}
}

