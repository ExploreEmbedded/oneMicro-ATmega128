/*
 * PIR sensor with Atmega128.c
 *
 * Created: 15-Apr-16 3:26:31 PM
 * Author : exploreembedded
 */ 

#include <avr/io.h>
#include "lcd.h"

#define PIR_sensor PA0

unsigned int PIR_Status = 0;
int main()
{
	
	DDRA = (0 << PIR_sensor);           // Configure PORTA as INput to connect switches
	/*Connect RS->PB0, RW->PB1, EN->PB2 and data bus to PORTC.4 to PORTC.7*/
	while(1)
	{
		while(((PINA) & (1<<PIR_sensor)) == 1)
		{
			LCD_SetUp(PB_0,PB_1,PB_2,P_NC,P_NC,P_NC,P_NC,PC_4,PC_5,PC_6,PC_7);
			LCD_Init(2,16);
			LCD_DisplayString("Motion Detected!");
			
		}
		 LCD_Clear();
		 
		while(((PINA) & (1<<PIR_sensor)) == 0) 
		{
		 LCD_SetUp(PB_0,PB_1,PB_2,P_NC,P_NC,P_NC,P_NC,PC_4,PC_5,PC_6,PC_7);
		 LCD_Init(2,16);		
		 LCD_DisplayString("Motion Ended!");
		}
		 LCD_Clear();	
	
		
				
	}
	
	return (0);
}
