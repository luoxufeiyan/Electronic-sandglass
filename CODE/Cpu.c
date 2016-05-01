/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cpu.c
**     Project   : ZJA060
**     Processor : MC9S12XS128CAL
**     Component : MC9S12XS256_112
**     Version   : Component 01.003, Driver 02.06, CPU db: 3.00.020
**     Datasheet : MC9S12XS256RMV1 Rev. 1.03 06/2008
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/5/1, 11:17
**     Abstract  :
**         This component "MC9S12XS256_112" implements properties, methods,
**         and events of the CPU.
**     Settings  :
**
**     Contents  :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetWaitMode - void Cpu_SetWaitMode(void);
**         SetStopMode - void Cpu_SetStopMode(void);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Cpu. */

#include "Events.h"
#include "Cpu.h"

#define CGM_DELAY  0x03FFU

#pragma DATA_SEG DEFAULT               /* Select data segment "DEFAULT" */
#pragma CODE_SEG DEFAULT


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR reegister */
#pragma CODE_SEG __NEAR_SEG NON_BANKED


/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MC9S12XS256_112)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S12XS256_112)
**
**     Description :
**         Disable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S12XS256_112)
**
**     Description :
**         Enable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component MC9S12XS256_112)
**
**     Description :
**         Set low power mode - Stop mode.
**         For more information about the stop mode see
**         documentation of this CPU.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetStopMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (component MC9S12XS256_112)
**
**     Description :
**         Set low power mode - Wait mode.
**         For more information about the wait mode see
**         documentation of this CPU.
**         Release from Wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetWaitMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S12XS256_112)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* Common initialization of the CPU registers */
  /* CRGINT: LOCKIE=0,SCMIE=0 */
  clrReg8Bits(CRGINT, 0x12U);           
  /* VREGCTRL: LVIE=0 */
  clrReg8Bits(VREGCTRL, 0x02U);         
  /* COPCTL: WCOP=0,RSBCK=0,WRTMASK=0,??=0,??=0,CR2=0,CR1=0,CR0=0 */
  setReg8(COPCTL, 0x00U);               
  /* RDRIV: RDPK=0,RDPE=0,RDPB=0,RDPA=0 */
  clrReg8Bits(RDRIV, 0x93U);            
  /* RDRH: RDRH7=0,RDRH6=0,RDRH5=0,RDRH4=0,RDRH3=0,RDRH2=0,RDRH1=0,RDRH0=0 */
  setReg8(RDRH, 0x00U);                 
  /* RDRJ: RDRJ7=0,RDRJ6=0,RDRJ1=0,RDRJ0=0 */
  clrReg8Bits(RDRJ, 0xC3U);             
  /* RDRM: RDRM7=0,RDRM6=0,RDRM5=0,RDRM4=0,RDRM3=0,RDRM2=0,RDRM1=0,RDRM0=0 */
  setReg8(RDRM, 0x00U);                 
  /* RDRP: RDRP7=0,RDRP6=0,RDRP5=0,RDRP4=0,RDRP3=0,RDRP2=0,RDRP1=0,RDRP0=0 */
  setReg8(RDRP, 0x00U);                 
  /* RDRS: RDRS7=0,RDRS6=0,RDRS5=0,RDRS4=0,RDRS3=0,RDRS2=0,RDRS1=0,RDRS0=0 */
  setReg8(RDRS, 0x00U);                 
  /* RDRT: RDRT7=0,RDRT6=0,RDRT5=0,RDRT4=0,RDRT3=0,RDRT2=0,RDRT1=0,RDRT0=0 */
  setReg8(RDRT, 0x00U);                 
  /* RDR0AD0: RDR0AD07=0,RDR0AD06=0,RDR0AD05=0,RDR0AD04=0,RDR0AD03=0,RDR0AD02=0,RDR0AD01=0,RDR0AD00=0 */
  setReg8(RDR0AD0, 0x00U);              
  /* RDR1AD0: RDR1AD07=0,RDR1AD06=0,RDR1AD05=0,RDR1AD04=0,RDR1AD03=0,RDR1AD02=0,RDR1AD01=0,RDR1AD00=0 */
  setReg8(RDR1AD0, 0x00U);              
  /* IRQCR: IRQEN=0 */
  clrReg8Bits(IRQCR, 0x40U);            
  /* ### MC9S12XS256_112 "Cpu" init code ... */
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/*lint -restore Enable MISRA rule (1.1) checking. */

#pragma CODE_SEG __NEAR_SEG NON_BANKED

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S12XS256_112)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */
#pragma OPTION ADD "-Onf"              /* 'Create Sub-Functions with Common Code optimalization' must be disabled because stack is not yet initialized */

#pragma NO_FRAME                       /* Suppress generation of frame code */
#pragma NO_EXIT                        /* Suppress generation of exit from a function */
void _EntryPoint(void)
{
  /* ### MC9S12XS256_112 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* MMCCTL1: MGRAMON=0,??=0,DFIFRON=0,PGMIFRON=0,??=0,??=0,??=0,??=0 */
  setReg8(MMCCTL1, 0x00U);              
  /* DIRECT: DP15=0,DP14=0,DP13=0,DP12=0,DP11=0,DP10=0,DP9=0,DP8=0 */
  setReg8(DIRECT, 0x00U);               
  /* IVBR: IVB_ADDR=0xFF */
  setReg8(IVBR, 0xFFU);                 
  /* ECLKCTL: NECLK=0,NCLKX2=1,DIV16=0,EDIV4=0,EDIV3=0,EDIV2=0,EDIV1=0,EDIV0=0 */
  setReg8(ECLKCTL, 0x40U);              
  /*  System clock initialization */
  /* CLKSEL: PLLSEL=0,PSTP=0,XCLKS=0,??=0,PLLWAI=0,??=0,RTIWAI=0,COPWAI=0 */
  setReg8(CLKSEL, 0x00U);              /* Select clock source from XTAL and set bits in CLKSEL reg. */ 
  /* PLLCTL: CME=1,PLLON=0,FM1=0,FM0=0,FSTWKP=0,PRE=0,PCE=0,SCME=1 */
  setReg8(PLLCTL, 0x81U);              /* Disable the PLL */ 
  /* VREGHTCL: ??=0,??=0,VSEL=0,VAE=1,HTEN=0,HTDS=0,HTIE=0,HTIF=0 */
  setReg8(VREGHTCL, 0x10U);             
  /*** End of PE initialization code after reset ***/
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm("jmp _Startup");               /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

#pragma CODE_SEG DEFAULT
/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
