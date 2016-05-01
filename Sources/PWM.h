#ifndef  PWM_H
#define  PWM_H

#define  pwmclk_pclk00   0     
#define  pwmprclk_pcka0  3     
#define  pwmscla0        16     
#define  pwmper0         250    
#define  pwmdty0         0     

#define  pwmclk_pclk11   0     
#define  pwmprclk_pcka1  3     
#define  pwmscla1        16     
#define  pwmper1         250   
#define  pwmdty1         0   
#define  pwmclk_pclk22   0      
#define  pwmprclk_pckb2  3     
#define  pwmsclb2        16     
#define  pwmper2         250   
#define  pwmdty2         0    
#define  pwmclk_pclk33   0     
#define  pwmprclk_pckb3  3     
#define  pwmsclb3        16      
#define  pwmper3         250    
#define  pwmdty3         0      
#define  pwmclk_pclk44   0     
#define  pwmprclk_pcka4  3     
#define  pwmscla4        16     
#define  pwmper4         250  
#define  pwmdty4       0   
#define  pwmclk_pclk55   1     
#define  pwmprclk_pcka5  0      
#define  pwmscla5        8      
#define  pwmper5         250   
#define  pwmclk_pclk66   0     
#define  pwmprclk_pckb6  0     
#define  pwmsclb6        8      
#define  pwmper6         250   
#define  pwmclk_pclk77   0     
#define  pwmprclk_pckb7  0     
#define  pwmsclb7        8      
#define  pwmper7         250    
#define  pwmclk_pclk01    1     
#define  pwmprclk_pcka01  3     
#define  pwmscla01        1                                                           
#define  pwmper01         50000  
#define  pwmdty01         0   
#define  pwmclk_pclk23    1      
#define  pwmprclk_pckb23  3     
#define  pwmsclb23        1                                                            
#define  pwmper23         50000 
#define  pwmdty23         0 
#define  pwmclk_pclk45    1    
#define  pwmprclk_pcka45  3     
#define  pwmscla45        1                                                         
#define  pwmper45         50000  
#define  pwmdty45         0     
#define  pwmclk_pclk67    1      
#define  pwmprclk_pckb67  3      
#define  pwmsclb67        1                                                            
#define  pwmper67         50000 
#define  pwmdty67         0     

void Pwm0_Init(void);
void Pwm1_Init(void);
void Pwm2_Init(void);
void Pwm3_Init(void);
void Pwm4_Init(void);
void Pwm5_Init(void);
void Pwm6_Init(void);
void Pwm7_Init(void);


void Pwm01_Init(void);
void Pwm23_Init(void);
void Pwm45_Init(void);
void Pwm67_Init(void);


             

void Delay(void);

#endif





             






































