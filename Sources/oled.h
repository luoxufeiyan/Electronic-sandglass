/*******************(C) Copyright 2014 HDU XinGong CCD SmartCar************************
  File Name   : oled.h

  Author      : ZhaoXiang

  Found Date  : 2014.2.12
   
  Description : OLEDҺ����ʾģ��ײ�����ͷ�ļ� 

              * 4��SPIʹ��˵����
              * VBT ���ڲ�DC-DC��ѹ��3.3~4.3V
              *                      ���ʹ��5V��ѹ��Ϊ���������һ��100~500ŷ�ĵ���    
              * CS         Ƭѡ�ܽ�(��ѡ)
              *
              * DC         ��������ѡ��ܽ�
              * RST        ģ�鸴λ�ܽ� 
              * D0��SCLK�� ʱ�ӽţ���MCU����
              * D1��MOSI�� ��������������ݽţ���MCU���� 
****************************************************************************************/

#ifndef _OLED_H_
#define _OLED_H_

#include "includes.h"

/******************** Device Config ********************/

/* OLED�˿ں궨�� */

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
 *                        ** ��С������ʾ���л� **
 *    ֻ���� "oled.c" ���޸� "OLED_Write_Char()" ���� ������ʾ��ѡһ����
 *    �����������Ҳ�Ƕ�ѡһ(��Լ��Ƭ���ڴ�)
 *    ע�⣺ʹ�ô�����ʱ��yֻ��ȡ"0, 2, 4, 6" ��4��
 */

/**************** End of Device Config *****************/


/* OLED�ֱ��ʺ궨�� */
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
 *  ����д��
 */
void OLED_WrDat(unsigned char data);

/*
 *  ����д��
 */
void OLED_WrCmd(unsigned char cmd);

/*
 *  ��������
 */
void OLED_Set_XY(unsigned char x,unsigned char y);

/*
 *  ��������
 */
void OLED_Clear(void);

/*
 *  ��ʱ����
 */
void OLED_Delay_ms(unsigned int ms);

/*
 *  Һ����ʼ��
 */
void OLED_Init(void);        
     

/******************************************************************************
 �������� ��OLED_Write_Char
 �������� ���ַ���ʾ
 ����˵�� ��x  SmallChars(С����) -- (0 - 20)��21��
               LargeChars(������) -- (0 - 15)��16��
            y  SmallChars(С����) -- (0 - 7) �� 8��
               LargeChars(������) -- (0 - 6) �� 4��  ** yֻ��ȡ"0, 2, 4, 6" 4�� **
            c  ������������ַ�
 �������� ����
 ʾ    �� ��OLED_Write_Char(0, 0, 'A'); -- ��0��0�п�ʼ��� A
*******************************************************************************/
void OLED_Write_Char(unsigned char x,unsigned char y,unsigned char c);


/******************************************************************************
 �������� ��OLED_Write_String
 �������� ���ַ�����ʾ
 ����˵�� ��x  SmallChars(С����) -- (0 - 20)��21��
               LargeChars(������) -- (0 - 15)��16��
            y  SmallChars(С����) -- (0 - 7) �� 8��
               LargeChars(������) -- (0 - 6) �� 4��  ** yֻ��ȡ"0, 2, 4, 6" 4�� **
            *s �ַ���
 �������� ����
 ʾ    �� ��OLED_Write_String(0, 2, (u8*)"Hello"); -- ��2��0�п�ʼ��� Hello
*******************************************************************************/   
void OLED_Write_String(unsigned char x,unsigned char y,unsigned char *s);


/******************************************************************************
 �������� ��OLED_Write_Num3
 �������� ��3λ������ʾ
 ����˵�� ��x   SmallChars(С����) -- (0 - 20)��21��
                LargeChars(������) -- (0 - 15)��16��
            y   SmallChars(С����) -- (0 - 7) �� 8��
                LargeChars(������) -- (0 - 6) �� 4��  ** yֻ��ȡ"0, 2, 4, 6" 4�� **
            num xxx  3λ����
 �������� ����
 ʾ    �� ��OLED_Write_Num3(0, 0, 199);
*******************************************************************************/
void OLED_Write_Num3(unsigned char x,unsigned char y,unsigned int num);


/******************************************************************************
 �������� ��OLED_Write_Char
 �������� ��4λ������ʾ
 ����˵�� ��x   SmallChars(С����) -- (0 - 20)��21��
                LargeChars(������) -- (0 - 15)��16��
            y   SmallChars(С����) -- (0 - 7) �� 8��
                LargeChars(������) -- (0 - 6) �� 4��  ** yֻ��ȡ"0, 2, 4, 6" 4�� **
            num xxxx  4λ����
 �������� ����
 ʾ    �� ��OLED_Write_Num4(0, 0, 1999);
*******************************************************************************/ 
void OLED_Write_Num4(unsigned char x,unsigned char y,unsigned int num);
void OLED_Write_Num6(unsigned char x,unsigned char y,unsigned int num);
void LCD_PutPixel(byte x,byte y);

//void LCD_P8x16Str(byte x,byte y,byte ch[]);

#endif