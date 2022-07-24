#include <msp430.h>
#include "libTimer.h"
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
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void aheadOnOurWay(int sixteenth_note)
{
  switch (sixteenth_note)
    {
    case 0:
      buzzer_set_period(A4);
      break;
    case 2:
      buzzer_set_period(G4);
      break;
    case 4:
      buzzer_set_period(F4_SHARP);
      break;
    case 6:
      buzzer_set_period(G4);
      break;
    case 8:
      buzzer_set_period(A4);
      break;
    case 10:
      buzzer_set_period(0);
      break;
    case 12:
      buzzer_set_period(B3);
      break;
    case 14:
      buzzer_set_period(D4);
      break;
    case 16:
      buzzer_set_period(F4_SHARP);
      break;
    case 18:
      buzzer_set_period(E4);
      break;
    case 19:
      buzzer_set_period(0);
      break;
    case 20:
      buzzer_set_period(E4);
      break;
    case 24:
      buzzer_set_period(0);
      break;
    case 28:
      buzzer_set_period(E4);
      break;
    case 30:
      buzzer_set_period(B4);
      break;
    case 32:
      buzzer_set_period(A4);
      break;
    case 34:
      buzzer_set_period(G4);
      break;
    case 36:
      buzzer_set_period(A4);
      break;
    case 40:
      buzzer_set_period(0);
      break;
    case 42:
      buzzer_set_period(B4);
      break;
    case 43:
      buzzer_set_period(C5_SHARP);
      break;
    case 44:
      buzzer_set_period(D5);
      break;
    case 46:
      buzzer_set_period(B4);
      break;
    case 47:
      buzzer_set_period(0);
      break;
    case 48:
      buzzer_set_period(B4);
      break;
    case 52:
      buzzer_set_period(0);
      break;
    case 56:
      buzzer_set_period(B4);
      break;
    case 58:
      buzzer_set_period(C5);
      break;
    case 60:
      buzzer_set_period(B4);
      break;
    case 62:
      buzzer_set_period(A4);
      break;
    case 64:
      buzzer_set_period(G4);
      break;
    case 68:
      buzzer_set_period(0);
      break;
    case 70:
      buzzer_set_period(A4);
      break;
    case 72:
      buzzer_set_period(B4);
      break;
    case 74:
      buzzer_set_period(B3);
      break;
    case 76:
      buzzer_set_period(C4);
      break;
    case 78:
      buzzer_set_period(D4);
      break;
    case 80:
      buzzer_set_period(F4_SHARP);
      break;
    case 82:
      buzzer_set_period(E4);
      break;
    case 86:
      buzzer_set_period(0);
      break;
    case 88:
      buzzer_set_period(E4);
      break;
    case 90:
      buzzer_set_period(F4_SHARP);
      break;
    case 92:
      buzzer_set_period(G4);
      break;
    case 94:
      buzzer_set_period(A4);
      break;
    case 98:
      buzzer_set_period(0);
      break;
    case 102:
      buzzer_set_period(G4);
      break;
    case 104:
      buzzer_set_period(A4);
      break;
    case 106:
      buzzer_set_period(B4);
      break;
    case 108:
      buzzer_set_period(C5);
      break;
    case 112:
      buzzer_set_period(0);
      break;
    case 116:
      buzzer_set_period(F4_SHARP);
      break;
    case 118:
      buzzer_set_period(G4);
      break;
    case 120:
      buzzer_set_period(A4);
      break;
    case 122:
      buzzer_set_period(B4);
      break;
    case 124:
      buzzer_set_period(D5);
      break;
    case 128:
      buzzer_set_period(B4);
      break;
    case 130:
      buzzer_set_period(G4);
      break;
    case 132:
      buzzer_set_period(F4_SHARP);
      break;
    case 136:
      buzzer_set_period(E4);
      break;
    case 140:
      buzzer_set_period(0);
      state = 0;
    }
}

void aerithsTheme(int sixteenth_note)
{
  
}

void tifasTheme(int sixteenth_note)
{

}

void mainTheme(int sixteenth_note)
{

}
