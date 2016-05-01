#include "includes.h"
#define ptld0 39    
#define pitinte_pinte0 4999
#define pitinte_pinte1 9
void PIT_Init0(void)
{ 
PITCFLMT_PITE=0;
PITCE_PCE0=1;
PITMTLD0=200-1;
PITMUX_PMUX0=0;
PITLD0=1000-1; 
PITINTE_PINTE0=1;
PITCFLMT_PITE=1;                     
}
void PIT_Init012(void) 
{
  PITCFLMT=0X00;  
  PITFLT=0X04;   
  PITCE=0x04;   
  PITMUX_PMUX0=0;  
  PITMUX_PMUX1=0;
  PITMUX_PMUX2=0;
  PITMTLD0=ptld0;    
  PITLD0=pitinte_pinte1;
  PITLD1=pitinte_pinte1;
  PITLD2=pitinte_pinte0;
  PITINTE=0X04;
  PITCFLMT=0X80;                 
}
void PIT_Init1(void)
{ 
PITCFLMT_PITE=0;
PITCE_PCE1=1;
PITMTLD1=39;
PITMUX_PMUX1=0;
PITLD1=9;
PITINTE_PINTE1=1;
PITCFLMT_PITE=1;                    
}
void PIT_Init2(void)
{ 
PITCFLMT_PITE=0;
PITCE_PCE2=1;
PITMTLD1=39;
PITMUX_PMUX2=0;
PITLD2=9;
PITINTE_PINTE2=1;
PITCFLMT_PITE=1;                      
}

