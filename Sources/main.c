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
    
   /*for(j=1;j<=62;j++) {

        
        LCD_PutPixel(i,i);
        LCD_PutPixel((63-i),i); 

    } */ 
    for(i=0;i<63;i=i+4){

    }   
    
    LCD_PutPixel(4,4);
    LCD_PutPixel((63-4),4);
    LCD_PutPixel(8,8);
    LCD_PutPixel((63-8),8);
    LCD_PutPixel(12,12);
    LCD_PutPixel((63-12),12);
    LCD_PutPixel(16,16);
    LCD_PutPixel((63-16),16);
    LCD_PutPixel(20,20);
    LCD_PutPixel((63-20),20);
    LCD_PutPixel(24,24);
    LCD_PutPixel((63-24),24);
    LCD_PutPixel(28,28);
    LCD_PutPixel((63-28),28);
    LCD_PutPixel(36,36);
    LCD_PutPixel((63-36),36);
    LCD_PutPixel(40,40);
    LCD_PutPixel((63-40),40);
    LCD_PutPixel(44,44);
    LCD_PutPixel((63-44),44);
    LCD_PutPixel(48,48);
    LCD_PutPixel((63-48),48);
    LCD_PutPixel(52,52);
    LCD_PutPixel((63-52),52);
    LCD_PutPixel(56,56);
    LCD_PutPixel((63-56),56);
    LCD_PutPixel(60,60);
    LCD_PutPixel((63-60),60);
    
    LCD_PutPixel(30,31);
    LCD_PutPixel(30,32);
    LCD_PutPixel(33,31);
    LCD_PutPixel(33,32);  

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
   //Oled_ControlShow();
   EnableInterrupts;
  
   for(;;) 
   {
     Oled_ControlShow();
     delayms(500);
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
     /* if(count<=990){
      count ++;
      flag == 1;
      }else{
      count == 0; 
      flag == 0; 
      }*/
      EnableInterrupts; 
       
}   

//===================================================


#pragma CODE_SEG DEFAULT	
