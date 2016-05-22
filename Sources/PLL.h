#ifndef  PLL_h  
#define  PLL_h

#include <MC9S12XS128.h>

/**********************************************************************
选择SYNR_SET的值，设置总线频率，计算公式（SYNR_SET+1）*16M/（REFDV+1�
这里REFDV = 1;
**********************************************************************/

#define SYNR_SET   0x02    
                        //0x02-----24M总线频率
                        //0x43-----32M总线频率
                        //0x44-----40M总线频率
                        //0xc5-----48M总线频率
                        //0xc6-----56M总线频率
                        //0xc7-----64M总线频率
                        //0xc8-----72M总线频率
                        //0xc9-----80M总线频率
                        //0xca-----88M总线频率
                        //0xcb-----96M总线频率
                        
                        //0xcc-----104M总线频率
                        //0xcd-----112M总线频率
                        //0xce-----120M总线频率
/*==================================================================*/
void PLL_init(void);

#endif
