#include"includes.h"

void Oled_ControlShow(void)  
{   

    if(flag == 0){
      
    int i,j;
   	OLED_Write_String(64,0,"ac_x");
    OLED_Write_Num4(96, 0, acx);
  	OLED_Write_String(64,1,"ac_y");
    OLED_Write_Num4(96, 1, acy);
    OLED_Write_String(64,2,"ac_z");
    OLED_Write_Num4(96, 2, acz);
    
    for(i=1;i<=62;i++) {
      if(i!=31||i!=32){
        
        LCD_PutPixel(i,i);
        LCD_PutPixel((63-i),i); 
      }
    }
    for(i=0;i<=63;i++){
    LCD_PutPixel(i,0);
    LCD_PutPixel(i,63);
    }
    LCD_PutPixel(30,31);
    LCD_PutPixel(30,32);
    LCD_PutPixel(33,31);
    LCD_PutPixel(33,32);  
    
    for(i=0;i<=29;i++){
      for(j=i+1;j<=62-i;j++)
        LCD_PutPixel(j,i); 
    }
    }
    if(flag == 1){
    
    
    }
    if(flag == 2){
    
    
    }
    if(flag == 3){
    
    
    }
    if(flag == 4){
    
    
    }
   
}

void ALL_init(void)
{
    PLL_init(); 
    OLED_Init();    
    PIT_Init012();           
    InitMPU6050();
    I2C_Init();
    Pwm0_Init();
}

void main(void) 
{
   DisableInterrupts;
   ALL_init(); 
   EnableInterrupts;
  
   for(;;) 
   {
     Oled_ControlShow();
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
      if(count<=990){
      count ++;
      }else{
      count == 0;  
      }
      EnableInterrupts; 
       
}   

//===================================================


#pragma CODE_SEG DEFAULT	
