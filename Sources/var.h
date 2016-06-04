#ifndef _VAR_H
#define _VAR_H



#define beep PORTA_PA0
#define beep_dir DDRA_DDRA0
extern uint16  D;
extern uint16  P;
extern uint16  Angle;
extern uint8  work1;
extern uint8  work0;
extern uint8  flag;
extern uint8  flag_last;
extern int8  count;
extern uint8  Time;
extern uint8  locate;
//------------------------------------------------------------
extern byte shazi_x[20];
extern byte shazi_y[20];
extern byte shazixia_x[20];
extern byte shazixia_y[20];
extern byte liusha_x[20];
extern byte liusha_y[20];
extern byte liushaxia_x[20];
extern byte liushaxia_y[20];
extern byte celiuzuo_x[20];
extern byte celiuzuo_y[20];
extern byte celiuzuoxia_x[20];
extern byte celiuzuoxia_y[20];
extern byte celiuyuo_x[20];
extern byte celiuyuo_y[20];
extern byte celiuyuoxia_x[20];
extern byte celiuyuoxia_y[20];
extern float acx;
extern float acy;
extern float acz;

extern float cox;
extern float coy;
extern float coz;
extern float co_all;
extern float co_all_now;
extern float co_all_bef;


extern char CY;

extern float ac_x_eve;
extern float ac_y_eve;
extern float ac_z_eve;
extern float last_ac_x;
extern float last_ac_y;
extern float ac_x_max;
extern float ac_y_max;
extern float ac_x;
extern float ac_y;
extern float ac_z;

extern float co_x_eve;
extern float co_y_eve;
extern float co_z_eve;
extern float co_x;
extern float co_y;
extern float co_z;

extern float hubu;
extern float hubu0;

extern uint32 t;







//---------------------------------------------------- 




#endif