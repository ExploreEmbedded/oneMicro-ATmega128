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
#include "lcd.h"
//lcd port  is configured in lcd.h


int main(void)
{
	LCD_Init(4,2,16); // 4 bit mode, 2 lines, 16 characters
	LCD_Printf("ExploreEmbedded\nLet's build. . .");
	
	while(1);
}