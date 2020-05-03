#include <msp430.h>
#include "stateMachines.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include "renderings.h"
#include "buzzer.h"

char state = 0;

u_char wid = 20;
u_char len = 20;
u_char x = 54;
u_char y = 70;

static short tone = 30;

void state_advance()
{
  switch(state)
    {
    case 1:
      buzzer_set_period(tone*200);
      draw_shape(x,y,wid,len,COLOR_GREEN);
      x -= 5;
      draw_shape(x,y,wid,len,COLOR_RED);
      tone += 1;
      break;

    case 2:
      buzzer_set_period(tone*200);
      draw_shape(x,y,wid,len,COLOR_GREEN);
      x += 5;
      draw_shape(x,y,wid,len,COLOR_RED);
      tone -= 1;
      break;

    case 3:
      buzzer_set_period(tone*200);
      draw_shape(x,y,wid,len,COLOR_GREEN);
      y += 5;
      draw_shape(x,y,wid,len,COLOR_RED);
      tone += 1;
      break;

    case 4:
      buzzer_set_period(tone*200);
      draw_shape(x,y,wid,len,COLOR_GREEN);
      y -= 5;
      draw_shape(x,y,wid,len,COLOR_RED);
      tone -= 1;
      break;
    }
}
