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
    /*for(i=0;i<30;i++)  //»­É³×Ó
    {
      LCD_PutPixel(shazi_x[i],shazi_y[i]);
    } */
    
    /*LCD_PutPixel(12,6);
//*****************»­É³Â©±ß½ç**********************    
    LCD_PutPixel(0,0);
    LCD_PutPixel(6,0);
    LCD_PutPixel(12,0);
    LCD_PutPixel(18,0);
    LCD_PutPixel(24,0);
    LCD_PutPixel(30,0);
    LCD_PutPixel(33,0);
    LCD_PutPixel(39,0);
    LCD_PutPixel(45,0);
    LCD_PutPixel(51,0);
    LCD_PutPixel(57,0);
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
    LCD_PutPixel(33,32);  
            */
    
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
      delayms(500);
     /* if(count <= 29){
         LCD_CutPixel(liusha_x[count],liusha_y[count]);
         
         LCD_PutPixel((63-liusha_x[count]),(63-liusha_y[count]));
      }else {
        count == 0; 
        flag == 0; 
      }
      count ++;*/
      EnableInterrupts; 
       
}   

//===================================================


#pragma CODE_SEG DEFAULT	
