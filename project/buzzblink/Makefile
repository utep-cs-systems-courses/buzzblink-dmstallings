COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS			 = -L/opt/ti/msp430_gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc # C COMPILER
AS              = msp430-elf-as  # ASSEMEBLY 


all: buzzblink.elf

buzzblink.elf: ${COMMON_OBJECTS} buzzer.o led.o switches.o interrupts_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: buzzblink.elf
	msp430loader.sh buzzblink.elf

clean:
	rm -f *.o
