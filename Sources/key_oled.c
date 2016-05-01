#include "includes.h" 




void Key_Init(void)
{                           
     KEY_PUCR=0xff;           
    KEY_DDR=0x00;           
    KEY_PORT1 = 1;          
    KEY_PORT2 = 1;
    KEY_PORT3 = 1;
    KEY_PORT4 = 1;
}





 void Oled_ControlShow(void)  
{
   LCD_write_string(0,0,"T");
   
   
   Write_LCD2(0,6,t);
   

}


