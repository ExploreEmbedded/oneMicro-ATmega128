

#include <avr/io.h>
#include "lcd.h"
#include "stdutils.h"
#include "delay.h"
#include "keypad.h"
#include "rtc.h"
#include "eeprom.h"
#include "adc.h"
#include "uart.h"

void testKeyPad(void);
uint8_t DisplayMenu(void);
void blinky();
void testDipSwitches();
void RTCTest();
void EEPROMTest();
void ADCTest();
void UARTTest();
void microSdTest();
void OLEDTest();
//connect display to PORTD check LCD.h for connections
//connect keypad to PORTB, R1->PB7 ..... C4->PB0

#define SegmentValue PORTA //PORT2.0 is connected to segment 'a'
#define SegmentSlection PORTC //PORT0.0 is selection line 'S1'

#define SegOne   0x01
#define SegTwo   0x02
#define SegThree 0x04
#define SegFour  0x08

unsigned char TestMenu[11][20]={
								"Blink",// led, relay, buzzer, 
								"Switches",
								"7-segment",
								"RTC",
								"EEPROM",
								"ADC",
								"SerialComm",
								"Graphics128x64",
								"MicroSD",   //trip pot, ldr, lm35
								"L293D",
								"OLED",	
							   };

int main(void)
{
	char key;
	uint8_t option;
	LCD_Init(4,2,16);
	KEYPAD_Init();
	//UART_Init(9600);
	
    while(1)
    {
		
		LCD_Printf("Ultra AVR test!");
		do 
		{
	    	//LCD_ScrollMessage(2, "Ultra AVR Test. . .Navigation C:Left  D:Right E:Enter F:Cancel");
		} while(KEYPAD_GetKey()!='E');

		
		LCD_Clear();
		option = DisplayMenu();
		switch(option)
		{
		   case 0: blinky(); break;
		   case 1: testDipSwitches(); break;
		   case 2: seg_test(); break;
		   case 3: RTCTest(); break;
		   case 4: EEPROMTest(); break;
		   case 5: ADCTest(); break;
		  // case 6: UARTTest();
		   case 7: OLEDTest();
		   case 8: microSdTest();
		   default: break;	
		}	
		while(1);	
    }
}


uint8_t DisplayMenu(){
	int8_t keyCount = 0;
	unsigned char key;
    //LCD_GoToLine(1);
	//LCD_Clear();
	LCD_Printf("<%s>\n",TestMenu[keyCount]);
	do{
	 key = KEYPAD_GetKey();
	 if(key == 'D')
	 {
		 keyCount++;
	 }
	 else if(key == 'C')
	  {
		  keyCount--;
		  keyCount = keyCount + 10;
	  }
	  
	 if((keyCount <= 0)||(keyCount>10))
	 {
		  keyCount = 0;
	 }	  
	  LCD_GoToLine(2);
	  LCD_Clear();
	  LCD_Printf("<%s>\n",TestMenu[keyCount]);
	  
	}while(key != 'E');
	
	return keyCount;
}

void blinky()
{
	LCD_Printf("Connect LEDs to PORTA or PORTC. Reset the board after test!");
	DDRC = DDRA = 0XFF;
	while(1){
		PORTC= PORTA = 0XFF;
		_delay_ms(100);
		PORTC= PORTA = 0X00;
		_delay_ms(100);
	}
}
void testKeyPad(){
	
}

void testDipSwitches()
{
	LCD_ScrollMessage(2,"Simple connect DIP Switch directly to LEDs");
}


void seg_test()
{
	DDRC = DDRA = 0XFF;
	LCD_Clear();
	LCD_Printf("PA:Databus, PC0:S1---PC3:S4");
	while(KEYPAD_GetKey()!='E');
	unsigned char seg_code[]={0xC0,0xF9,0xA4,0xB0};
			while(1)
			{
				SegmentSlection=SegOne;
				SegmentValue = seg_code[0];
				DELAY_us(10);
				SegmentSlection=SegTwo;
				SegmentValue = seg_code[1];
				DELAY_us(10);
				SegmentSlection=SegThree;
				SegmentValue = seg_code[2];
				DELAY_us(10);
				SegmentSlection=SegFour;
				SegmentValue = seg_code[3];
				DELAY_us(10);
			}
}

void RTCTest()
{
	
	 LCD_GoToLine(1);
	 LCD_Printf("PC0->SCL PC1->SDA and hit enter");
	 while(KEYPAD_GetKey()!='E');
	 unsigned char sec,min,hour,day,month,year;

	 RTC_Init();

	 RTC_SetTime(0x10,0x40,0x20);  //  10:40:20 am
	 RTC_SetDate(0x14,0x11,0x12);  //  14th Nov 2012


	 LCD_Clear();
	 while(1)
	 {
		 /* Read the Time from RTC(RTC) */
		   RTC_GetTime(&hour,&min,&sec);
 
		 /* Read the Date from RTC(RTC) */
		 
		 RTC_GetDate(&day,&month,&year);
		 LCD_GoToLine(1);
		 LCD_Printf("Time:%d:%d:%d",hour,min,sec);
		 LCD_GoToLine(2);
		 LCD_Printf("Date:%d:%d:%d",day,month,year);


	 }
	
}

void EEPROMTest(){
	
	 unsigned int eeprom_address=0x00;
     unsigned char write_String[] = {"Explore"}, read_string[15];

 
 while(1)
 {
	 LCD_GoToLine(1);
	 LCD_Printf("Write:%s",write_String);  //Display the String to be written
	 EEPROM_WriteString(eeprom_address,write_String); // Write the String at memory Location	0x00
     LCD_GoToLine(2);
	 EEPROM_ReadString(eeprom_address,read_string);	// Read the String from memory Location 0x00
	 LCD_Printf("Read:%s",read_string);			        //Display the read String

 }
}

void ADCTest(){
	 uint16_t temp, light, pot;
	 LCD_GoToLine(1);
	 LCD_Printf("Temp->PA0 Pot->PA1 light->PA2");
	 while(KEYPAD_GetKey()!='E');
	 ADC_Init();
	 LCD_Clear();
	 while(1)
	 {
		 temp = ADC_GetAdcValue(0);
		 pot = ADC_GetAdcValue(1); 
		 light = ADC_GetAdcValue(2);	 
		 LCD_Printf("T:%d  P:%d\nL:%d",temp,pot,light);
		 LCD_GoToLine(1);
	 }
	
	 
}

UARTTest(){
	
	UART_Init(9600);
	while(1)
	{
		UART_TxString("Welcome to ExploreEmbedded \r\n");		
	}
}

void microSdTest(){
	
	
}

void OLEDTest(){
	
	
}