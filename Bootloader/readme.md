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

explore128.name= Explore Atmega128 
explore128.upload.protocol=arduino
explore128.upload.maximum_size=126976
explore128.upload.speed=57600
explore128.upload.tool=arduino:avrdude
explore128.bootloader.tool=arduino:avrdude
explore128.bootloader.low_fuses=0xFF
explore128.bootloader.high_fuses=0xDA
explore128.bootloader.extended_fuses=0xFF
explore128.bootloader.file=atmega/ATmegaBOOT_168_atmega128.hex
explore128.bootloader.unlock_bits=0x3F
explore128.bootloader.lock_bits=0x0F
explore128.build.mcu=atmega128
explore128.build.f_cpu=16000000L
explore128.build.core=arduino:arduino
explore128.build.variant=explore128