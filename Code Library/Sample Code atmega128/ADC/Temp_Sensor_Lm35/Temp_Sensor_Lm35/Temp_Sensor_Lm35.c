/*-----------------------------------------------------------------------------
 Program to demonstrate single channel ADC, 10bit(0-1023) adc value is displayed on lcd
  -----------------------------------------------------------------------------
  note:
  1.Refer lcd.c(lcd_4_bit.c/lcd_8_bit.c) file for Pin connections
  2.Refer Atmega32 datasheet for register description.
------------------------------------------------------------------------------*/
 

#include "lcd.h"	//User defined LCD library which conatins the lcd routines
#include "adc.h"   //User defined library which conatins the adc routines


/* start the main program */
void main() 
{
   unsigned int adc_result,adc_temp,temp_val;
    
  /* Initialize the lcd before displaying any thing on the lcd */
    LCD_Init(4,2,16);

  /* Initialize the adc before starting the conversion */
    //ADC_Init();
   ADC_Init();
   LCD_Clear();

   /* Display the adc channel zero value continuously */ 
   while(1)
    {     
	    	 
		     temp_val = ADC_GetAdcValue(0);
			 temp_val = temp_val/2;  
			 
			 
		    // pot = ADC_GetAdcValue(1);
		    // light = ADC_GetAdcValue(2);
			
		     LCD_Printf("Temprature:%d",temp_val);
		     LCD_GoToLine(1);
			 	     
	     
      }


  }