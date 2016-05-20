#include"includes.h"

void Oled_ControlShow(void)  
{    

    
    if(flag == 0){
    int i,j;
   	OLED_Write_String(33,2,"x:");
    OLED_Write_Num6(35, 2, acx);
  	OLED_Write_String(33,3,"y:");
    OLED_Write_Num6(35, 3, acy/50);
    OLED_Write_String(33,4,"z:");
    OLED_Write_Num6(35, 4, acz/50);
    /*for(i=0;i<30;i++)  //»­É³×Ó
    {
      LCD_PutPixel(shazi_x[i],shazi_y[i]);
    } 
    
    
    LCD_PutPixel(6,0);
    LCD_PutPixel(12,0);
    LCD_PutPixel(18,0);
    LCD_PutPixel(24,0);
    LCD_PutPixel(30,0);
    LCD_PutPixel(33,0);
    LCD_PutPixel(39,0);
    LCD_PutPixel(45,0);
    LCD_PutPixel(51,0);
    LCD_PutPixel(57,0);*/
    
    LCD_PutPixel(12,6);
    LCD_PutPixel(18,6);
    LCD_PutPixel(24,6);
    LCD_PutPixel(30,6);
    LCD_PutPixel(33,6);
    LCD_PutPixel(39,6);
    LCD_PutPixel(45,6);
    LCD_PutPixel(51,6);
    
    LCD_PutPixel(18,12);
    LCD_PutPixel(24,12);
    LCD_PutPixel(30,12);
    LCD_PutPixel(33,12);
    LCD_PutPixel(39,12);
    LCD_PutPixel(45,12);
    
    LCD_PutPixel(24,18);
    LCD_PutPixel(30,18);
    LCD_PutPixel(33,18);
    LCD_PutPixel(39,18);
    
    LCD_PutPixel(30,24);
    LCD_PutPixel(33,24);
    
    /*LCD_PutPixel(12,5);
//*****************»­É³Â©±ß½ç**********************    
    LCD_PutPixel(0,0);
    LCD_PutPixel((63-0),0);
    LCD_PutPixel(6,6);
    LCD_PutPixel((63-6),6);
    LCD_PutPixel(12,12);
    LCD_PutPixel((63-12),12);
    LCD_PutPixel(18,18);
    LCD_PutPixel((63-18),18);
    LCD_PutPixel(24,24);
    LCD_PutPixel((63-24),24);
    LCD_PutPixel(30,30);
    LCD_PutPixel((63-30),30);
    LCD_PutPixel(33,33);
    LCD_PutPixel((63-33),33);
    LCD_PutPixel(39,39);
    LCD_PutPixel((63-39),39);
    LCD_PutPixel(45,45);
    LCD_PutPixel((63-45),45);
    LCD_PutPixel(51,51);
    LCD_PutPixel((63-51),51);
    LCD_PutPixel(57,57);
    LCD_PutPixel((63-57),57);
    LCD_PutPixel(63,63);
    LCD_PutPixel((63-63),63);
    
    LCD_PutPixel(30,31);
    LCD_PutPixel(30,32);
    LCD_PutPixel(33,31); 
    LCD_PutPixel(33,32);  */
            
    count ++;
    }
    if(flag == 1){

    
    
    }
    if(count <= 29){
      LCD_CutPixel(liusha_x[count],liusha_y[count]);
      delayms(500);
      LCD_PutPixel((63-liusha_x[count]),(63-liusha_y[count]));
      delayms(500);
      flag = 1;
      count ++;
    }else if(count==30){
      count = 0; 
      flag = 0;
      OLED_Init(); 
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
     delayms(1000);
   }
}


#pragma CODE_SEG __NEAR_SEG NON_BANKED 

void interrupt 68 Pit0_interrupt(void)
{      
          
      DisableInterrupts;
      acx=GetData(ACCEL_XOUT_H);	
    	acy=GetData(ACCEL_YOUT_H);	
    	acz=GetData(ACCEL_ZOUT_H);	
      PITTF_PTF0=1;
      EnableInterrupts; 
       
}   

//===================================================


#pragma CODE_SEG DEFAULT	
