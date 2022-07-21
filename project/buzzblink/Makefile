
COMMON_OBJECTS  = led.o interrupts_handler.o switches.o buzzer.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ./h
LDFLAGS		= -L/opt/ti/msp430_gcc/include
DEPS		= led.h buzzer.h switches.h

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: buzzblink.elf 

#additional rules for files
buzzblink.elf: ${COMMON_OBJECTS} main.o ./lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh buzzblink.elf

clean:
	rm -f *.o *.elf
