#ifndef switches_included
#define switches_included

#define SW0 BIT0		/* switch0 is p2.0 */
#define SW1 BIT1		/* switch1 is p2.1 */
#define SW2 BIT2		/* switch2 is p2.2 */
#define SW3 BIT3		/* switch3 is p2.3 */

#define SWITCHES (SW0 | SW1 | SW2 | SW3) /* four switches on board */

extern char state;

void switch_init();
void switch_interrupt_handler();

#endif // included
