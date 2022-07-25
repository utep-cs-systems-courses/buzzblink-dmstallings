#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

int sixteenth_note = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char count = 0;
  count++;
  
  switch (state) {
    case 1:
      mainTheme(sixteenth_note);
      if (count == 75)
	{
	  sixteenth_note++;
	  count = 0;
	}
      break;
    case 2:
      /*aerithsTheme(sixteenth_note);
      if (count < 250)
	{
	  sixteenth_note++;
	  count = 0;
	  }*/
      buzzer_set_period(10000);
      break;
    case 3:
      tifasTheme(sixteenth_note);
      if (count < 250)
	{
	  sixteenth_note++;
	  count = 0;
	}
      break;
    case 4:
      aheadOnOurWay(sixteenth_note);
      if (count == 45)
	{
	  count = 0;
	  sixteenth_note++;
	}
      break;
    default:
      buzzer_set_period(0);
      count = 0;
      sixteenth_note = 0;
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
