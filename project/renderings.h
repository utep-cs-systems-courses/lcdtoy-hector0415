#ifndef renderings_included
#define renderings_included

void draw_shape(u_char x,u_char y,u_char length,u_char width, u_int colorBRG);

void drawChar8x12(u_char rcol, u_char rrow, char c, u_int fgColorBRG, u_int bgColorBGR);

void drawString8x12(u_char col, u_char row, char *string, u_int fgColorBRG, u_int bgColorBRG);

#endif
