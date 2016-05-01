#ifndef _5110_h
#define _5110_h

#define sclk  PORTE_PE3 
#define sdin  PORTE_PE2
#define dc    PORTE_PE5
#define res   PORTE_PE4
#define sce   PORTE_PE7

#define SCLK_DDR  DDRE_DDRE3
#define SDIN_DDR  DDRE_DDRE2
#define DC_DDR    DDRE_DDRE5
#define RES_DDR   DDRE_DDRE4
#define SCE_DDR   DDRE_DDRE7  
                                   
void delay(void);
void LCD_write_byte(unsigned char dt, unsigned char command);
void LCD_init(void);
void LCD_clear(void);
void LCD_write_shu(unsigned char row, unsigned char page,unsigned char c);
void LCD_write_char(byte row, byte page,byte c);
void Write_LCD(uchar hang,uchar lie, uchar num);
void Write_LCD2(uchar hang,uchar lie, uint num2);
void Write_LCD3(uchar hang,uchar lie, uint num3);
void LCD_write_string(unsigned char row, unsigned char page,unsigned char * str);
void  display_PWMDTY01(byte hang,byte lie,int data) ;
void  display_PWMDTY45(byte hang,byte lie,int data);
void  display_D(byte hang,byte lie,char k) ;
void  display_I(byte hang,byte lie,char k) ;
void display_P(byte hang,byte lie,char k)  ;
void display_ccd(byte hang,byte lie)   ;
void display_duoji(byte hang,byte lie) ;
void display_dianji(byte hang,byte lie) ;
void display_Rx(byte hang,byte lie,char k) ;
void display_Lx(byte hang,byte lie,char k)  ;
void display_AD(byte hang,byte lie,byte k)  ;
void display_cha(byte hang,byte lie,char k)   ;
void display_Center(byte hang,byte lie,char k);


#endif