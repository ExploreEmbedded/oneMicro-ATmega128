Settings for bootloader.
The board comes with a pre-flashed bootloader, you need not do these steps for normal usage.

Bootloader Settings:

1. Flash the ATmegaBOOT_168_atmega128.hex file with Khazama Programmer
2. Set the Fuse Bits as below with XploreFlash:
* low_fuses=0xFF
* high_fuses=0xDA
* extended_fuses=0xFF
* lock_bits=0x0F



//additional information for using the board with arduino IDE.
visit

https://github.com/ExploreEmbedded/Arduino_Boards

