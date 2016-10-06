/*
 * UART programming with Atmega128.c
 *
 * Created: 18-Apr-16 4:10:59 PM
 * Author : exploreembedded
 */ 

#include "uart.h"


int main()
{


	UART_Init(0,9600);   // Initilaize All the UARTs at 9600 Baud rate
	UART1_Init(9600);   // Both UART_Init(0,9600) and UART0_Init(9600) are same
	// Internally UART0_Init() is mapped to UART_Init()
	// You can notice First two(0,1) are called with parameter other two(2,3) with suffix

	/*Directly use the Channel suffixed interface UART0_Printf, where suffix "0" specifies the UART channel*/
	UART0_Printf("Channel Zero %4d,  %2x\n\r", 1234, 0xabcd);
	UART1_Printf("Channel One %4d,   %2x\n\r", 5678, 0xef);



	/*Use the standard interface by passing the channel number as first paramater*/
	UART_Printf(0,"Channel Zero %4d,  %2x\n\r", 1234, 0xabcd);
	UART_Printf(1,"Channel One %4d,   %2x\n\r", 5678, 0xef);

	while(1);
}

