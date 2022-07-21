#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  switch (state) {
    case 1:
      buzzer_set_period(5000);
      break;
    case 2:
      buzzer_set_period(7000);
      break;
    case 3:
      buzzer_set_period(9000);
      break;
    case 4:
      buzzer_set_period(11000);
      break;
    default:
      buzzer_set_period(1000);
    }
  }

/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}
