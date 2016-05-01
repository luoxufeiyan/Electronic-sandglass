#include"includes.h"

void Oled_ControlShow(void)  
{   
   	OLED_Write_String(8,0,"ac_x");
    OLED_Write_Num4(68, 0, acx);
  	OLED_Write_String(8,1,"ac_y");
    OLED_Write_Num4(68, 1, acy);
    OLED_Write_String(8,2,"ac_z");
    OLED_Write_Num4(68, 2, acz);
}

void ALL_init(void)
{
    PLL_init(); 
    OLED_Init();    
    PIT_Init012();           
    InitMPU6050();
    I2C_Init();
}

void main(void) 
{
   DisableInterrupts;
   ALL_init(); 
   EnableInterrupts;
  
   for(;;) 
   {
     Oled_ControlShow();  //ShowCurrentPosition
     LCD_Triangle(0,0,127,63,0);
   }
}


#pragma CODE_SEG __NEAR_SEG NON_BANKED 

void interrupt 68 Pit0_interrupt(void)
{      
          
      DisableInterrupts;
      acx=GetData(ACCEL_XOUT_H);	
    	acy=GetData(ACCEL_YOUT_H);	
    	acz=GetData(ACCEL_ZOUT_H);
    	cox=GetData(GYRO_XOUT_H);	
    	coy=GetData(GYRO_YOUT_H);	
    	coz=GetData(GYRO_ZOUT_H);	
      PITTF_PTF0=1;
      EnableInterrupts; 
       
}   

//===================================================


#pragma CODE_SEG DEFAULT	
