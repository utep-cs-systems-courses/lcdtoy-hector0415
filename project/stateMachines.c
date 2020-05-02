#include <msp430.h>
#include "stateMachines.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include "renderings.h"
char state = 0;
int s1c = 0;
int s2c = 0;
int s3c = 0;
int s4c = 0;

void state_advance()
{
  switch(state)
    {
    case 1:
      //clearScreen(COLOR_RED);
      draw_shape(50,50,25,25,COLOR_RED);
      break;

    case 2:
      //      clearScreen(COLOR_BLUE);
      drawString8x12(20,20,"test",COLOR_BLACK,COLOR_WHITE);
      break;

    case 3:
      //      clearScreen(COLOR_YELLOW);
      drawString5x7(20,40,"5x7 test",COLOR_BLACK,COLOR_WHITE);
      break;

    case 4:
      clearScreen(COLOR_PURPLE);
      break;
    }
}
