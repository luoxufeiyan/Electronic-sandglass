#include"includes.h"

/*void delayms(uint ms)
{   
   uint ii,jj;
   for(ii=0;ii<ms;ii++)
     for(jj=0;jj<13325;jj++);    //80MHz--1ms      
}
void delayus(uint ms)
{   
   uint ii,jj;
   for(ii=0;ii<ms;ii++)
     for(jj=0;jj<5;jj++);    //80MHz--1us      
} */
void delayms(uint ms)
{   
   uint ii,jj;
   for(ii=0;ii<ms;ii++)
     for(jj=0;jj<2660;jj++);    //16MHz--1ms      
}
void delayus(uint ms)
{   
   uint ii;
   for(ii=0;ii<ms;ii++) ;
   // for(jj=0;jj<1;jj++);    //16MHz--2us      
}