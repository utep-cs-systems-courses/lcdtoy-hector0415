#include <msp430.h>
#include <lcdutils.h>
#include <lcddraw.h>

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
		drawPixel(x+col,y+row,COLOR_BLACK);
	      if(col> (len/2+row))
		drawPixel(x+col,y+row,COLOR_BLACK);
	    }
	}
      else
	{
	  for(col = 0; col <=len;col++)
	    { 
	      if(col< (row-len/2))
		drawPixel(x+col,y+row,COLOR_BLACK);
	      if(col> (len-row+len/2))
		drawPixel(x+col,y+row,COLOR_BLACK);
	    }
	}
    }
}

void drawChar8x12(u_char rcol, u_char rrow, char c, u_int fgColorBRG, u_int bgColorBGR)
{
  
}

void drawStrings8x12(u_char col, u_char row, char *string, u_int fgColorBRG, u_int bgColorBRG)
{
  
}
