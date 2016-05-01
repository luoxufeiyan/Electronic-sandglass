/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Vectors.c
**     Project   : ZJA060
**     Processor : MC9S12XS128CAL
**     Version   : Component 01.003, Driver 02.06, CPU db: 3.00.020
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/5/1, 11:17
**     Abstract  :
**         This component "MC9S12XS256_112" implements properties, methods,
**         and events of the CPU.
**     Settings  :
**
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
#include "Cpu.h"

/* ISR prototype */
typedef void (*near tIsrFunc)(void);
/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
static const tIsrFunc _InterruptVectorTable[] @0xFF10U = { /* Interrupt vector table */
/*lint -restore Enable MISRA rule (1.1) checking. */
  /* ISR name                               No.  Address  Pri Name           Description */
  &Cpu_Interrupt,                       /* 0x08  0xFF10   -   ivVsi          unused by PE */
  &Cpu_Interrupt,                       /* 0x09  0xFF12   -   ivVsyscall     unused by PE */
  &Cpu_Interrupt,                       /* 0x0A  0xFF14   1   ivVReserved118 unused by PE */
  &Cpu_Interrupt,                       /* 0x0B  0xFF16   1   ivVReserved117 unused by PE */
  &Cpu_Interrupt,                       /* 0x0C  0xFF18   1   ivVReserved116 unused by PE */
  &Cpu_Interrupt,                       /* 0x0D  0xFF1A   1   ivVReserved115 unused by PE */
  &Cpu_Interrupt,                       /* 0x0E  0xFF1C   1   ivVReserved114 unused by PE */
  &Cpu_Interrupt,                       /* 0x0F  0xFF1E   1   ivVReserved113 unused by PE */
  &Cpu_Interrupt,                       /* 0x10  0xFF20   1   ivVReserved112 unused by PE */
  &Cpu_Interrupt,                       /* 0x11  0xFF22   1   ivVReserved111 unused by PE */
  &Cpu_Interrupt,                       /* 0x12  0xFF24   1   ivVReserved110 unused by PE */
  &Cpu_Interrupt,                       /* 0x13  0xFF26   1   ivVReserved109 unused by PE */
  &Cpu_Interrupt,                       /* 0x14  0xFF28   1   ivVReserved108 unused by PE */
  &Cpu_Interrupt,                       /* 0x15  0xFF2A   1   ivVReserved107 unused by PE */
  &Cpu_Interrupt,                       /* 0x16  0xFF2C   1   ivVReserved106 unused by PE */
  &Cpu_Interrupt,                       /* 0x17  0xFF2E   1   ivVReserved105 unused by PE */
  &Cpu_Interrupt,                       /* 0x18  0xFF30   1   ivVReserved104 unused by PE */
  &Cpu_Interrupt,                       /* 0x19  0xFF32   1   ivVReserved103 unused by PE */
  &Cpu_Interrupt,                       /* 0x1A  0xFF34   1   ivVReserved102 unused by PE */
  &Cpu_Interrupt,                       /* 0x1B  0xFF36   1   ivVReserved101 unused by PE */
  &Cpu_Interrupt,                       /* 0x1C  0xFF38   1   ivVReserved100 unused by PE */
  &Cpu_Interrupt,                       /* 0x1D  0xFF3A   1   ivVReserved99  unused by PE */
  &Cpu_Interrupt,                       /* 0x1E  0xFF3C   1   ivVReserved98  unused by PE */
  &Cpu_Interrupt,                       /* 0x1F  0xFF3E   1   ivVatd0compare unused by PE */
  &Cpu_Interrupt,                       /* 0x20  0xFF40   1   ivVReserved96  unused by PE */
  &Cpu_Interrupt,                       /* 0x21  0xFF42   1   ivVReserved95  unused by PE */
  &Cpu_Interrupt,                       /* 0x22  0xFF44   1   ivVReserved94  unused by PE */
  &Cpu_Interrupt,                       /* 0x23  0xFF46   1   ivVReserved93  unused by PE */
  &Cpu_Interrupt,                       /* 0x24  0xFF48   1   ivVReserved92  unused by PE */
  &Cpu_Interrupt,                       /* 0x25  0xFF4A   1   ivVReserved91  unused by PE */
  &Cpu_Interrupt,                       /* 0x26  0xFF4C   1   ivVReserved90  unused by PE */
  &Cpu_Interrupt,                       /* 0x27  0xFF4E   1   ivVReserved89  unused by PE */
  &Cpu_Interrupt,                       /* 0x28  0xFF50   1   ivVReserved88  unused by PE */
  &Cpu_Interrupt,                       /* 0x29  0xFF52   1   ivVReserved87  unused by PE */
  &Cpu_Interrupt,                       /* 0x2A  0xFF54   1   ivVReserved86  unused by PE */
  &Cpu_Interrupt,                       /* 0x2B  0xFF56   1   ivVReserved85  unused by PE */
  &Cpu_Interrupt,                       /* 0x2C  0xFF58   1   ivVReserved84  unused by PE */
  &Cpu_Interrupt,                       /* 0x2D  0xFF5A   1   ivVReserved83  unused by PE */
  &Cpu_Interrupt,                       /* 0x2E  0xFF5C   1   ivVReserved82  unused by PE */
  &Cpu_Interrupt,                       /* 0x2F  0xFF5E   1   ivVReserved81  unused by PE */
  &Cpu_Interrupt,                       /* 0x30  0xFF60   1   ivVReserved79  unused by PE */
  &Cpu_Interrupt,                       /* 0x31  0xFF62   1   ivVReserved78  unused by PE */
  &Cpu_Interrupt,                       /* 0x32  0xFF64   1   ivVReserved77  unused by PE */
  &Cpu_Interrupt,                       /* 0x33  0xFF66   1   ivVReserved76  unused by PE */
  &Cpu_Interrupt,                       /* 0x34  0xFF68   1   ivVReserved75  unused by PE */
  &Cpu_Interrupt,                       /* 0x35  0xFF6A   1   ivVReserved74  unused by PE */
  &Cpu_Interrupt,                       /* 0x36  0xFF6C   1   ivVReserved73  unused by PE */
  &Cpu_Interrupt,                       /* 0x37  0xFF6E   1   ivVReserved72  unused by PE */
  &Cpu_Interrupt,                       /* 0x38  0xFF70   1   ivVReserved71  unused by PE */
  &Cpu_Interrupt,                       /* 0x39  0xFF72   1   ivVReserved70  unused by PE */
  &Cpu_Interrupt,                       /* 0x3A  0xFF74   1   ivVpit3        unused by PE */
  &Cpu_Interrupt,                       /* 0x3B  0xFF76   1   ivVpit2        unused by PE */
  &Cpu_Interrupt,                       /* 0x3C  0xFF78   1   ivVpit1        unused by PE */
  &Cpu_Interrupt,                       /* 0x3D  0xFF7A   1   ivVpit0        unused by PE */
  &Cpu_Interrupt,                       /* 0x3E  0xFF7C   1   ivVhti         unused by PE */
  &Cpu_Interrupt,                       /* 0x3F  0xFF7E   1   ivVapi         unused by PE */
  &Cpu_Interrupt,                       /* 0x40  0xFF80   1   ivVlvi         unused by PE */
  &Cpu_Interrupt,                       /* 0x41  0xFF82   1   ivVReserved62  unused by PE */
  &Cpu_Interrupt,                       /* 0x42  0xFF84   1   ivVReserved61  unused by PE */
  &Cpu_Interrupt,                       /* 0x43  0xFF86   1   ivVReserved60  unused by PE */
  &Cpu_Interrupt,                       /* 0x44  0xFF88   1   ivVReserved59  unused by PE */
  &Cpu_Interrupt,                       /* 0x45  0xFF8A   1   ivVReserved58  unused by PE */
  &Cpu_Interrupt,                       /* 0x46  0xFF8C   1   ivVpwmesdn     unused by PE */
  &Cpu_Interrupt,                       /* 0x47  0xFF8E   1   ivVportp       unused by PE */
  &Cpu_Interrupt,                       /* 0x48  0xFF90   1   ivVReserved55  unused by PE */
  &Cpu_Interrupt,                       /* 0x49  0xFF92   1   ivVReserved54  unused by PE */
  &Cpu_Interrupt,                       /* 0x4A  0xFF94   1   ivVReserved53  unused by PE */
  &Cpu_Interrupt,                       /* 0x4B  0xFF96   1   ivVReserved52  unused by PE */
  &Cpu_Interrupt,                       /* 0x4C  0xFF98   1   ivVReserved51  unused by PE */
  &Cpu_Interrupt,                       /* 0x4D  0xFF9A   1   ivVReserved50  unused by PE */
  &Cpu_Interrupt,                       /* 0x4E  0xFF9C   1   ivVReserved49  unused by PE */
  &Cpu_Interrupt,                       /* 0x4F  0xFF9E   1   ivVReserved48  unused by PE */
  &Cpu_Interrupt,                       /* 0x50  0xFFA0   1   ivVReserved47  unused by PE */
  &Cpu_Interrupt,                       /* 0x51  0xFFA2   1   ivVReserved46  unused by PE */
  &Cpu_Interrupt,                       /* 0x52  0xFFA4   1   ivVReserved45  unused by PE */
  &Cpu_Interrupt,                       /* 0x53  0xFFA6   1   ivVReserved44  unused by PE */
  &Cpu_Interrupt,                       /* 0x54  0xFFA8   1   ivVReserved43  unused by PE */
  &Cpu_Interrupt,                       /* 0x55  0xFFAA   1   ivVReserved42  unused by PE */
  &Cpu_Interrupt,                       /* 0x56  0xFFAC   1   ivVReserved41  unused by PE */
  &Cpu_Interrupt,                       /* 0x57  0xFFAE   1   ivVReserved40  unused by PE */
  &Cpu_Interrupt,                       /* 0x58  0xFFB0   1   ivVcan0tx      unused by PE */
  &Cpu_Interrupt,                       /* 0x59  0xFFB2   1   ivVcan0rx      unused by PE */
  &Cpu_Interrupt,                       /* 0x5A  0xFFB4   1   ivVcan0err     unused by PE */
  &Cpu_Interrupt,                       /* 0x5B  0xFFB6   1   ivVcan0wkup    unused by PE */
  &Cpu_Interrupt,                       /* 0x5C  0xFFB8   1   ivVflash       unused by PE */
  &Cpu_Interrupt,                       /* 0x5D  0xFFBA   1   ivVflashfd     unused by PE */
  &Cpu_Interrupt,                       /* 0x5E  0xFFBC   1   ivVReserved33  unused by PE */
  &Cpu_Interrupt,                       /* 0x5F  0xFFBE   1   ivVReserved32  unused by PE */
  &Cpu_Interrupt,                       /* 0x60  0xFFC0   1   ivVReserved31  unused by PE */
  &Cpu_Interrupt,                       /* 0x61  0xFFC2   1   ivVReserved30  unused by PE */
  &Cpu_Interrupt,                       /* 0x62  0xFFC4   1   ivVcrgscm      unused by PE */
  &Cpu_Interrupt,                       /* 0x63  0xFFC6   1   ivVcrgplllck   unused by PE */
  &Cpu_Interrupt,                       /* 0x64  0xFFC8   1   ivVReserved27  unused by PE */
  &Cpu_Interrupt,                       /* 0x65  0xFFCA   1   ivVReserved26  unused by PE */
  &Cpu_Interrupt,                       /* 0x66  0xFFCC   1   ivVporth       unused by PE */
  &Cpu_Interrupt,                       /* 0x67  0xFFCE   1   ivVportj       unused by PE */
  &Cpu_Interrupt,                       /* 0x68  0xFFD0   1   ivVReserved23  unused by PE */
  &Cpu_Interrupt,                       /* 0x69  0xFFD2   1   ivVatd0        unused by PE */
  &Cpu_Interrupt,                       /* 0x6A  0xFFD4   1   ivVsci1        unused by PE */
  &Cpu_Interrupt,                       /* 0x6B  0xFFD6   1   ivVsci0        unused by PE */
  &Cpu_Interrupt,                       /* 0x6C  0xFFD8   1   ivVspi0        unused by PE */
  &Cpu_Interrupt,                       /* 0x6D  0xFFDA   1   ivVtimpaie     unused by PE */
  &Cpu_Interrupt,                       /* 0x6E  0xFFDC   1   ivVtimpaaovf   unused by PE */
  &Cpu_Interrupt,                       /* 0x6F  0xFFDE   1   ivVtimovf      unused by PE */
  &Cpu_Interrupt,                       /* 0x70  0xFFE0   1   ivVtimch7      unused by PE */
  &Cpu_Interrupt,                       /* 0x71  0xFFE2   1   ivVtimch6      unused by PE */
  &Cpu_Interrupt,                       /* 0x72  0xFFE4   1   ivVtimch5      unused by PE */
  &Cpu_Interrupt,                       /* 0x73  0xFFE6   1   ivVtimch4      unused by PE */
  &Cpu_Interrupt,                       /* 0x74  0xFFE8   1   ivVtimch3      unused by PE */
  &Cpu_Interrupt,                       /* 0x75  0xFFEA   1   ivVtimch2      unused by PE */
  &Cpu_Interrupt,                       /* 0x76  0xFFEC   1   ivVtimch1      unused by PE */
  &Cpu_Interrupt,                       /* 0x77  0xFFEE   1   ivVtimch0      unused by PE */
  &Cpu_Interrupt,                       /* 0x78  0xFFF0   1   ivVrti         unused by PE */
  &Cpu_Interrupt,                       /* 0x79  0xFFF2   1   ivVirq         unused by PE */
  &Cpu_Interrupt,                       /* 0x7A  0xFFF4   -   ivVxirq        unused by PE */
  &Cpu_Interrupt,                       /* 0x7B  0xFFF6   -   ivVswi         unused by PE */
  &Cpu_Interrupt                        /* 0x7C  0xFFF8   -   ivVtrap        unused by PE */
};

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
static const tIsrFunc _ResetVectorTable[] @0xFFFAU = { /* Reset vector table */
/*lint -restore Enable MISRA rule (1.1) checking. */
  /* Reset handler name                    Address Name            Description */
  &_EntryPoint,                         /* 0xFFFA  ivVcop          unused by PE */
  &_EntryPoint,                         /* 0xFFFC  ivVclkmon       unused by PE */
  &_EntryPoint                          /* 0xFFFE  ivVreset        used by PE */
};
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
