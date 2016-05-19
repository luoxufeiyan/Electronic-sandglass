/*******************(C) Copyright 2014 HDU XinGong CCD SmartCar************************
  File Name   : oled.h

  Author      : ZhaoXiang

  Found Date  : 2014.2.12
   
  Description : OLED液晶显示模块底层驱动头文件 

              * 4线SPI使用说明：
              * VBT 供内部DC-DC电压，3.3~4.3V
              *                      如果使用5V电压，为保险起见串一个100~500欧的电阻    
              * CS         片选管脚(已选)
              *
              * DC         命令数据选择管脚
              * RST        模块复位管脚 
              * D0（SCLK） 时钟脚，由MCU控制
              * D1（MOSI） 主输出从输入数据脚，由MCU控制 
****************************************************************************************/

#ifndef _OLED_H_
#define _OLED_H_

#include "includes.h"

/******************** Device Config ********************/

/* OLED端口宏定义 */

#define OLED_SCL   PTM_PTM0   //24   //D0   SCLK
#define OLED_SDA   PTM_PTM1   //26   //D1   MOSI
#define OLED_RST   PTM_PTM2   //25   //RST
#define OLED_DC    PTM_PTM3   //28   //DC
#define OLED_CS    PTM_PTM4          //CS
                                   
#define SCL_DDR  DDRM_DDRM0 
#define SDA_DDR  DDRM_DDRM1      
#define RST_DDR  DDRM_DDRM2
#define DC_DDR   DDRM_DDRM3 
#define CS_DDR   DDRM_DDRM4
/*
 *                        ** 大小字体显示的切换 **
 *    只需在 "oled.c" 中修改 "OLED_Write_Char()" 函数 两种显示二选一即可
 *    且两套字体库也是二选一(节约单片机内存)
 *    注意：使用大字体时，y只能取"0, 2, 4, 6" 共4行
 */

/**************** End of Device Config *****************/


/* OLED分辨率宏定义 */
#define  X_WIDTH  128
#define  Y_WIDTH  64
#define XLevelL		0x00
#define XLevelH		0x10
#define XLevel		((XLevelH&0x0F)*16+XLevelL)
#define Max_Column	128
#define Max_Row		  64
#define	Brightness	0xCF 




/* Function Prototypes */
/*
 *  数据写入
 */
void OLED_WrDat(unsigned char data);

/*
 *  命令写入
 */
void OLED_WrCmd(unsigned char cmd);

/*
 *  坐标设置
 */
void OLED_Set_XY(unsigned char x,unsigned char y);

/*
 *  清屏函数
 */
void OLED_Clear(void);

/*
 *  延时函数
 */
void OLED_Delay_ms(unsigned int ms);

/*
 *  液晶初始化
 */
void OLED_Init(void);        
     

/******************************************************************************
 函数名称 ：OLED_Write_Char
 功能描述 ：字符显示
 参数说明 ：x  SmallChars(小字体) -- (0 - 20)共21列
               LargeChars(大字体) -- (0 - 15)共16列
            y  SmallChars(小字体) -- (0 - 7) 共 8行
               LargeChars(大字体) -- (0 - 6) 共 4行  ** y只能取"0, 2, 4, 6" 4行 **
            c  字体库中任意字符
 函数返回 ：无
 示    例 ：OLED_Write_Char(0, 0, 'A'); -- 在0行0列开始输出 A
*******************************************************************************/
void OLED_Write_Char(unsigned char x,unsigned char y,unsigned char c);


/******************************************************************************
 函数名称 ：OLED_Write_String
 功能描述 ：字符串显示
 参数说明 ：x  SmallChars(小字体) -- (0 - 20)共21列
               LargeChars(大字体) -- (0 - 15)共16列
            y  SmallChars(小字体) -- (0 - 7) 共 8行
               LargeChars(大字体) -- (0 - 6) 共 4行  ** y只能取"0, 2, 4, 6" 4行 **
            *s 字符串
 函数返回 ：无
 示    例 ：OLED_Write_String(0, 2, (u8*)"Hello"); -- 在2行0列开始输出 Hello
*******************************************************************************/   
void OLED_Write_String(unsigned char x,unsigned char y,unsigned char *s);


/******************************************************************************
 函数名称 ：OLED_Write_Num3
 功能描述 ：3位数字显示
 参数说明 ：x   SmallChars(小字体) -- (0 - 20)共21列
                LargeChars(大字体) -- (0 - 15)共16列
            y   SmallChars(小字体) -- (0 - 7) 共 8行
                LargeChars(大字体) -- (0 - 6) 共 4行  ** y只能取"0, 2, 4, 6" 4行 **
            num xxx  3位数字
 函数返回 ：无
 示    例 ：OLED_Write_Num3(0, 0, 199);
*******************************************************************************/
void OLED_Write_Num3(unsigned char x,unsigned char y,unsigned int num);


/******************************************************************************
 函数名称 ：OLED_Write_Char
 功能描述 ：4位数字显示
 参数说明 ：x   SmallChars(小字体) -- (0 - 20)共21列
                LargeChars(大字体) -- (0 - 15)共16列
            y   SmallChars(小字体) -- (0 - 7) 共 8行
                LargeChars(大字体) -- (0 - 6) 共 4行  ** y只能取"0, 2, 4, 6" 4行 **
            num xxxx  4位数字
 函数返回 ：无
 示    例 ：OLED_Write_Num4(0, 0, 1999);
*******************************************************************************/ 
void OLED_Write_Num4(unsigned char x,unsigned char y,unsigned int num);
void OLED_Write_Num6(unsigned char x,unsigned char y,unsigned int num);
void LCD_PutPixel(byte x,byte y);

//void LCD_P8x16Str(byte x,byte y,byte ch[]);

#endif