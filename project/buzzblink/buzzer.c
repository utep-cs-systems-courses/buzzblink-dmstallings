#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"


void buzzer_init()
{
  /* 
    Direct timer A output "TA0.1" to P2.6.  
    According to table 21 from data sheet:
      P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
      P2SEL.6 must be 1
    Also: P2.6 direction must be output
  */
 
  timerAUpmode();   // Used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;     // Enable output to speaker (P2.6)
}


void buzzer_set_period(short cycles)   // buzzer clock = 2Mhz 
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;                  // One half cycle
}

void song1()
{
  buzzer_set_period(2500);
}

void song2()
{
  buzzer_set_period(5000);
}
