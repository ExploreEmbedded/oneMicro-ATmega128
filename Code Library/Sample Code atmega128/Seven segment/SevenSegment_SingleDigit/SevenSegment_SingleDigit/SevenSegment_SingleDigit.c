/*-----------------------------------------------------------------------------
   Program to demonstrate Hex counter on signle SevenSegment(CommonAnode) display
  -----------------------------------------------------------------------------
  note:
Code is for CommonAnode type of segment, 
seg_code[] must be complemented for CommonCathode
------------------------------------------------------------------------------*/

																	
/* htc.h contains the definition of all ports and SFRs */
#include <avr\io.h>

#include "delay.h"	//User defined delay library which contains the delay routines

#define SegmentValue PORTB
#define SegmentSlection PORTC

#define SegOne   0x01
#define SegTwo   0x02
#define SegThree 0x04
#define SegFour  0x08

/* start the main program */
void main() 
{
   unsigned char seg_code[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
   unsigned char cnt=0;

 /* Configure the ports as output */
  DDRB = C_PortOutput_U8;
  DDRC = C_PortOutput_U8;
 
   while(1)
    {
	   
	    for(cnt=0x00;cnt<=0x0f;cnt++)	 // loop to display 0-F
		 {
		   	SegmentSlection = SegOne;	 // Select the segment			
			SegmentValue= seg_code[cnt];	 // Send the segment_code of number to be displayed
			DELAY_us(1000000);
		
		   }

	  }												  

  }										