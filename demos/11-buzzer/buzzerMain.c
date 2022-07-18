#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
    enableWDTInterrupts();
    
    buzzer_init();
    //buzzer_set_period(2500);	/* start buzzing!!! 2MHz/1000 = 2kHz*/


    or_sr(0x18);          // CPU off, GIE on
}

long count = 0;
long period = 7500;
char state = 0;

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  count++;
  switch (state)
    {
    case 0:
      period -= 15;
      buzzer_set_period(period);
      if (count > 250)
	state = 1;
      break;
    case 1:
      period += 15;
      buzzer_set_period(period);
      if (count >= 500) {
	  count = 0;
          state = 0;
	}
      break;
    }  
}
