#include"includes.h"

void Oled_ControlShow(void)  
{    

    int i,j,x=0;	
   /* LCD_P6x8Str(66,4,"x:");
    OLED_Write_Num6(35, 4, cox);
    LCD_P6x8Str(66,3,"y:");
    OLED_Write_Num6(35, 3, coy);*/
    LCD_P6x8Str(66,2,"z:");
    OLED_Write_Num6(35, 2, coz);
    LCD_Print(66,0,"电子沙漏");
    delayms(Time);
    if(flag == 0){    //模式选择 
            if(coz<50&&coz>0){
              locate = 1;
              //delayms(5*Time);      
            }
            else {
              locate = 0;
              //delayms(5*Time);
            }    
          if(locate==0){
 /**********************顺序沙漏*******************************/  
            Draw_BMP(0,0,64,7,shalou64x64);
        /*  for(i=0;i<=count;i++)  //画沙子
          {
            LCD_CutPixel(liusha_x[i],liusha_y[i]);
            LCD_PutPixel(liusha_x[i],liusha_y[i]);
          }*/
          for(j=19;j>=count;j--) 
          {
            LCD_CutPixel(liusha_x[j],liusha_y[j]);
            LCD_PutPixel(liusha_x[j],liusha_y[j]); 
          }  
            
            
          for(i=19;i>=19-count;i--)  //画沙子
          {
            LCD_CutPixel(liushaxia_x[i],liushaxia_y[i]);
            LCD_PutPixel(liushaxia_x[i],liushaxia_y[i]); 
          }
        /*  for(j=0;j<=19-count;j++) 
          {
            LCD_CutPixel(liushaxia_x[j],liushaxia_y[j]);
            LCD_PutPixel(liushaxia_x[j],liushaxia_y[j]); 
          }*/
            delayms(Time);
          flag = 1; 
          
 /*************************************************************/          
          }
          else if(locate==1){
 /**********************逆向沙漏*****************************/         
            Draw_BMP(0,0,64,7,shalou64x64);
      /*    for(i=0;i<=count;i++)  //画沙子
          {
            LCD_CutPixel(liusha_x[i],liusha_y[i]);
            LCD_PutPixel(liusha_x[i],liusha_y[i]);
          }*/
          for(j=0;j<=19-count;j++) 
          {
            LCD_CutPixel(liusha_x[j],liusha_y[j]);
            LCD_PutPixel(liusha_x[j],liusha_y[j]); 
          }  
            
            
          for(i=0;i<=count;i++)  //画沙子
          {
            LCD_CutPixel(liushaxia_x[i],liushaxia_y[i]);
            LCD_PutPixel(liushaxia_x[i],liushaxia_y[i]); 
          }
        /*  for(j=0;j<=19-count;j++) 
          {
            LCD_CutPixel(liushaxia_x[j],liushaxia_y[j]);
            LCD_PutPixel(liushaxia_x[j],liushaxia_y[j]); 
          }*/
            delayms(Time);
          flag = 1;
/***************************************************************/         
          }
    }
    
    if(flag == 1){
        if(locate==0){    
/***************************顺序流沙***********************************/    
          if(count <= 19&&count >= 0){
            LCD_CutPixel(liusha_x[count],liusha_y[count]);
            delayms(Time);
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
            LCD_PutPixel((63-liusha_x[count]),(63-liusha_y[count]));
            delayms(Time); 
            if(coz<50&&coz>0){
              locate = 1;
              delayms(5*Time); 
              flag = 0;     
            }
            else {
              locate = 0;
              delayms(5*Time);
              count++;
              flag = 1; 
            }
            
          }else if(count>19){      
            flag = 0; 
            count = 0;
            Draw_BMP(0,2,64,5,shijian64x32);
            LCD_Print(8,3,"时间到!");
            delayms(2000);
            //locate =1;
           // LCD_Init();
          } 
/*******************************************************************/      
        
        } 
        
        else if(locate==1){  
/*************************逆向沙漏程序******************************/      
        if(count <= 19&&count >= 0){
          LCD_CutPixel(liushaxia_x[count],liushaxia_y[count]);
          delayms(Time);
            if(count%2==1) { 
              if(liushaxia_y[count]==57){
                if(liushaxia_x[count]==30){
                    for(x=0;x<3;x++){
                    LCD_PutPixel(33,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(33,24-6*x);
                    delayms(Time);
                  } 
                }
                else if(liushaxia_x[count]==24){
                  for(x=0;x<3;x++){
                    LCD_PutPixel(33,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(33,24-6*x);
                    delayms(Time);
                  }
                }
                else if(liushaxia_x[count]==18){
                    for(x=0;x<2;x++){
                      LCD_PutPixel(33,24-6*x);
                      delayms(Time);
                      LCD_CutPixel(33,24-6*x);
                      delayms(Time);
                    } 
                    LCD_PutPixel(33+6,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(33+6,24-6*x);
                    delayms(Time);
                }
                else if(liushaxia_x[count]==12){
                    LCD_PutPixel(33,24);
                    delayms(Time);
                    LCD_CutPixel(33,24);
                    delayms(Time);
                    for(x=1;x<3;x++){ 
                      LCD_PutPixel(33+6*x,24-6*x);
                      delayms(Time);
                      LCD_CutPixel(33+6*x,24-6*x);
                    delayms(Time);}
                }             
              } 
              else if(liushaxia_y[count]==51)
              {
                if(liushaxia_x[count]==30){
                  for(x=0;x<2;x++){
                    LCD_PutPixel(33,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(33,24-6*x);
                    delayms(Time);
                  } 
                }
                else if(liushaxia_x[count]==24){
                  for(x=0;x<2;x++){
                    LCD_PutPixel(33,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(33,24-6*x);
                    delayms(Time);
                  }
                }
                else if(liushaxia_x[count]==18){
                  LCD_PutPixel(33,24);
                  delayms(Time);
                  LCD_CutPixel(33,24);
                  delayms(Time);
                  LCD_PutPixel(33+6,24-6);
                  delayms(Time);
                  LCD_CutPixel(33+6,24-6);
                  delayms(Time);
                }             
              } 
              else if(liushaxia_y[count]==45){
                  LCD_PutPixel(33,24);
                  delayms(Time);
                  LCD_CutPixel(33,24);
                  delayms(Time);
              }
              else if(liushaxia_y[count]==39){            
              }
                  
            }
            else {
              if(liushaxia_y[count]==57){
                if(liushaxia_x[count]==33){
                    for(x=0;x<3;x++){
                    LCD_PutPixel(30,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(30,24-6*x);
                    delayms(Time);
                  } 
                }
                else if(liushaxia_x[count]==39){
                    for(x=0;x<3;x++){
                    LCD_PutPixel(30,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(30,24-6*x);
                    delayms(Time);
                  }
                }
                else if(liushaxia_x[count]==45){
                    for(x=0;x<2;x++){
                    LCD_PutPixel(30,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(30,24-6*x);
                    delayms(Time);
                  } 
                  LCD_PutPixel(30-6,24-6*x);
                  delayms(Time);
                  LCD_CutPixel(30-6,24-6*x);
                  delayms(Time);
                }
                else if(liushaxia_x[count]==51){
                    
                  LCD_PutPixel(30,24);
                  delayms(Time);
                  LCD_CutPixel(30,24);
                  delayms(Time);
                  for(x=1;x<3;x++){ 
                    LCD_PutPixel(30-6*x,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(30-6*x,24-6*x);
                    delayms(Time);
                  }
                }  
              } 
              else if(liushaxia_y[count]==51)
              {
                if(liushaxia_x[count]==33){
                  for(x=0;x<2;x++){
                    LCD_PutPixel(30,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(30,24-6*x);
                    delayms(Time);
                  } 
                }
                else if(liushaxia_x[count]==39){
                  for(x=0;x<2;x++){
                    LCD_PutPixel(30,24-6*x);
                    delayms(Time);
                    LCD_CutPixel(30,24-6*x);
                    delayms(Time);
                  }
                }
                else if(liushaxia_x[count]==45){
                  LCD_PutPixel(30,24);
                  delayms(Time);
                  LCD_CutPixel(30,24);
                  delayms(Time);
                  LCD_PutPixel(30-6,24-6);
                  delayms(Time);
                  LCD_CutPixel(30-6,24-6);
                  delayms(Time);
                }            
              } 
              else if(liushaxia_y[count]==45){
                  LCD_PutPixel(30,24);
                  delayms(Time);
                  LCD_CutPixel(30,24);
                  delayms(Time);
              }
              else if(liushaxia_y[count]==39){            
              }
            }
          LCD_PutPixel((63-liushaxia_x[count]),(63-liushaxia_y[count]));
          delayms(Time);
          if(coz<50&&coz>=0){
              locate = 1;
              delayms(5*Time); 
              count --;
              flag =1;     
            }
            else {
              locate = 0;
              delayms(5*Time);
              flag = 0; 
            }
            
        }else if(count<0){      
          flag = 0; 
          count = 19;
          Draw_BMP(0,2,64,5,shijian64x32);
          LCD_Print(8,3,"时间到!");
          delayms(2000);
        //  locate = 0;
        //  LCD_Init(); 
        }
/********************************************************************/      
        }
      
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
     /* LCD_Fill(0xff);//黑屏 
      delayms(2000);      
      LCD_CLS();                           //清屏
      Draw_BMP(0,0,64,7,shalou64x64); *///图片显示
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
