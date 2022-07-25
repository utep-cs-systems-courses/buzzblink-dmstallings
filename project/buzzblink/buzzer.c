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
    case 142:
      buzzer_set_period(0);
      break;
    case 144:
      buzzer_set_period(G4_SHARP);
      break;
    case 146:
      buzzer_set_period(A4);
      break;
    case 148:
      buzzer_set_period(B4);
      break;
    case 150:
      buzzer_set_period(C5);
      break;
    case 152:
      buzzer_set_period(E5);
      break;
    case 154:
      buzzer_set_period(C5);
      break;
    case 156:
      buzzer_set_period(E4);
      break;
    case 158:
      buzzer_set_period(A4);
      break;
    case 160:
      buzzer_set_period(G4);
      break;
    case 168:
      buzzer_set_period(F4_SHARP);
      break;
    case 176:
      buzzer_set_period(A4_SHARP);
      break;
    case 178:
      buzzer_set_period(B4);
      break;
    case 180:
      buzzer_set_period(C5_SHARP);
      break;
    case 182:
      buzzer_set_period(D5);
      break;
    case 184:
      buzzer_set_period(F5_SHARP);
      break;
    case 186:
      buzzer_set_period(D5);
      break;
    case 188:
      buzzer_set_period(E5);
      break;
    case 190:
      buzzer_set_period(F5_SHARP);
      break;
    case 192:
      buzzer_set_period(A5);
      break;
    case 194:
      buzzer_set_period(G5);
      break;
    case 196:
      buzzer_set_period(A5);
      break;
    case 198:
      buzzer_set_period(B5);
      break;
    case 200:
      buzzer_set_period(E5);
      break;
    case 207:
      buzzer_set_period(0);
      break;
    case 208:
      buzzer_set_period(E5);
      break;
    case 210:
      buzzer_set_period(B4);
      break;
    case 212:
      buzzer_set_period(C5);
      break;
    case 214:
      buzzer_set_period(G4_SHARP);
      break;
    case 216:
      buzzer_set_period(A4);
      break;
    case 220:
      buzzer_set_period(0);
      break;
    case 226:
      buzzer_set_period(G4_SHARP);
      break;
    case 228:
      buzzer_set_period(A4);
      break;
    case 230:
      buzzer_set_period(B4);
      break;
    case 232:
      buzzer_set_period(C5);
      break;
    case 236:
      buzzer_set_period(D5);
      break;
    case 238:
      buzzer_set_period(C5);
      break;
    case 240:
      buzzer_set_period(D5);
      break;
    case 245:
      buzzer_set_period(0);
      break;
    case 246:
      buzzer_set_period(B4);
      break;
    case 248:
      buzzer_set_period(G4);
      break;
    case 250:
      buzzer_set_period(F4_SHARP);
      break;
    case 252:
      buzzer_set_period(E4);
      break;
    case 254:
      buzzer_set_period(F4_SHARP);
      break;
    case 256:
      buzzer_set_period(G4);
      break;
    case 258:
      buzzer_set_period(E4);
      break;
    case 265:
      buzzer_set_period(0);
      break;
    case 266:
      buzzer_set_period(E5);
      break;
    case 272:
      buzzer_set_period(C5);
      break;
    case 274:
      buzzer_set_period(A4);
      break;
    case 276:
      buzzer_set_period(G4);
      break;
    case 278:
      buzzer_set_period(F4_SHARP);
      break;
    case 284:
      buzzer_set_period(G4);
      break;
    case 286:
      buzzer_set_period(A4);
      break;
    case 290:
      buzzer_set_period(0);
      break;
    case 292:
      buzzer_set_period(E4);
      break;
    case 294:
      buzzer_set_period(B4);
      break;
    case 296:
      buzzer_set_period(A4);
      break;
    case 298:
      buzzer_set_period(G4);
      break;
    case 300:
      buzzer_set_period(A4);
      break;
    case 303:
      buzzer_set_period(F4_SHARP);
      break;
    case 307:
      buzzer_set_period(G4);
      break;
    case 312:
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
  switch (sixteenth_note)
    {
    case 0:
      buzzer_set_period(A4);
      break;
    case 4:
      buzzer_set_period(B4);
      break;
    case 6:
      buzzer_set_period(C4_SHARP);
      break;
    case 8:
      buzzer_set_period(G4_SHARP);
      break;
    case 12:
      buzzer_set_period(F4_SHARP);
      break;
    }
}
