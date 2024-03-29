#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char state = 0;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  if (~p2val & SW1) {
    state = 1;
    sixteenth_note = 0;
  }
  else if (~p2val & SW2) {
    state = 2;
    sixteenth_note = 0;
  }
  else if (~p2val & SW3) {
    state = 3;
    sixteenth_note = 0;
  }
  else if (~p2val & SW4) {
    state = 4;
    sixteenth_note = 0;
  }
  else {
    state = 0;
    sixteenth_note = 0;
  }
}
