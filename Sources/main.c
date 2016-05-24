#include"includes.h"

void Oled_ControlShow(void)  
{    

    int i,j,x=0;	
    LCD_P6x8Str(66,2,"x:");
    OLED_Write_Num6(35, 2, cox);
    LCD_P6x8Str(66,3,"y:");
    OLED_Write_Num6(35, 3, coy);
    LCD_P6x8Str(66,4,"z:");
    OLED_Write_Num6(35, 4, coz);
    LCD_Print(66,0,"µç×ÓÉ³Â©");
    if(flag == 0){
      Draw_BMP(0,0,64,7,shalou64x64);
      for(i=0;i<20;i++)  //»­É³×Ó
      {
        LCD_PutPixel(shazi_x[i],shazi_y[i]);
      }   
      
    }
    
    if(count <= 19){
        LCD_CutPixel(liusha_x[count],liusha_y[count]);
        delayms(Time);
        if(flag == 1){
          if(count%2==0) { 
            if(liusha_y[count]==6){
              if(liusha_x[count]==30){
                  for(x=0;x<3;x++){
                  LCD_PutPixel(33,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(33,39+6*x);
                  delayms(Time);
                } 
              }
              else if(liusha_x[count]==24){
                for(x=0;x<3;x++){
                  LCD_PutPixel(33,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(33,39+6*x);
                  delayms(Time);
                }
              }
              else if(liusha_x[count]==18){
                  for(x=0;x<2;x++){
                    LCD_PutPixel(33,39+6*x);
                    delayms(Time);
                    LCD_CutPixel(33,39+6*x);
                    delayms(Time);
                  } 
                  LCD_PutPixel(33+6,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(33+6,39+6*x);
                  delayms(Time);
              }
              else if(liusha_x[count]==12){
                  LCD_PutPixel(33,39);
                  delayms(Time);
                  LCD_CutPixel(33,39);
                  delayms(Time);
                  for(x=1;x<3;x++){ 
                    LCD_PutPixel(33+6*x,39+6*x);
                    delayms(Time);
                    LCD_CutPixel(33+6*x,39+6*x);
                  delayms(Time);}
              }             
            } 
            else if(liusha_y[count]==12)
            {
              if(liusha_x[count]==30){
                for(x=0;x<2;x++){
                  LCD_PutPixel(33,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(33,39+6*x);
                  delayms(Time);
                } 
              }
              else if(liusha_x[count]==24){
                for(x=0;x<2;x++){
                  LCD_PutPixel(33,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(33,39+6*x);
                  delayms(Time);
                }
              }
              else if(liusha_x[count]==18){
                LCD_PutPixel(33,39);
                delayms(Time);
                LCD_CutPixel(33,39);
                delayms(Time);
                LCD_PutPixel(33+6,39+6);
                delayms(Time);
                LCD_CutPixel(33+6,39+6);
                delayms(Time);
              }             
            } 
            else if(liusha_y[count]==18){
                LCD_PutPixel(33,39);
                delayms(Time);
                LCD_CutPixel(33,39);
                delayms(Time);
            }
            else if(liusha_y[count]==24){            
            }
                
          }
          else {
            if(liusha_y[count]==6){
              if(liusha_x[count]==33){
                  for(x=0;x<3;x++){
                  LCD_PutPixel(30,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(30,39+6*x);
                  delayms(Time);
                } 
              }
              else if(liusha_x[count]==39){
                  for(x=0;x<3;x++){
                  LCD_PutPixel(30,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(30,39+6*x);
                  delayms(Time);
                }
              }
              else if(liusha_x[count]==45){
                  for(x=0;x<2;x++){
                  LCD_PutPixel(30,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(30,39+6*x);
                  delayms(Time);
                } 
                LCD_PutPixel(30-6,39+6*x);
                delayms(Time);
                LCD_CutPixel(30-6,39+6*x);
                delayms(Time);
              }
              else if(liusha_x[count]==51){
                  
                LCD_PutPixel(30,39);
                delayms(Time);
                LCD_CutPixel(30,39);
                delayms(Time);
                for(x=1;x<3;x++){ 
                  LCD_PutPixel(30-6*x,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(30-6*x,39+6*x);
                  delayms(Time);
                }
              }  
            } 
            else if(liusha_y[count]==12)
            {
              if(liusha_x[count]==33){
                for(x=0;x<2;x++){
                  LCD_PutPixel(30,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(30,39+6*x);
                  delayms(Time);
                } 
              }
              else if(liusha_x[count]==39){
                for(x=0;x<2;x++){
                  LCD_PutPixel(30,39+6*x);
                  delayms(Time);
                  LCD_CutPixel(30,39+6*x);
                  delayms(Time);
                }
              }
              else if(liusha_x[count]==45){
                LCD_PutPixel(30,39);
                delayms(Time);
                LCD_CutPixel(30,39);
                delayms(Time);
                LCD_PutPixel(30-6,39+6);
                delayms(Time);
                LCD_CutPixel(30-6,39+6);
                delayms(Time);
              }            
            } 
            else if(liusha_y[count]==18){
                LCD_PutPixel(30,39);
                delayms(Time);
                LCD_CutPixel(30,39);
                delayms(Time);
            }
            else if(liusha_y[count]==24){            
            }
          }
        } 
        LCD_PutPixel((63-liusha_x[count]),(63-liusha_y[count]));
        delayms(Time);
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
    	coz= MPU6050_GetAngle(acx,acy,acz,0);	
    	cox= MPU6050_GetAngle(acx,acy,acz,1);
    	coy= MPU6050_GetAngle(acx,acy,acz,2);
      PITTF_PTF0=1;
      EnableInterrupts; 
       
}   

//===================================================


#pragma CODE_SEG DEFAULT	
