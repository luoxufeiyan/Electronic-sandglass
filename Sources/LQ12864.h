#ifndef _LQOLED_H
#define _LQOLED_H
#include "includes.h"
 extern byte longqiu96x64[768];
 extern byte shalou64x64[512];
 void LCD_Init(void);
 void LCD_CLS(void);
 void LCD_P6x8Str(byte x,byte y,byte ch[]);
 void LCD_P8x16Str(byte x,byte y,byte ch[]);
 void LCD_P14x16Str(byte x,byte y,byte ch[]);
 void LCD_Print(byte x, byte y, byte ch[]);
 void OLED_Write_Char(unsigned char x,unsigned char y,unsigned char c);
 void OLED_Write_Num6(unsigned char x,unsigned char y,unsigned int num);
 void LCD_PutPixel(byte x,byte y);
 void LCD_CutPixel(byte x,byte y);
 void LCD_Rectangle(byte x1,byte y1,byte x2,byte y2,byte gif);
 void Draw_LQLogo(void);
 void Draw_LibLogo(void);
 void Draw_BMP(byte x0,byte y0,byte x1,byte y1,byte bmp[]); 
 void LCD_Fill(byte dat);
#endif

