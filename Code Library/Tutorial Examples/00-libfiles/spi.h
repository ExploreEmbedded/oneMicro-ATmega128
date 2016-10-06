/***************************************************************************************************
                                   ExploreEmbedded  
 ****************************************************************************************************
 * File:   spi.h
 * Version: 16.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: File contains the function prototypes and SFR bits location for SPI communication

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

#ifndef _SPI_H_
#define _SPI_H_

#include "stdutils.h"
#include "gpio.h"


/****************************************************************************************************
                            SPI pin numbers and pin functions
 ****************************************************************************************************/
#define MOSI_PIN    PB_2
#define MISO_PIN    PB_3
#define SCK_PIN     PB_1
#define SSEL_PIN    PB_0
/***************************************************************************************************/










/****************************************************************************************************
                            SPI function prototypes and Macros
 ****************************************************************************************************/
void SPI_Init(void);
uint8_t SPI_Write (uint8_t spiData_u8);
uint8_t SPI_Read(void);


#define SPI_EnableChipSelect()   GPIO_PinWrite(SSEL_PIN,LOW)
#define SPI_DisableChipSelect()  GPIO_PinWrite(SSEL_PIN,HIGH)
/***************************************************************************************************/


#endif



