#include "includes.h" 

//==============================================================
//函数名：  void Key_Init(void)
//功能描述：按键的初始化程序
//参数：    无
//返回：    无
//============================================================== 
void Key_Init(void)
{  
  KEY_PUCR1=0xff;           // 上拉
  KEY_PUCR2=1;   
  KEY_PUCR3=1;
            
  KEY_DDR1=0x00;           // 方向寄存器
  KEY_DDR2=0;     
  KEY_DDR3=0;       
    
  KEY_PORT1 = 1;      // 数据寄存器 
  KEY_PORT2 = 1;
  KEY_PORT3 = 1;
  KEY_PORT4 = 1;
  KEY_PORT5 = 1;
}

//==============================================================
//函数名：  void LCD_Key(void)
//功能描述：确定哪个按键被按下
//参数：    无
//返回：    无
//============================================================== 
void Oled_Key(void)
{
		if(KEY_PORT1 == 0)          // 上
	{
	    delayms(DELAY_NUM);                        // 延时消抖
		if(KEY_PORT1 == 0 && fx!=1)
		{
			fx = 0; 	
		}
	}
	
	else if(KEY_PORT2 == 0)     // 下
	{
		delayms(DELAY_NUM);                        // 延时消抖	
		if(KEY_PORT2 == 0 && fx!=0)
		{
			fx = 1;
		}
	}
	
    else if(KEY_PORT3 == 0)      // 右
	{
		delayms(DELAY_NUM);                        // 延时消抖	
		if(KEY_PORT3 == 0 && fx!=3)
		{
			fx = 2;	
		}
	}
	
	else if(KEY_PORT4 == 0)      // 左
	{
		delayms(DELAY_NUM);                        // 延时消抖
		if(KEY_PORT4 == 0&& fx!=2)
		{
			fx = 3;	
		}
	}

	else if(KEY_PORT5 == 0)
	{
		delayms(DELAY_NUM);                        // 延时消抖
		if(KEY_PORT5 == 0)
		{ 
		  fx=0;
		}  
	}
}


//==============================================================
//函数名：  void LCD_ControlShow(void)
//功能描述：按键的液晶显示
//参数：    无
//返回：    无
//==============================================================
 void Oled_ControlShow(void)  
{	     
  LCD_P6x8Str(18,0,"fraction:");   		
}

//==============================================================
//函数名：  void LCD_Work(void)
//功能描述：按键的液晶显示
//参数：    无
//返回：    无
//==============================================================
void Oled_Work(void)
{
	Oled_Key();	
}