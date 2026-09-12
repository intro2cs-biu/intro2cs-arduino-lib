#ifndef LCD_H
#define LCD_H

#include <stdio.h>
#include <stdarg.h>

void lcdBegin(char cols, char rows);

void lcdClear(void);
void lcdClearRow(unsigned char row);
void lcdHome(void);

void lcdSetCursor(unsigned char col, unsigned char row);

void lcdWrite(char value);
void lcdPrint(const char *str);
void lcdPrintf(const char *format, ...);

void lcdCursor(void);
void lcdNoCursor(void);

void lcdBlink(void);
void lcdNoBlink(void);

void lcdDisplay(void);
void lcdNoDisplay(void);

void lcdScrollDisplayLeft(void);
void lcdScrollDisplayRight(void);

void lcdAutoscroll(void);
void lcdNoAutoscroll(void);

void lcdLeftToRight(void);
void lcdRightToLeft(void);

void lcdCreateChar(char location, const unsigned char charmap[8]);

void lcdBacklight(void);
void lcdNoBacklight(void);

#endif
