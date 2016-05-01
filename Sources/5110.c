
#include <hidef.h>    
#include "derivative.h"   
#include<MC9S12XS128.h>
#include"5110.h"
      
byte shuzi[]={
 0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,
 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,
 0x00, 0x42, 0x61, 0x51, 0x49, 0x46,
 0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,
 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,
 0x00, 0x27, 0x45, 0x45, 0x45, 0x39,
 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,
 0x00, 0x01, 0x71, 0x09, 0x05, 0x03,
 0x00, 0x36, 0x49, 0x49, 0x49, 0x36,
 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,

  0x00,0x7C,0x12,0x11,0x12,0x7C,
  0x00,0x7F,0x49,0x49,0x49,0x36,
  0x00,0x3E,0x41,0x41,0x41,0x22,
  0x00,0x7F,0x41,0x41,0x22,0x1C,
  0x00,0x7F,0x49,0x49,0x49,0x41,
  0x00,0x7F,0x09,0x09,0x09,0x01,
  0x00,0x3E,0x41,0x49,0x49,0x7A,
  0x00,0x7F,0x08,0x08,0x08,0x7F,
  0x00,0x00,0x41,0x7F,0x41,0x00,
  0x00,0x20,0x40,0x41,0x3F,0x01,
  0x00,0x7F,0x08,0x14,0x22,0x41,
  0x00,0x7F,0x40,0x40,0x40,0x40,
  0x00,0x7F,0x02,0x0C,0x02,0x7F,
  0x00,0x7F,0x04,0x08,0x10,0x7F,
  0x00,0x3E,0x41,0x41,0x41,0x3E,
  0x00,0x7F,0x09,0x09,0x09,0x06,
  0x00,0x3E,0x41,0x51,0x21,0x5E,
  0x00,0x7F,0x09,0x19,0x29,0x46,
  0x00,0x46,0x49,0x49,0x49,0x31,
  0x00,0x01,0x01,0x7F,0x01,0x01,
  0x00,0x3F,0x40,0x40,0x40,0x3F,
  0x00,0x1F,0x20,0x40,0x20,0x1F,
  0x00,0x3F,0x40,0x38,0x40,0x3F,
  0x00,0x63,0x14,0x08,0x14,0x63,
  0x00,0x07,0x08,0x70,0x08,0x07,
  0x00,0x61,0x51,0x49,0x45,0x43,

  0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x36,0x36,0x00,0x00,
  0x00,0x08,0x08,0x08,0x08,0x08,
  0x00,0x20,0x10,0x08,0x04,0x02,
  0x00,0x00,0x60,0x60,0x00,0x00,
  0x00,0x00,0x00,0xA0,0x60,0x00,
  0x00,0x04,0x02,0x01,0x02,0x04,
};

byte tuxiang[]=
{
0x00,0x00,0x00,0xC0,0xC0,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x03,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//µç³Ø
} ;
void delay(void)
{
	unsigned int i;
	for (i=0;i<5;i++)	  ;
		for (i=0;i<5;i++)	  ;

}


void LCD_write_byte(unsigned char dt, unsigned char command)
{
            	unsigned char i; 
            	sce=0;	
            	dc=command;	
            	for(i=0;i<8;i++)
            	{ 
            		if(dt&0x80)
            			sdin=1;
            		else
            			sdin=0;
            		dt=dt<<1;		
            		sclk=0; 		
            		sclk=1;  
            	}	
            	dc=1; 	
            	sce=1; 	
            	sdin=1;                         
}

void LCD_init(void)
{
    
        PERT=0XFF;
    
        SCLK_DDR=1;
      	SDIN_DDR=1 ;
  	    DC_DDR=1 ;
      	RES_DDR=1 ;
      	SCE_DDR=1 ;        

      	res=0;  	
        delay();
        res=1;  
          
        LCD_write_byte(0x21,0);
        LCD_write_byte(0xd0,0);
       	LCD_write_byte(0x20,0);
        LCD_write_byte(0x0C,0);
}

void LCD_set_XY(unsigned char X, unsigned char Y)
{
        	LCD_write_byte(0x40 | Y, 0);
        	LCD_write_byte(0x80 | X, 0);
} 

void LCD_clear(void)
{
                	unsigned char t;
                	unsigned char k;
                	LCD_set_XY(0,0);
                	for(t=0;t<6;t++)
                	{ 
                		for(k=0;k<84;k++)
                		{ 
                			LCD_write_byte(0x00,1);
                				
                		} 
                	}
}

void LCD_write_shu(unsigned char row, unsigned char page,unsigned char c) //row:ÁÐ page:Ò³ dd:×Ö·û
{
                	unsigned char i;
                	  	
                		LCD_set_XY(row*8, page);
                	for(i=0; i<8;i++) 
                	{
                		LCD_write_byte(0x00,1); 
                	}
                	
                    LCD_set_XY(row*8, page+1);
                	for(i=8; i<16;i++) 
                	{
                		LCD_write_byte(0x00,1);
                	}
                	LCD_set_XY(row*8, page); 
                	for(i=0; i<8;i++) 
                	{
                		LCD_write_byte(shuzi[c*16+i],1); 
                	}
                	
                    LCD_set_XY(row*8, page+1);
                	for(i=8; i<16;i++) 
                	{
                		LCD_write_byte(shuzi[c*16+i],1);
                	}	 	
}

void LCD_write_char(byte row, byte page,byte c) 
{
            	byte i;  	


            	if(c>='A'&& c<='Z')
            	  c = c - 'A'+ 10;
            	else if(c==' ')
            	  c = 36;
            	else if(c==':')
            	  c = 37;
            	else if(c=='-')
            	  c = 38;
            	else if(c=='/')
            	  c = 39;
            	else if(c=='.')
            	  c = 40;
            	else if(c==',')
            	  c = 41;
            	else if(c=='^')
            	  c = 42;
              LCD_set_XY(row*6, page);
            	for(i=0; i<6;i++) 
            	{
            		LCD_write_byte(shuzi[c*6+i],1); 
            	}
            	
                             
}
                 
void Write_LCD(uchar hang,uchar lie,uchar num) 
{
                uchar bai,shi,ge;
                 bai=num/100;
                 shi=num/10%10;
                 ge=num%10;
               
                 LCD_write_char(lie,hang,bai);  
                 LCD_write_char(lie+1,hang,shi);
                 LCD_write_char(lie+2,hang,ge);
}

void Write_LCD2(uchar hang,uchar lie, uint num2) 
{         
             uchar qian,bai,shi,ge;
                
                 qian=num2/1000;
                 bai=num2%1000/100;
                 shi=num2%1000%100/10;
                 ge=num2%10;
                
               
                 LCD_write_char(lie,hang,qian);  
                 LCD_write_char(lie+1,hang,bai);
                 LCD_write_char(lie+2,hang,shi);
                 LCD_write_char(lie+3,hang,ge);
}



void Write_LCD3(uchar hang,uchar lie, uint num3) 
{         
                 uchar wan,qian,bai,shi,ge;
                
                 wan=num3/10000; 
                 qian=num3%10000/1000;
                 bai=num3%1000/100;
                 shi=num3%1000%100/10;
                 ge=num3%10;
                                                
                 LCD_write_char(lie,hang,wan);    
                 LCD_write_char(lie+1,hang,qian);
                 LCD_write_char(lie+2,hang,bai);
                 LCD_write_char(lie+3,hang,shi);
                 LCD_write_char(lie+4,hang,ge);
}



void LCD_write_string(unsigned char row, unsigned char page,unsigned char * str)
{
	unsigned int i=0;
	for(i=0; str[i]!='\0'; i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			LCD_write_shu(row, page, str[i]-'0');	
		}
		else
		{
			LCD_write_char(row, page, str[i]);	
		}
		row++;
		if(row>13)
		{
			row = 0;
			page++;
			if(page>5)
				page = 0;
		}
		
	}
}

void display_Center(byte hang,byte lie,char k)
{        
   	LCD_write_char(lie,hang,'c');
    LCD_write_char(lie+1,hang,'n');
    LCD_write_char(lie+2,hang,'t');
   	LCD_write_char(lie+3,hang,'e');
   	LCD_write_char(lie+4,hang,'r');     	
  	Write_LCD(hang,lie+6,k) ;
  	
   	
}
 
 
void display_cha(byte hang,byte lie,char k) {
    
    
    
   	LCD_write_char(lie,hang,'c');
   	LCD_write_char(lie+1,hang,'h');
   	LCD_write_char(lie+2,hang,'a');   	
  	
  	Write_LCD(hang,lie+4,k) ;
  	
   
}

void display_AD(byte hang,byte lie,uchar k) {
    
    
    
   	LCD_write_char(lie,hang,'a');
   	LCD_write_char(lie+1,hang,'d');
  	
  	Write_LCD(hang,lie+3,k) ;
  	
}   
void display_Lx(byte hang,byte lie,char k) {
    
    
    
   	LCD_write_char(lie,hang,'L');
   	LCD_write_char(lie+1,hang,'x');
  	
  	Write_LCD(hang,lie+3,k) ;
  	
} 
void display_Rx(byte hang,byte lie,char k) {
    
    
    
   	LCD_write_char(lie,hang,'R');
   	LCD_write_char(lie+1,hang,'x');
  	
  	Write_LCD(hang,lie+3,k) ;
  	
} 
 
void display_dianji(byte hang,byte lie) {
           
   	LCD_write_char(lie,hang,'s');
   	LCD_write_char(lie+1,hang,'p');
   	LCD_write_char(lie+2,hang,'e');
   	LCD_write_char(lie+3,hang,'e');
   	LCD_write_char(lie+4,hang,'d');
   
    
} 
 
void display_duoji(byte hang,byte lie) {
    
    
    
   	LCD_write_char(lie,hang,'d');
   	LCD_write_char(lie+1,hang,'u');
   	LCD_write_char(lie+2,hang,'o');
   
   	LCD_write_char(lie+3,hang,'j');
   	LCD_write_char(lie+4,hang,'i');
  	
}  
 
void display_ccd(byte hang,byte lie) {
    
    
    
   	LCD_write_char(lie,hang,'c');
   	LCD_write_char(lie+1,hang,'c');
   	LCD_write_char(lie+2,hang,'d');  
}  
  




void display_P(byte hang,byte lie,char k) {
    
    
    
   	LCD_write_char(lie,hang,'p');
	
  	Write_LCD(hang,lie+2,k) ;
  	
} 



void  display_I(byte hang,byte lie,char k) {
    
    
   	LCD_write_char(lie,hang+1,'I');
    	
  	Write_LCD(hang,lie+2,k) ;
  	
}    


void  display_D(byte hang,byte lie,char k) {
        
   	LCD_write_char(lie,hang+1,'d');
  	
  	Write_LCD(hang,lie+2,k) ;
  	
}  

void  display_PWMDTY45(byte hang,byte lie,int data) {
    
    
    
   	LCD_write_char(lie,hang,'p');
   	LCD_write_char(lie+1,hang,'W');
   	LCD_write_char(lie+2,hang,'M');
   	LCD_write_char(lie+3,hang,'d');
   	LCD_write_char(lie+4,hang,'T');
   	LCD_write_char(lie+5,hang,'Y');
   	LCD_write_char(lie+6,hang,5);

  	
  	Write_LCD2(hang,lie+8,data) ;
  	
}


void  display_PWMDTY01(byte hang,byte lie,int data) {
            
   	LCD_write_char(lie,hang,'p');
   	LCD_write_char(lie+1,hang,'W');
   	LCD_write_char(lie+2,hang,'M');
   	LCD_write_char(lie+3,hang,'d');
   	LCD_write_char(lie+4,hang,'T');
   	LCD_write_char(lie+5,hang,'Y');
   	LCD_write_char(lie+6,hang,1);

  	
  	Write_LCD2(hang,lie+8,data) ;
  	
}



void qing_fangkuai(byte hang,byte lie) 
{
    int i=0;
    for(i=0;i<3;i++)
        {
          
          LCD_set_XY(lie+i,hang); 
          LCD_write_byte(0x00,1);
        }
}  
 

