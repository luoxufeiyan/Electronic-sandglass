#include "includes.h"


void Pwm0_Init(void)
{
  
    PWMCLK_PCLK0=pwmclk_pclk00;   
    PWMPRCLK_PCKA=pwmprclk_pcka0; 
    #if  pwmclk_pclk00==1
    PWMSCLA=pwmscla0;           
    #endif
    PWMPOL_PPOL0=1;               
    PWMCAE_CAE0=0;                
    PWMPER0=pwmper0;              
    PWMDTY0=pwmdty0;              
    PWME_PWME0=1;                
}


void Pwm1_Init(void)
{
   
    PWMCLK_PCLK1=pwmclk_pclk11;    
    PWMPRCLK_PCKA=pwmprclk_pcka1;
    #if  pwmclk_pclk11==1
    PWMSCLA=pwmscla1;             
    #endif
    PWMPOL_PPOL1=1;                
    PWMCAE_CAE1=0;               
    PWMPER1=pwmper1;             
    PWMDTY1=pwmdty1;              
    PWME_PWME1=1;            
}


void Pwm2_Init(void)
{
   
    PWMCLK_PCLK2=pwmclk_pclk22;   
    PWMPRCLK_PCKB=pwmprclk_pckb2; 
    #if  pwmclk_pclk22==1
    PWMSCLB=pwmsclb2;              
    #endif
    PWMPOL_PPOL2=1;              
    PWMCAE_CAE2=0;                
    PWMPER2=pwmper2;              
    PWMDTY2=pwmdty2;             
    PWME_PWME2=1;                
}


void Pwm3_Init(void)
{
   
    PWMCLK_PCLK3=pwmclk_pclk33;  
    PWMPRCLK_PCKB=pwmprclk_pckb3; 
    #if  pwmclk_pclk33==1
    PWMSCLB=pwmsclb3;            
    #endif
    PWMPOL_PPOL3=1;               
    PWMCAE_CAE3=0;              
    PWMPER3=pwmper3;           
    PWMDTY3=pwmdty3;          
    PWME_PWME3=1;              
}
  

void Pwm4_Init(void)
{
   
    PWMCLK_PCLK4=pwmclk_pclk44;   
    PWMPRCLK_PCKA=pwmprclk_pcka4; 
    #if  pwmclk_pclk44==1
    PWMSCLA=pwmscla4;             
    #endif
    PWMPOL_PPOL4=1;               
    PWMCAE_CAE4=0;                
    PWMPER4=pwmper4;             
    PWMDTY4=pwmdty4;            
    PWME_PWME4=1;               
}


void Pwm5_Init(void)
{
   
    PWMCLK_PCLK5=pwmclk_pclk55;   
    PWMPRCLK_PCKA=pwmprclk_pcka5; 
    #if  pwmclk_pclk55==1
    PWMSCLA=pwmscla5;             
    #endif
    PWMPOL_PPOL5=1;               
    PWMCAE_CAE5=0;               
    PWMPER5=pwmper5;            

}


void Pwm6_Init(void)
{
   
    PWMCLK_PCLK6=pwmclk_pclk66;   
    PWMPRCLK_PCKB=pwmprclk_pckb6;  
    #if  pwmclk_pclk66==1
    PWMSCLB=pwmsclb6;              
    #endif
    PWMPOL_PPOL6=1;                
    PWMCAE_CAE6=0;                 
    PWMPER6=pwmper6;            

}


void Pwm7_Init(void)
{
  
    PWMCLK_PCLK7=pwmclk_pclk77;    
    PWMPRCLK_PCKB=pwmprclk_pckb7;  
    #if  pwmclk_pclk77==1
    PWMSCLB=pwmsclb7;              
    #endif
    PWMPOL_PPOL7=1;               
    PWMCAE_CAE7=0;              
    PWMPER7=pwmper7;             

}



void Pwm01_Init(void)
{
   
    PWMCLK_PCLK1=pwmclk_pclk01;    
    PWMPRCLK_PCKA=pwmprclk_pcka01; 
    #if  pwmclk_pclk01==1
    PWMSCLA=pwmscla01;             
    #endif
    PWMPOL_PPOL1=1;                
    PWMCAE_CAE1=0;                
    PWMCTL_CON01=1;              
    PWMPER01=pwmper01;          
    PWMDTY01=pwmdty01;            

}


void Pwm23_Init(void)
{
   
    PWMCLK_PCLK3=pwmclk_pclk23;    
    PWMPRCLK_PCKB=pwmprclk_pckb23; 
    #if  pwmclk_pclk23==1
    PWMSCLB=pwmsclb23;             
    #endif
    PWMPOL_PPOL3=1;                
    PWMCAE_CAE3=0;               
    PWMCTL_CON23=1;               
    PWMPER23=pwmper23;           
    PWMDTY23=pwmdty23;            
    PWME_PWME3=1;              
}


void Pwm45_Init(void)
{
   
    PWMCLK_PCLK5=pwmclk_pclk45;    
    PWMPRCLK_PCKA=pwmprclk_pcka45; 
    #if  pwmclk_pclk45==1
    PWMSCLA=pwmscla45;             
    #endif
    PWMPOL_PPOL5=1;             
    PWMCAE_CAE5=0;                 
    PWMCTL_CON45=1;            
    PWMPER45=pwmper45;       
    PWMDTY45=pwmdty45;          
    PWME_PWME5=1;              
}



void Pwm67_Init(void)
{
   
    PWMCLK_PCLK7=pwmclk_pclk67;   
    PWMPRCLK_PCKB=pwmprclk_pckb67; 
    #if  pwmclk_pclk67==1
    PWMSCLB=pwmsclb67;            
    #endif
    PWMPOL_PPOL7=1;             
    PWMCAE_CAE7=0;                
    PWMCTL_CON67=1;              
    PWMPER67=pwmper67;            
    PWMDTY67=pwmdty67;           
    PWME_PWME7=1;;              
}


//----------------------------------------------------------------- 

void Delay(void ) 
{
    int i,j;
    for(i=0;i<=100;i++) 
    {
     for(j=0;j<=200;j++) 
     {
     }
    }
}




















































