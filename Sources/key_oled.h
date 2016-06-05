#ifndef _KEY_OLED_H
#define _KEY_OLED_H

uint KEY_DOWN = 0;
uint DELAY_NUM = 100;

#define KEY_PUCR1    PERM_PERM1
#define KEY_PUCR4    PERS_PERS6
#define KEY_PUCR3    PERM_PERM3
#define KEY_PUCR2    PERM_PERM5
#define KEY_PUCR5    PERJ_PERJ7  // ����


#define KEY_DDR1     DDRM_DDRM1        // ����Ĵ���
#define KEY_DDR4     DDRS_DDRS6
#define KEY_DDR3     DDRM_DDRM3
#define KEY_DDR2     DDRM_DDRM5
#define KEY_DDR5     DDRJ_DDRJ7


#define KEY_PORT1    PTM_PTM1       // S3,���ݼĴ���
#define KEY_PORT4    PTS_PTS6       // S7,���ݼĴ���
#define KEY_PORT3    PTM_PTM3       // S4,���ݼĴ���
#define KEY_PORT2    PTM_PTM5       // S5,���ݼĴ���
#define KEY_PORT5    PTJ_PTJ7       // S6,���ݼĴ���
    

//==============================================================
//��������  void Key_Init(void)
//���������������ĳ�ʼ������
//������    ��
//���أ�    ��
//============================================================== 
void Key_Init(void);

//==============================================================
//��������  void LCD_Key(void)
//����������ȷ���ĸ�����������
//������    ��
//���أ�    ��
//============================================================== 
void Oled_Key(void);

//==============================================================
//��������  void LCD_ControlShow(void)
//����������������Һ����ʾ
//������    ��
//���أ�    ��
//==============================================================
void Oled_ControlShow(void);

//==============================================================
//��������  void LCD_Work(void)
//����������������Һ����ʾ
//������    ��
//���أ�    ��
//==============================================================
void Oled_Work(void);

#endif