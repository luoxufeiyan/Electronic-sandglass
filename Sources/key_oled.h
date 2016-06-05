#ifndef _KEY_OLED_H
#define _KEY_OLED_H

uint KEY_DOWN = 0;
uint DELAY_NUM = 100;

#define KEY_PUCR1    PERM_PERM1
#define KEY_PUCR4    PERS_PERS6
#define KEY_PUCR3    PERM_PERM3
#define KEY_PUCR2    PERM_PERM5
#define KEY_PUCR5    PERJ_PERJ7  // 上拉


#define KEY_DDR1     DDRM_DDRM1        // 方向寄存器
#define KEY_DDR4     DDRS_DDRS6
#define KEY_DDR3     DDRM_DDRM3
#define KEY_DDR2     DDRM_DDRM5
#define KEY_DDR5     DDRJ_DDRJ7


#define KEY_PORT1    PTM_PTM1       // S3,数据寄存器
#define KEY_PORT4    PTS_PTS6       // S7,数据寄存器
#define KEY_PORT3    PTM_PTM3       // S4,数据寄存器
#define KEY_PORT2    PTM_PTM5       // S5,数据寄存器
#define KEY_PORT5    PTJ_PTJ7       // S6,数据寄存器
    

//==============================================================
//函数名：  void Key_Init(void)
//功能描述：按键的初始化程序
//参数：    无
//返回：    无
//============================================================== 
void Key_Init(void);

//==============================================================
//函数名：  void LCD_Key(void)
//功能描述：确定哪个按键被按下
//参数：    无
//返回：    无
//============================================================== 
void Oled_Key(void);

//==============================================================
//函数名：  void LCD_ControlShow(void)
//功能描述：按键的液晶显示
//参数：    无
//返回：    无
//==============================================================
void Oled_ControlShow(void);

//==============================================================
//函数名：  void LCD_Work(void)
//功能描述：按键的液晶显示
//参数：    无
//返回：    无
//==============================================================
void Oled_Work(void);

#endif