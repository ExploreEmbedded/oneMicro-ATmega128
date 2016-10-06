/*
 * SD card interface.c
 *
 * Created: 18-Apr-16 6:47:33 PM
 * Author : exploreembedded
 */ 

#include <avr/io.h>
#include "sdcard.h"
#include "uart.h"
#include "fat32.h"
#include "stdutils.h"
#include "delay.h"
#include "spi.h"


#define FILE_READ         '1'
#define FILE_WRITE        '2'
#define FILE_COPY         '3'
#define FILE_DELETE       '4'
#define FILE_LIST         '5'
#define MEMORY_STATICS    '6'



int main()
{
	uint8_t returnStatus,sdcardType,option;
	char ch,sourceFileName[12],destFileName[12];
	fileConfig_st *srcFilePtr,*destFilePtr;
	fileInfo fileList;
	uint32_t totalMemory,freeMemory;

	UART0_Init(115200);
	returnStatus = SD_Init(&sdcardType);

	if(returnStatus)
	{
		if(returnStatus == SDCARD_NOT_DETECTED)
		{
			UART0_TxString("\n\r SD card not detected..");
		}
		else if(returnStatus == SDCARD_INIT_FAILED)
		{
			UART0_TxString("\n\r Card Initialization failed..");
		}
		else if(returnStatus == SDCARD_FAT_INVALID)
		{
			UART0_TxString("\n\r Invalid Fat filesystem");
		}
		while(1);
	}
	else
	{
		UART0_TxString("\n\rSD Card Detected!");
	}


	while(1)
	{
		UART0_TxString("\n\r\n\rPress any key to continue");
		UART0_RxChar();
		UART0_TxString("\n\r\n\r------File options---------\n\r");
		UART0_TxString("1: Read File \n\r");
		UART0_TxString("2: Write File \n\r");
		UART0_TxString("3: File Copy \n\r");
		UART0_TxString("4: Delete File \n\r");
		UART0_TxString("5: Get File List \n\r");
		UART0_TxString("6: Memory Statics \n\r");
		UART0_TxString("--------------------------- \n\r");
		UART0_TxString("Choose one of the options: \n\r");


		do
		{
			option = UART0_RxChar();
		}while((option<'1') || (option>'6'));

		UART0_TxChar(option);
		UART0_TxString("\n\r\n\r");

		switch(option)
		{

			case FILE_READ: /* Read a File */
			UART0_TxString("\n\rEnter File name max 11 chars including file type: ");
			UART0_RxString(sourceFileName);

			srcFilePtr = FILE_Open(sourceFileName,READ,&returnStatus);
			if(srcFilePtr == 0)
			{
				UART0_TxString("\n\rFile Opening Failed");
			}
			else
			{
				UART0_TxString("File Content: ");
				while(1)
				{
					ch = FILE_GetCh(srcFilePtr);
					if(ch == EOF)
					break;
					UART0_TxChar(ch);
				}

				FILE_Close(srcFilePtr);
			}
			break;



			case FILE_WRITE: /* Write to a File */
			UART0_TxString("\n\rEnter File name max 11 chars including file type: ");
			UART0_RxString(sourceFileName);

			srcFilePtr = FILE_Open(sourceFileName,WRITE,&returnStatus);
			if(srcFilePtr == 0)
			{
				UART0_TxString("\n\rFile Opening Failed");
			}
			else
			{
				UART0_TxString("\n\rEnter text ending with '>' :");
				while(1)
				{
					ch = UART0_RxChar();
					if(ch == '>')
					{
						FILE_PutCh(srcFilePtr,EOF);
						break;
					}
					else
					{   UART0_TxChar(ch);
						FILE_PutCh(srcFilePtr,ch);
					}
				}
				UART0_TxString("\n\rData saved to file, closing the file.");
				FILE_Close(srcFilePtr);
			}
			break;



			case FILE_COPY: /* File Copy */
			UART0_TxString("\n\rEnter source File name max 11 chars including file type: ");
			UART0_RxString(sourceFileName);

			srcFilePtr = FILE_Open(sourceFileName,READ,&returnStatus);
			if(srcFilePtr == 0)
			{
				UART0_TxString("\n\rSource File Opening Failed");
			}
			else
			{
				UART0_TxString("\n\rEnter destination File name max 11 chars including file type: ");
				UART0_RxString(destFileName);

				destFilePtr = FILE_Open(destFileName,WRITE,&returnStatus);

				if(destFilePtr == 0)
				{
					UART0_TxString("\n\rDestination File Opening Failed");

				}
				else
				{
					UART0_TxString("\n\rCopying the file.");
					while(1)
					{
						ch = FILE_GetCh(srcFilePtr);
						FILE_PutCh(destFilePtr,ch);
						if(ch == EOF)
						{
							break;
						}
					}
					UART0_TxString("\n\rDone Copying..");
					FILE_Close(destFilePtr);
				}

				FILE_Close(srcFilePtr);
			}
			break;



			case FILE_DELETE: // FIle Delete
			UART0_TxString("\n\rEnter File name to be deleted max 11 chars including file type: ");
			UART0_RxString(sourceFileName);

			UART0_TxString("\n\rDeleting File: ");
			returnStatus = FILE_Delete(sourceFileName);
			if(returnStatus == FAT32_FILE_OPENED_CANNOT_BE_DELETED)
			{
				UART0_TxString("\n\rFile is open cannot be deleted");
			}
			else
			{
				UART0_TxString("\n\rDone! File Deleted");
			}
			break;



			case FILE_LIST: //Print the files with size
			while(1)
			{
				returnStatus = FILE_GetList(&fileList);
				if(returnStatus != FAT32_END_OF_FILE_LIST)
				{
					UART0_Printf("\n\r%s   %Ubytes",fileList.fileName,fileList.fileSize);
				}
				else
				{
					break;
				}
			}
			break;


			case MEMORY_STATICS: //Print the SD CARD memory Total/Free in bytes
			UART0_TxString("\n\rMemory Statics is being calculated..");
			FILE_GetMemoryStatics(&totalMemory,&freeMemory);
			UART0_Printf("\n\rTotal memory:%Ubytes  Free memory:%Ubytes",totalMemory,freeMemory);
			break;

		}// End of switch
	}// End of while
}// End of main

