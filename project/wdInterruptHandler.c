#include <msp430.h>
#include "stateMachines.h"

#define GREEN_LED BIT6

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  static char blink_count = 0;
  P1OUT |= GREEN_LED;
  if (++blink_count == 100){
    state_advance();
    blink_count = 0;
  }
  P1OUT &= ~GREEN_LED;
}
