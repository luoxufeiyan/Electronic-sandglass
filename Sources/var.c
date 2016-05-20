#include "includes.h"

uint16  D = 0;
uint16  P = 0;
uint16  Angle = 10; 
uint8  work1 = 250;
uint8  work0 = 0;
uint8  flag = 0;
uint8  count = 0;
//-------------------------------------------------
byte shazi_x[30]={                ////初始化沙子横坐标位置
  6,12,18,24,30,33,39,45,51,57,   //
    12,18,24,30,33,39,45,51,      //
       18,24,30,33,39,45,         //
          24,30,33,39,            //
             30,33,               //
};

byte shazi_y[30]={                ////初始化沙子纵坐标位置
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   //
     6, 6, 6, 6, 6, 6, 6, 6,      //
       12,12,12,12,12,12,         //
          18,18,18,18,            //
             24,24,               //

};

byte liusha_x[30]={               //流沙顺序横坐标编码
           30,33,
        24,39,30,33,
     18,45,24,39,30,33,
  12,51,18,45,24,39,30,33,
6,57,12,51,18,45,24,39,30,33,
};

byte liusha_y[30]={               //流沙顺序纵坐标编码
            0, 0,
        0 , 0, 6, 6,
      0, 0, 6, 6,12,12,
   0, 0, 6, 6,12,12,18,18,
0, 0, 6, 6,12,12,18,18,24,24,
};
 float acx=0;
 float acy=0;
 float acz=0;

 float cox=0;
 float coy=0;
 float coz=0;
 float co_all=0;
 float co_all_now=0;
 float co_all_bef=0;
 
 
 char CY;


float ac_x_eve=0;
float ac_y_eve=0;
float ac_z_eve=0;
float last_ac_x =0;
float last_ac_y =0;
float ac_x_max=0;
float ac_y_max=0;
float ac_x=0;
float ac_y=0;
float ac_z=0;

float co_x_eve=0;
float co_y_eve=0;
float co_z_eve=0;
float co_x=0;
float co_y=0;
float co_z=0;

float hubu=0;
float hubu0=0;


//---------------------------------------------------- 

uint32 t=189;

