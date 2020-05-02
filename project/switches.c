#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

char SW1_STATE, SW2_STATE, SW3_STATE, SW4_STATE;
char switch_state_changed;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val &  SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void
switch_init()
{
  P2REN |=  SWITCHES;
  P2IE   =  SWITCHES;
  P2OUT |=  SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  SW1_STATE = (p2val & SW1) ? 0 : 1;
  SW2_STATE = (p2val & SW2) ? 0 : 1;
  SW3_STATE = (p2val & SW3) ? 0 : 1;
  SW4_STATE = (p2val & SW4) ? 0 : 1;

  if(SW1_STATE)
    state = 1;
  if(SW2_STATE)
    state = 2;
  if(SW3_STATE)
    state = 3;
  if(SW4_STATE)
    state = 4;

  switch_state_changed = 1;
  
}

