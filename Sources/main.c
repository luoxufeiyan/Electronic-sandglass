#include"includes.h"


uint KEY_DOWN = 0;
uint DELAY_NUM = 200;

#define KEY_PUCR_ADD    PERS_PERS6
#define KEY_PUCR_SUB    PERJ_PERJ7  // 上拉


#define KEY_DDR_ADD     DDRS_DDRS6
#define KEY_DDR_SUB     DDRJ_DDRJ7


#define KEY_PORT_ADD    PTS_PTS6       // S7,数据寄存器
#define KEY_PORT_SUB    PTJ_PTJ7       // S6,数据寄存器


void Key_Init(void)
{  
  KEY_PUCR_ADD=1;   
  KEY_PUCR_SUB=1;
                      // 方向寄存器
  KEY_DDR_ADD=0;     
  KEY_DDR_SUB=0;       
    
  KEY_PORT_ADD = 1;      // 数据寄存器 
  KEY_PORT_SUB = 1;
}

void Oled_Key(void)
{
		if(KEY_PORT_ADD == 0)          // 上
	{
	    delayms(DELAY_NUM);                        // 延时消抖
		if(KEY_PORT_ADD == KEY_DOWN)
		{
			Time += 10;
			delayms(DELAY_NUM);
		  LCD_P6x8Str(66,5,"T:");
      OLED_Write_Num6(35, 5, Time);   	
		}
	}
	
	else if(KEY_PORT_SUB == 0)     // 下
	{
		delayms(DELAY_NUM);                        // 延时消抖	
		if(KEY_PORT_SUB == KEY_DOWN)
		{
			Time -= 10;
			delayms(DELAY_NUM); 
			LCD_P6x8Str(66,5,"T:");
      OLED_Write_Num6(35, 5, Time); 
		}
	}
	
}


void Oled_ControlShow(void)  
{    

    int i,j,x=0;	
    LCD_P6x8Str(66,4,"x:");
    OLED_Write_Num6(35, 4, cox);
    LCD_P6x8Str(66,3,"y:");
    OLED_Write_Num6(35, 3, coy);
    LCD_P6x8Str(66,2,"z:");
    OLED_Write_Num6(35, 2, coz);
    LCD_Print(66,0,"电子沙漏");
    LCD_P6x8Str(66,5,"T:");
    OLED_Write_Num6(35, 5, Time); 
    delayms(Time);
    
    /*  if(count>19||count<0){
        if(locate == 0){
          count = 0;
        }
        if(locate == 1){
          count = 19;
        }
      }*/
    if(flag == 0){    //模式选择 
            if(coz<50&&coz>0){
              if(coy>-10&&coy<10){
                
                locate = 1;   //1  
              } else if(coy>=10&&coy<70){
                locate = 5;
              }else {
                locate = 3;
              }
              //delayms(5*Time);      
            }
            else {
              
              if(coy>-10&&coy<10){
                
                locate = 0;   //0  
              } else if(coy>=10&&coy<70){
                locate = 4;
              }else {
                locate = 2;
              }
              //delayms(5*Time);
            }    
          if(locate==0){
 /**********************顺序沙漏*******************************/  
            Draw_BMP(0,0,64,7,shalou64x64);
          for(j=19;j>=count;j--) 

          {
            LCD_CutPixel(liusha_x[j],liusha_y[j]);
            LCD_PutPixel(liusha_x[j],liusha_y[j]); 
          }  
            
            
          for(i=19;i>19-count;i--)  //画沙子
          {
            LCD_CutPixel(63-liushaxia_x[i],liushaxia_y[i]);
            LCD_PutPixel(63-liushaxia_x[i],liushaxia_y[i]); 
          }
            delayms(Time);
          flag = 1; 
          
 /*************************************************************/          
          }
          else if(locate==1){
 /**********************逆向沙漏*****************************/         
            Draw_BMP(0,0,64,7,shalou64x64);         
          for(j=0;j<19-count;j++) 
          {
            LCD_CutPixel(63-liusha_x[j],liusha_y[j]);
            LCD_PutPixel(63-liusha_x[j],liusha_y[j]); 
          }  
            
            
          for(i=0;i<=count;i++)  //画沙子
          {
            LCD_CutPixel(liushaxia_x[i],liushaxia_y[i]);
            LCD_PutPixel(liushaxia_x[i],liushaxia_y[i]); 
          }
            delayms(Time);
          flag = 1;
/***************************************************************/         
          }
          else if(locate==2){
 /**********************左下流沙*****************************/         
            Draw_BMP(0,0,64,7,shalou64x64);
          for(j=19;j>count;j--)
          {
            LCD_CutPixel(celiuzuo_x[j],celiuzuo_y[j]);
            LCD_PutPixel(celiuzuo_x[j],celiuzuo_y[j]); 
          }  
          for(i=0;i<=count;i++)  //画沙子
          {
            LCD_CutPixel(celiuzuoxia_x[i],celiuzuoxia_y[i]);
            LCD_PutPixel(celiuzuoxia_x[i],celiuzuoxia_y[i]); 
          }
            delayms(Time);
          flag = 1;
/***************************************************************/         
          }
          else if(locate==3){
 /**********************左上流沙*****************************/         
            Draw_BMP(0,0,64,7,shalou64x64);
          for(j=0;j<19-count;j++) 
          {
            LCD_CutPixel(celiuyuo_x[j],celiuyuo_y[j]);
            LCD_PutPixel(celiuyuo_x[j],celiuyuo_y[j]); 
          }  
            
            
          for(i=19;i>19-count;i--)  //画沙子
          {
            LCD_CutPixel(63-celiuyuo_x[i],63-celiuyuo_y[i]);
            LCD_PutPixel(63-celiuyuo_x[i],63-celiuyuo_y[i]); 
          }
            delayms(Time);
          flag = 1;
/***************************************************************/         
          }
          else if(locate==4){
 /**********************右下流沙*****************************/         
            Draw_BMP(0,0,64,7,shalou64x64);
          for(j=19;j>count;j--)
          {
            LCD_CutPixel(celiuyuo_x[j],celiuyuo_y[j]);
            LCD_PutPixel(celiuyuo_x[j],celiuyuo_y[j]); 
          }  
          for(i=0;i<=count;i++)  //画沙子
          {
            LCD_CutPixel(celiuyuoxia_x[i],celiuyuoxia_y[i]);
            LCD_PutPixel(celiuyuoxia_x[i],celiuyuoxia_y[i]); 
          }
            delayms(Time);
          flag = 1;
/***************************************************************/         
          }
          else if(locate==5){
 /**********************右上流沙*****************************/         
            Draw_BMP(0,0,64,7,shalou64x64);
          for(j=0;j<19-count;j++) 
          {
            LCD_CutPixel(celiuzuo_x[j],celiuzuo_y[j]);
            LCD_PutPixel(celiuzuo_x[j],celiuzuo_y[j]); 
          }  
            
            
          for(i=19;i>19-count;i--)  //画沙子
          {
            LCD_CutPixel(63-celiuzuo_x[i],63-celiuzuo_y[i]);
            LCD_PutPixel(63-celiuzuo_x[i],63-celiuzuo_y[i]); 
          }
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
              if(coy>-10&&coy<10){
                locate = 1;   //1  
                flag = 0;
              } else if(coy>=10&&coy<70){
                locate = 5;
                flag = 0;
              }else {
                locate = 3;
                flag = 0;
              }     
            }
            else {
              if(coy>-10&&coy<10){
                locate = 0;   //1
                delayms(5*Time);
                count++;
                flag = 1; 
              } else if(coy>=10&&coy<70){
                locate = 4;
                flag = 0;
              }else {
                locate = 2;
                flag = 0;
              }
            } 
            
          }else if(count>19){      
            flag = 0; 
            count = 0;
            Draw_BMP(0,2,64,5,shijian64x32);
            LCD_Print(8,3,"时间到!");
            beep_on();
            delayms(300);
            beep_off();
            delayms(1000);
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

            if(coz<50&&coz>0){
              if(coy>-10&&coy<10){
                
                locate = 1;   //1  
                delayms(5*Time);
                count --;
                flag = 1;
              } else if(coy>=10&&coy<70){
                locate = 5;
                flag = 0;
              }else {
                locate = 3;
                flag = 0;
              }      
            }
            else {
              if(coy>-10&&coy<10){
                locate = 0;   //1
                flag = 0;
              } else if(coy>=10&&coy<70){
                locate = 4;
                flag = 0;
              }else {
                locate = 2;
                flag = 0;
              } 
            } 
            
        }else if(count<0){      
          flag = 0; 
          count = 19;
          Draw_BMP(0,2,64,5,shijian64x32);
          LCD_Print(8,3,"时间到!");
          beep_on();
            delayms(300);
            beep_off();
          delayms(1000);
        //  locate = 0;
        //  LCD_Init(); 
        }
/********************************************************************/      
        }
        else if(locate==2){
          
/*************************左下沙漏程序******************************/      
        if(count <= 19&&count >= 0){
          LCD_CutPixel(celiuzuo_x[count],celiuzuo_y[count]);
          delayms(Time);
          
          if(count == 2){
            LCD_PutPixel(18,51);
            delayms(Time);
            LCD_CutPixel(18,51);
            delayms(Time);
          }else if(count == 4){
            LCD_PutPixel(24,51);
            delayms(Time);
            LCD_CutPixel(24,51);
            delayms(Time);
          }
          
          else if(count == 6){
            LCD_PutPixel(24,45);
            delayms(Time);
            LCD_CutPixel(24,45);
            delayms(Time);
            LCD_PutPixel(30,51);
            delayms(Time);
            LCD_CutPixel(30,51);
            delayms(Time);
          }else if(count == 7){
            LCD_PutPixel(24,45);
            delayms(Time);
            LCD_CutPixel(24,45);
            delayms(Time);
          }
          
          else if(count == 9){
            LCD_PutPixel(30,45);
            delayms(Time);
            LCD_CutPixel(30,45);
            delayms(Time);
            LCD_PutPixel(33,51);
            delayms(Time);
            LCD_CutPixel(33,51);
            delayms(Time);
          }else if(count == 10){
            LCD_PutPixel(30,45);
            delayms(Time);
            LCD_CutPixel(30,45);
            delayms(Time);
          }
          
          else if(count == 12){
            LCD_PutPixel(30,39);
            delayms(Time);
            LCD_CutPixel(30,39);
            delayms(Time);
            LCD_PutPixel(33,45);
            delayms(Time);
            LCD_CutPixel(33,45);
            delayms(Time);
            LCD_PutPixel(39,51);
            delayms(Time);
            LCD_CutPixel(39,51);
            delayms(Time);
          }else if(count == 13){
            LCD_PutPixel(30,39);
            delayms(Time);
            LCD_CutPixel(30,39);
            delayms(Time);
            LCD_PutPixel(33,45);
            delayms(Time);
            LCD_CutPixel(33,45);
            delayms(Time);
          }else if(count == 14){
            LCD_PutPixel(30,39);
            delayms(Time);
            LCD_CutPixel(30,39);
            delayms(Time);
          }
          
          else if(count == 16){
            LCD_PutPixel(33,39);
            delayms(Time);
            LCD_CutPixel(33,39);
            delayms(Time);
            LCD_PutPixel(39,45);
            delayms(Time);
            LCD_CutPixel(39,45);
            delayms(Time);
            LCD_PutPixel(45,51);
            delayms(Time);
            LCD_CutPixel(45,51);
            delayms(Time);
          }else if(count == 17){
            LCD_PutPixel(33,39);
            delayms(Time);
            LCD_CutPixel(33,39);
            delayms(Time);
            LCD_PutPixel(39,45);
            delayms(Time);
            LCD_CutPixel(39,45);
            delayms(Time);
          }else if(count == 18){
            LCD_PutPixel(33,39);
            delayms(Time);
            LCD_CutPixel(33,39);
            delayms(Time);
          }
             
          
          LCD_PutPixel((63-celiuzuo_x[count]),(63-celiuzuo_y[count]));
          delayms(Time); 
          if(coz<50&&coz>0){
              if(coy>-10&&coy<10){
                locate = 1;   //1  
                flag =0;
              } else if(coy>=10&&coy<70){
                locate = 5;
                flag =0;
              }else {
                locate = 3;
                flag =0;
              }
              //delayms(5*Time);      
            }
            else {
              if(coy>-10&&coy<10){
                locate = 0;   //0 
                flag =0; 
              } else if(coy>=10&&coy<70){
                locate = 4;
                flag =0;
              }else {
                locate = 2;
                count ++;
                flag =0;
              }
              //delayms(5*Time);
            }   
        
        }else if(count>19){      
            flag = 0; 
            count = 0;
            Draw_BMP(0,2,64,5,shijian64x32);
            LCD_Print(8,3,"时间到!");
            beep_on();
            delayms(300);
            beep_off();
            delayms(1000);
            //locate =1;
           // LCD_Init();
        }
/********************************************************************/      
        
        
        }
        else if(locate==3){
          
/*************************左上沙漏程序******************************/      
        if(count <= 19&&count >= 0){
          LCD_CutPixel(63-celiuyuo_x[19-count],63-celiuyuo_y[19-count]);
          delayms(Time);
          
          if(count == 17){
            LCD_PutPixel(18,12);
            delayms(Time);
            LCD_CutPixel(18,12);
            delayms(Time);
          }else if(count == 15){
            LCD_PutPixel(24,12);
            delayms(Time);
            LCD_CutPixel(24,12);
            delayms(Time);
          }
          
          else if(count == 13){
            LCD_PutPixel(24,18);
            delayms(Time);
            LCD_CutPixel(24,18);
            delayms(Time);
            LCD_PutPixel(30,12);
            delayms(Time);
            LCD_CutPixel(30,12);
            delayms(Time);
          }else if(count == 12){
            LCD_PutPixel(24,18);
            delayms(Time);
            LCD_CutPixel(24,18);
            delayms(Time);
          }
          
          else if(count == 10){
            LCD_PutPixel(30,18);
            delayms(Time);
            LCD_CutPixel(30,18);
            delayms(Time);
            LCD_PutPixel(33,12);
            delayms(Time);
            LCD_CutPixel(33,12);
            delayms(Time);
          }else if(count == 9){
            LCD_PutPixel(30,18);
            delayms(Time);
            LCD_CutPixel(10,18);
            delayms(Time);
          }
          
          else if(count == 7){
            LCD_PutPixel(30,24);
            delayms(Time);
            LCD_CutPixel(30,24);
            delayms(Time);
            LCD_PutPixel(33,18);
            delayms(Time);
            LCD_CutPixel(33,18);
            delayms(Time);
            LCD_PutPixel(39,12);
            delayms(Time);
            LCD_CutPixel(39,12);
            delayms(Time);
          }else if(count == 6){
            LCD_PutPixel(30,24);
            delayms(Time);
            LCD_CutPixel(30,24);
            delayms(Time);
            LCD_PutPixel(33,18);
            delayms(Time);
            LCD_CutPixel(33,18);
            delayms(Time);
          }else if(count == 5){
            LCD_PutPixel(30,24);
            delayms(Time);
            LCD_CutPixel(30,24);
            delayms(Time);
          }
          
          else if(count == 3){
            LCD_PutPixel(33,24);
            delayms(Time);
            LCD_CutPixel(33,24);
            delayms(Time);
            LCD_PutPixel(39,18);
            delayms(Time);
            LCD_CutPixel(39,18);
            delayms(Time);
            LCD_PutPixel(45,12);
            delayms(Time);
            LCD_CutPixel(45,12);
            delayms(Time);
          }else if(count == 2){
            LCD_PutPixel(33,24);
            delayms(Time);
            LCD_CutPixel(33,24);
            delayms(Time);
            LCD_PutPixel(39,18);
            delayms(Time);
            LCD_CutPixel(39,18);
            delayms(Time);
          }else if(count == 1){
            LCD_PutPixel(33,24);
            delayms(Time);
            LCD_CutPixel(33,24);
            delayms(Time);
          }
          
          LCD_PutPixel((celiuyuo_x[19-count]),(celiuyuo_y[19-count]));
          delayms(Time);  
           if(coz<50&&coz>0){
              if(coy>-10&&coy<10){
                locate = 1;   //1  
                flag =0;
              } else if(coy>=10&&coy<70){
                locate = 5;
                flag =0;
              }else {
                locate = 3;
                count --;
                flag =1;
              }
              //delayms(5*Time);      
            }
            else {
              if(coy>-10&&coy<10){
                locate = 0;   //0 
                flag =0; 
              } else if(coy>=10&&coy<70){
                locate = 4;
                flag =0;
              }else {
                locate = 2;
                flag =0;
              }
              //delayms(5*Time);
            }      
        }else if(count<0){      
            flag = 0; 
            count = 19;
            Draw_BMP(0,2,64,5,shijian64x32);
            LCD_Print(8,3,"时间到!");
            beep_on();
            delayms(300);
            beep_off();
            delayms(1000);
            //locate =1;
           // LCD_Init();
        }
/********************************************************************/      
        
        
        }
        else if(locate==4){
          
/*************************右下沙漏程序******************************/      
        if(count <= 19&&count >= 0){
          LCD_CutPixel(celiuyuo_x[count],celiuyuo_y[count]);
          delayms(Time);
          
          if(count == 2){
            LCD_PutPixel(45,51);
            delayms(Time);
            LCD_CutPixel(45,51);
            delayms(Time);
          }else if(count == 4){
            LCD_PutPixel(39,51);
            delayms(Time);
            LCD_CutPixel(39,51);
            delayms(Time);
          }
          
          else if(count == 6){
            LCD_PutPixel(39,45);
            delayms(Time);
            LCD_CutPixel(39,45);
            delayms(Time);
            LCD_PutPixel(33,51);
            delayms(Time);
            LCD_CutPixel(33,51);
            delayms(Time);
          }else if(count == 7){
            LCD_PutPixel(39,45);
            delayms(Time);
            LCD_CutPixel(39,45);
            delayms(Time);
          }
          
          else if(count == 9){
            LCD_PutPixel(33,45);
            delayms(Time);
            LCD_CutPixel(33,45);
            delayms(Time);
            LCD_PutPixel(30,51);
            delayms(Time);
            LCD_CutPixel(30,51);
            delayms(Time);
          }else if(count == 10){
            LCD_PutPixel(33,45);
            delayms(Time);
            LCD_CutPixel(33,45);
            delayms(Time);
          }
          
          else if(count == 12){
            LCD_PutPixel(33,39);
            delayms(Time);
            LCD_CutPixel(33,39);
            delayms(Time);
            LCD_PutPixel(30,45);
            delayms(Time);
            LCD_CutPixel(30,45);
            delayms(Time);
            LCD_PutPixel(24,51);
            delayms(Time);
            LCD_CutPixel(24,51);
            delayms(Time);
          }else if(count == 13){
            LCD_PutPixel(33,39);
            delayms(Time);
            LCD_CutPixel(33,39);
            delayms(Time);
            LCD_PutPixel(30,45);
            delayms(Time);
            LCD_CutPixel(30,45);
            delayms(Time);
          }else if(count == 14){
            LCD_PutPixel(33,39);
            delayms(Time);
            LCD_CutPixel(33,39);
            delayms(Time);
          }
          
          else if(count == 16){
            LCD_PutPixel(30,39);
            delayms(Time);
            LCD_CutPixel(30,39);
            delayms(Time);
            LCD_PutPixel(24,45);
            delayms(Time);
            LCD_CutPixel(24,45);
            delayms(Time);
            LCD_PutPixel(18,51);
            delayms(Time);
            LCD_CutPixel(18,51);
            delayms(Time);
          }else if(count == 17){
            LCD_PutPixel(30,39);
            delayms(Time);
            LCD_CutPixel(30,39);
            delayms(Time);       
            LCD_PutPixel(24,45);
            delayms(Time);
            LCD_CutPixel(24,45);
            delayms(Time);
          }else if(count == 18){
            LCD_PutPixel(30,39);
            delayms(Time);
            LCD_CutPixel(30,39);
            delayms(Time);
          }
          
          LCD_PutPixel((63-celiuyuo_x[count]),(63-celiuyuo_y[count]));
          delayms(Time);
           if(coz<50&&coz>0){
              if(coy>-10&&coy<10){
                locate = 1;   //1  
                flag =0;
              } else if(coy>=10&&coy<70){
                locate = 5;
                flag =0;
              }else {
                locate = 3;
                flag =0;
              }
              //delayms(5*Time);      
            }
            else {
              if(coy>-10&&coy<10){
                locate = 0;   //0 
                flag =0; 
              } else if(coy>=10&&coy<70){
                locate = 4;
                count ++;
                flag =1;
              }else {
                locate = 2;
                flag =0;
              }
              //delayms(5*Time);
            }        
        }else if(count>19){      
            flag = 0; 
            count = 0;
            Draw_BMP(0,2,64,5,shijian64x32);
            LCD_Print(8,3,"时间到!");
            beep_on();
            delayms(300);
            beep_off();
            delayms(1000);
            //locate =1;
           // LCD_Init();
        }
/********************************************************************/      
        
        
        }
        else if(locate==5){
          
/*************************右上沙漏程序******************************/      
        if(count <= 19&&count >= 0){
          LCD_CutPixel(63-celiuzuo_x[19-count],63-celiuzuo_y[19-count]);
          delayms(Time);
          
          if(count == 17){
            LCD_PutPixel(45,12);
            delayms(Time);
            LCD_CutPixel(45,12);
            delayms(Time);
          }else if(count == 15){
            LCD_PutPixel(39,12);
            delayms(Time);
            LCD_CutPixel(39,12);
            delayms(Time);
          }
          
          else if(count == 13){
            LCD_PutPixel(39,18);
            delayms(Time);
            LCD_CutPixel(39,18);
            delayms(Time);
            LCD_PutPixel(33,12);
            delayms(Time);
            LCD_CutPixel(33,12);
            delayms(Time);
          }else if(count == 12){
            LCD_PutPixel(39,18);
            delayms(Time);
            LCD_CutPixel(39,18);
            delayms(Time);
          }
          
          else if(count == 10){
            LCD_PutPixel(33,18);
            delayms(Time);
            LCD_CutPixel(33,18);
            delayms(Time);
            LCD_PutPixel(30,12);
            delayms(Time);
            LCD_CutPixel(30,12);
            delayms(Time);
          }else if(count == 9){
            LCD_PutPixel(33,18);
            delayms(Time);
            LCD_CutPixel(33,18);
            delayms(Time);
          }
          
          else if(count == 7){
            LCD_PutPixel(33,24);
            delayms(Time);
            LCD_CutPixel(33,24);
            delayms(Time);
            LCD_PutPixel(30,18);
            delayms(Time);
            LCD_CutPixel(30,18);
            delayms(Time);
            LCD_PutPixel(24,12);
            delayms(Time);
            LCD_CutPixel(24,12);
            delayms(Time);
          }else if(count == 6){
            LCD_PutPixel(33,24);
            delayms(Time);
            LCD_CutPixel(33,24);
            delayms(Time);
            LCD_PutPixel(30,18);
            delayms(Time);
            LCD_CutPixel(30,18);
            delayms(Time);
          }else if(count == 5){
            LCD_PutPixel(33,24);
            delayms(Time);
            LCD_CutPixel(33,24);
            delayms(Time);
          }
          
          else if(count == 3){
            LCD_PutPixel(30,24);
            delayms(Time);
            LCD_CutPixel(30,24);
            delayms(Time);
            LCD_PutPixel(24,18);
            delayms(Time);
            LCD_CutPixel(24,18);
            delayms(Time);
            LCD_PutPixel(18,12);
            delayms(Time);
            LCD_CutPixel(18,12);
            delayms(Time);
          }else if(count == 2){
            LCD_PutPixel(30,24);
            delayms(Time);
            LCD_CutPixel(30,24);
            delayms(Time);
            LCD_PutPixel(24,18);
            delayms(Time);
            LCD_CutPixel(24,18);
            delayms(Time);
          }else if(count == 1){
            LCD_PutPixel(30,24);
            delayms(Time);
            LCD_CutPixel(30,24);
            delayms(Time);
          }     
          
          LCD_PutPixel((celiuzuo_x[19-count]),(celiuzuo_y[19-count]));
          delayms(Time);
           if(coz<50&&coz>0){
              if(coy>-10&&coy<10){
                locate = 1;   //1  
                flag =0;
              } else if(coy>=10&&coy<70){
                locate = 5;
                count --;
                flag =1;
              }else {
                locate = 3;
                flag =0;
              }
              //delayms(5*Time);      
            }
            else {
              if(coy>-10&&coy<10){
                locate = 0;   //0 
                flag =0; 
              } else if(coy>=10&&coy<70){
                locate = 4;
                flag =0;
              }else {
                locate = 2;
                flag =0;
              }
              //delayms(5*Time);
            }      
        }else if(count<0){      
            flag = 0; 
            count = 19;
            Draw_BMP(0,2,64,5,shijian64x32);
            LCD_Print(8,3,"时间到!");
            beep_on();
            delayms(300);
            beep_off();
            delayms(1000);
            //locate =1;
           // LCD_Init();
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
    Key_Init();
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
     //Oled_Key();
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
      Oled_Key();
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
