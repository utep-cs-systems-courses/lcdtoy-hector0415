#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>

#include "stateMachines.h"
#include "switches.h"

#define GREEN_LED BIT6

int redrawScreen = 1;

static int sm1 = 1;
static int sm2 = 1;
static int sm3 = 1;
static int sm4 = 1;

void main()
{
  P1DIR |= GREEN_LED;
  P1OUT |= GREEN_LED;

  configureClocks();
  lcd_init();
  switch_init();

  or_sr(0x8);
  enableWDTInterrupts();
  
  clearScreen(COLOR_GREEN);
  
}
