//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state vars that control blinking
unsigned char greenLimit = 7;  // duty cycle = 1/blinkLimit
unsigned char greenCount = 0;  // cycles 0...blinkLimit-1
unsigned char greenTime = 0; // state var representing repeating time 0…1s
unsigned char redLimit = 5;
unsigned char redCount = 0;
unsigned char redTime = 0;

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // handle blinking
  redCount++;
  if (redCount >= redLimit) {
    redCount = 0;
    P1OUT |= LED_RED;
  } else
    P1OUT &= ~LED_RED;
  
  greenCount --;
  if (greenCount >= greenLimit) { // on for 1 interrupt period
    greenCount = 7;
    P1OUT |= LED_GREEN;
  } else		          // off for blinkLimit - 1 interrupt periods
    P1OUT &= ~LED_GREEN;

  // measure a second
  greenTime ++;
  if (greenTime >= 250) {  // once each second
    greenTime = 0;
    greenLimit --;	     // reduce duty cycle
    if (greenLimit = 0)     // but don't let duty cycle go below 1/7.
      greenLimit = 7;
  }
  redTime++;
  if (redTime >= 250) {
    redTime = 0;
    redLimit++;
    if (redLimit >= 8)
      redLimit = 0;
  }
} 

