#include <msp430.h>
#include "stateMachines.h"
#include <libTimer.h>

#define GREEN_LED BIT6

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  static char blink_count = 0;
  P1OUT |= GREEN_LED;
  
  if (++blink_count == 150){
    state_advance();
    blink_count = 0;
  }
  
  P1OUT &= ~GREEN_LED;
}
