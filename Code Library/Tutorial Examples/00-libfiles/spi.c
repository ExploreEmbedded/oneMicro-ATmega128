/***************************************************************************************************
                                   ExploreEmbedded    
 ****************************************************************************************************
 * File:   spi.h
 * Version: 16.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: File contains the functions to read and write data from SPI

The libraries have been tested on ExploreEmbedded development boards. We strongly believe that the 
library works on any of development boards for respective controllers. However, ExploreEmbedded 
disclaims any kind of hardware failure resulting out of usage of libraries, directly or indirectly.
Files may be subject to change without prior notice. The revision history contains the information 
related to updates. 


GNU GENERAL PUBLIC LICENSE: 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 

Errors and omissions should be reported to codelibraries@exploreembedded.com
 **************************************************************************************************/
#include <avr/io.h>
#include "spi.h"
#include "gpio.h"



uint8_t dummy_u8;




/***************************************************************************************************
                           void SPI_Init(void)
 ****************************************************************************************************
 * I/P Arguments : none

 * Return value  : none

 * description :This function initializes the SPI module of LPC1768.
                 MOSI -- P0.18
                 MISO -- P0.17
                 SCK  -- P0.15
                 SSEL -- P0.16               
 ****************************************************************************************************/
void SPI_Init(void)
{    

    GPIO_PinDirection(SCK_PIN,OUTPUT);        /* Configure SCK,MOSI,SSEl as Output and MISO as Input */ 
    GPIO_PinDirection(MOSI_PIN,OUTPUT);
    GPIO_PinDirection(MISO_PIN,INPUT);
    GPIO_PinDirection(SSEL_PIN,OUTPUT);

    SPI_DisableChipSelect();                  /* Disable the Slave Select */

    SPCR = 0x53; //setup SPI: Master mode, MSB first, SCK phase low, SCK idle low
    SPSR = 0x00;

 
}





/***************************************************************************************************
                          uint8_t SPI_Write (uint8_t spiData_u8)
 ****************************************************************************************************
 * I/P Arguments : 
                 uint8_t : Byte of data to be send on SPI.

 * Return value  : 
                 uint8_t : Returns back the data send on SPI, this is used in case of SD card.

 * description :
                 This function is used to send a byte of data through SPI.              
 ****************************************************************************************************/
uint8_t SPI_Write (uint8_t spiData_u8)
{

    SPDR = spiData_u8;

    // Wait for transmission complete
    while(!(SPSR & (1<<SPIF)));
    dummy_u8 = SPDR;

    return spiData_u8;
}






/***************************************************************************************************
                          uint8_t SPI_Read(void)
 ****************************************************************************************************
 * I/P Arguments : none

 * Return value  : 
                  uint8_t : Returns back a byte of data read from SPI.

 * description :
                 This function is used to read a byte of data from SPI.              
 ****************************************************************************************************/
uint8_t SPI_Read(void)
{
    uint8_t spiData_u8;

    SPDR = 0xff;
    while(!(SPSR & (1<<SPIF)));
    spiData_u8 = SPDR;

    return spiData_u8;
}

