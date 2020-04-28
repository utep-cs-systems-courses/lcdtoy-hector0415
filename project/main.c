#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>

#define GREEN_LED BIT6

void main()
{
  P1DIR |= GREEN_LED;
  P1OUT |= GREEN_LED;

  configureClocks();
  lcd_init();
  p2sw_init(15);

  or_sr(0x8);
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_GREEN);

  while(1)
    {
      u_int switches = p2sw_read(),i;
      int sw_pressed = switches | switches;
      switch(sw_pressed)
	{
	case 1:
	  clearScreen(COLOR_RED);
	  break;

	case 2:
	  clearScreen(COLOR_CYAN);
	  break;

	case 4:
	  clearScreen(COLOR_YELLOW);
	  break;

	case 8:
	  clearScreen(COLOR_PINK);
	  break;

	default:
	  break;
	}
    }
}
