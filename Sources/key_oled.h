#ifndef _KEY_OLED_H
#define _KEY_OLED_H

#define KEY_DOWN    0
#define DELAY_NUM   1000

#define KEY_PUCR    PERT


#define KEY_DDR     DDRT      


#define KEY_PORT1    PTT_PTT0     
#define KEY_PORT4    PTT_PTT2      
#define KEY_PORT3    PTT_PTT4     
#define KEY_PORT2    PTT_PTT6      



void Key_Init(void);
void Oled_ControlShow(void);
void Oled_Work(void);


#endif