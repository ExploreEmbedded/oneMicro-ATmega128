
#include <avr/io.h>
#include "stdutils.h"
#include "delay.h"



#define SegmentValue PORTA //PORTA0 is connected to segment 'a'
#define SegmentSlection PORTC //PORTC0 is selection line 'S1'

#define SegOne   0x01
#define SegTwo   0x02
#define SegThree 0x04
#define SegFour  0x08

unsigned char seg_code[]={0xC0,0xF9,0xA4,0xB0};

int main(void)
{
	char key;
	uint8_t option;
	DDRA = DDRC = 0XFF; //Set the ports as output
	
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