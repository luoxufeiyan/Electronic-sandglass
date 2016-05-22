#include"includes.h"

void Oled_ControlShow(void)  
{    

    int i,j;	
    LCD_P6x8Str(66,2,"x:");
    OLED_Write_Num6(35, 2, acx);
    LCD_P6x8Str(66,3,"y:");
    OLED_Write_Num6(35, 3, acy);
    LCD_P6x8Str(66,4,"z:");
    OLED_Write_Num6(35, 4, acz);
    if(flag == 0){

      Draw_BMP(0,0,64,7,shalou64x64);
      for(i=0;i<20;i++)  //»­É³×Ó
      {
        LCD_PutPixel(shazi_x[i],shazi_y[i]);
      }   
      
    }
    if(flag == 1){

    
    
    }
    if(count <= 19){
     // LCD_CLS();
      //LCD_CutPixel(liusha_x[count],liusha_y[count]);
     // for(j=count;j<30;j++){
        LCD_CutPixel(liusha_x[count],liusha_y[count]);
      //}
      delayms(500);
     // for(j=0;j<count;j++){
        LCD_PutPixel((63-liusha_x[count]),(63-liusha_y[count]));
      //}
      delayms(500);
      flag = 1;
      count ++;
    }else if(count==20){
      count = 0; 
      flag = 0;
      LCD_Init(); 
    }         
    
}

void ALL_init(void)
{
    Pll_Init();
    PIT_Init012();
    DDRB=0XFF;
    DDRS=0XFF;
    DDRM=0XFF;
    PORTB=0XFF;
    LCD_Init();              
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
    // delayms(1000);
     /* LCD_Fill(0xff);//ºÚÆÁ 
      delayms(700); 
      LCD_Fill(0x00);//ÁÁÆÁ
      delayms(1000);      
      LCD_Print(8,0,"±±¾©ÁúÇðÖÇÄÜ¿Æ¼¼");  //ºº×Ö×Ö·û´®ÏÔÊ¾
      LCD_Print(15,2,"ÖÇÄÜ³µÊ×Ñ¡Òº¾§");   //ºº×Ö×Ö·û´®ÏÔÊ¾
      LCD_P8x16Str(48,4,"OLED");          //Ó¢ÎÄ×Ö·û´®ÏÔÊ¾
      LCD_P6x8Str(16,6,"chiusir@yahoo.cn");//Ó¢ÎÄ×Ö·û´®ÏÔÊ¾ 
      LCD_P6x8Str(34,7,"2011-09-03");      //Ó¢ÎÄ×Ö·û´®ÏÔÊ¾
      delayms(2000);      
      LCD_CLS();                           //ÇåÆÁ
      Draw_BMP(0,0,64,7,shalou64x64); *///Í¼Æ¬ÏÔÊ¾
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
