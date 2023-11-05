	# Makefile for programming AVR in Geany 
	MK=atmega328p
	compile:
		"C:\Program
	Files\Arduino\hardware\tools\avr\bin\avr-gcc.exe" -
	mmcu=$(MK) -Wall -gdwarf-2 -Os -std=gnu99 -
	funsigned-char -funsigned-bitfields -fpack-struct -
	fshort-enums -MD -MP -MT main.o -MF dep_main.o.d -
	c main.c
		"C:\Program Files\Arduino\hardware\tools\
	avr\bin\avr-gcc.exe" -g -mmcu=$(MK) -o main.elf
	main.o
		"C:\Program Files\Arduino\hardware\tools\
	avr\bin\avr-objdump.exe" -h -S main.elf > main.lss
		"C:\Program Files\Arduino\hardware\tools\
	avr\bin\avr-objcopy.exe" -j .text -j .data -O ihex 
	main.elf main.hex
		"C:\Program Files\Arduino\hardware\tools\
	avr\bin\avr-size.exe" --mcu=$(MK) -C main.#000000elf 
	program:#1A1A1A#1A1A1A#000000#000000
		"C:\Program 
	Files\Arduino\hardware\tools\avr\bin\avrdude.exe" -
	C	"C:\Program
	Files\Arduino\hardware\tools\avr\etc\avrdude.conf"
	-v -patmega328p -carduino -PCOM4 -b115200 -D -
	Uflash:w:main.hex:i 
	clean:
		del -f main.o dep_main.o.d main.map 
	main.eep.hex main.hex main.lss main.eep main.elf 
	size:
		"C:\Program 
	Files\Arduino\hardware\tools\avr\bin\avr-size.exe"
	--mcu=$(MK) -C main.elf
