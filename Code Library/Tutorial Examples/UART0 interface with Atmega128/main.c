/*
 * UART0 interface with Atmega128.c
 *
 * Created: 20-Apr-16 3:50:57 PM
 * Author : exploreembedded
 */ 

#include <avr/io.h>

#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init( unsigned int ubrr );
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );



int main( void )
{
	unsigned char str[18] = "\n\rExplore Embedded";
	unsigned char strLenght = 18;
	unsigned char i = 0;
	
	USART_Init ( MYUBRR );
	//USART_Transmit('S' );	
	while(1)
	{
		USART_Transmit( str[i++] );
		if(i >= strLenght)
		i = 0;
		
	}
	return(0); 
	
	
	
}
void USART_Init( unsigned int ubrr )
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}




	
	 