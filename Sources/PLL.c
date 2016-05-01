#include "includes.h"
void PLL_init(void)
{
  CLKSEL=0X00;
  PLLCTL_PLLON=1;
  SYNR=0xc0 | 0x04; 
  REFDV=0x80 | 0x01; 
  POSTDIV=0x00;     
  _asm(nop);         
  _asm(nop);
  while(!(CRGFLG_LOCK==1)); 
  CLKSEL_PLLSEL =1; 
}
