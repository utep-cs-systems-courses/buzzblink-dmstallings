//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  or_sr(0x18);		/* CPU off, GIE on */
}

/* Not setting one of the LED bits in P1DIR means that the bit will not be set for output.
   Therefore, it would be impossible to turn on that LED.
   P1OUT |= LED will turn on an LED
   P1OUT &= ~LED will turn off an LED
   P1OUT ^= LED will toggle an LED */
