#include"includes.h"


void beep_on() 
{

  beep_dir = 1;
  beep = 0;
}

void beep_off() 
{

  beep_dir = 1;
  beep = 1;
}


void Balence_work(void)
{

 ac_x_eve=GetData(ACCEL_YOUT_H);
 ac_y_eve=GetData(ACCEL_XOUT_H);
 co_y_eve+=GetData(GYRO_XOUT_H); 
  

 
   ac_x=ac_x_eve/16384;          
   ac_x=asin(ac_x)*180/3.14*1.2 ; 
   ac_y=ac_y_eve/16384;         
   ac_y=asin(ac_y)*180/3.14*1.2 ; 
 

  co_y=(co_y_eve)/16.4/20;       
  hubu=0.8*(hubu+co_y*0.02)+0.2*(ac_x);

  if(abs(ac_x)>ac_x_max)
  {
     ac_x_max=abs(ac_x);
  }
  if(abs(ac_y)>ac_y_max)
  {
     ac_y_max=abs(ac_y);
  }
  ac_x=acx;
  ac_y=acy;
  last_ac_y=ac_y;
  last_ac_x=ac_x;
  ac_x_eve=0;
  ac_y_eve=0;
  co_y_eve=0;  
}
  

  