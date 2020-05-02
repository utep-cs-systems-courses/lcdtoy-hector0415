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

void drawChar(u_char rcol, u_char rrow, char c, u_int fgColorBGR, u_int bgColorBGR)
{
  u_char col = 0;
  u_char row = 0;
  u_char bit = 0x01;
  u_char oc = c - 0x20;
  
  lcd_setArea(rcol,rrow,rcol+10,rrow+16);
  while(row < 16)
    {
      while (col < 11)
	{
	  u_int colorBGR = (font_11x16[oc][col] & bit) ? fgColorBGR : bgColorBGR;
	  lcd_writeColor(colorBGR);
	  col++;
	}
      col = 0;
      bit <<= 1;
      row++;
    }
}

void drawString(u_char col, u_char row, char *string, u_int fgColorBGR, u_int bgColorBGR)
{
  u_char cols = col;
  while(*string)
    {
      drawChar(cols,row, *string++, fgColorBGR,bgColorBGR);
      cols += 14;
    }
}
