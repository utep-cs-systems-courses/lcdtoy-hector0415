#include <msp430.h>
#include "stateMachines.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include "renderings.h"

char state = 0;

static u_char x = 0;
static u_char y = 0;
static u_char wid = 20;
static u_char len = 20;

void state_advance()
{
  switch(state)
    {
    case 1:
      draw_shape(x,y,wid,len,COLOR_GREEN);
      x = (x-5);
      draw_shape(x,y,wid,len,COLOR_RED);
      break;

    case 2:
      draw_shape(x,y,wid,len,COLOR_GREEN);
      x = (x+5);
      draw_shape(x,y,wid,len,COLOR_RED);
      
      break;

    case 3:
      draw_shape(x,y,wid,len,COLOR_GREEN);
      y += 5;
      draw_shape(x,y,wid,len,COLOR_RED);
      break;

    case 4:
      draw_shape(x,y,wid,len,COLOR_GREEN);
      y -= 5;
      draw_shape(x,y,wid,len,COLOR_RED);
      break;
    }
}
