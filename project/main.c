#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>

#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"

#define GREEN_LED BIT6

int redrawScreen = 1;

void main()
{
  P1DIR |= GREEN_LED;
  P1OUT |= GREEN_LED;

  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();
  
  or_sr(0x8);

  enableWDTInterrupts();
  
  clearScreen(COLOR_GREEN);

  draw_shape(x,y,wid,len,COLOR_RED);
  buzzer_set_period(30*200);
  
}
