#include <msp430.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "renderings.h"

void draw_shape(u_char x,u_char y,u_char len,u_char wid, u_int colorBRG)
{
  signed char row;
  signed char col;
  for(row = 0; row<=wid;row++)
    {
      if(row < wid/2)
	{
	  for(col = 0; col <=len;col++)
	    {
	      if(col< (len/2-row))
		drawPixel(x+col,y+row,colorBRG);
	      if(col> (len/2+row))
		drawPixel(x+col,y+row,colorBRG);
	    }
	}
      else
	{
	  for(col = 0; col <=len;col++)
	    { 
	      if(col< (row-len/2))
		drawPixel(x+col,y+row,colorBRG);
	      if(col> (len-row+len/2))
		drawPixel(x+col,y+row,colorBRG);
	    }
	}
    }
}
