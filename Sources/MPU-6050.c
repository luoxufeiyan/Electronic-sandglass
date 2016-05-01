#include"includes.h"

void delayus(uint8 x)
{
  uchar i,j;
  for(i=110;i>0;i--)
    for(j=x;j>0;j--);
}


void I2C_Init() 
{
    SCL=1;
    delayus(5);
    SDA=1;
    delayus(5);
}

void I2C_Start()
{
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                   
    SCL = 1;                   
    delayus(10);               
    SDA = 0;                   
    delayus(10);               
    SCL = 0;                   
}

void I2C_Stop()
{
    SDAIO=1;
    SCLIO=1;
    SDA = 0;                   
    SCL = 1;                
    delayus(10);          
    SDA = 1;                  
    delayus(10);         
}

void I2C_SendACK()
{   
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                    
    SCL = 1;                    
    delayus(10);               
    SCL = 0;                    
    delayus(10);             
}


void I2C_RecvACK()
{
     
    SDAIO=0;
    SCLIO=1;
    SCL=1; 
    delayus(10);  
    SCL=0;
    delayus(10);

}


void I2C_SendByte(uchar dat)
{
    uchar i;
    SDAIO=1;
    SCLIO=1;
    for (i=0; i<8; i++)         
    {
        if(dat&0x80)
        SDA = 1;                
        else
        SDA = 0;
        dat <<= 1;              
        SCL = 1;                
        delayus(10);           
        SCL = 0;               
        delayus(10);         
    }
    I2C_RecvACK();
}

uchar I2C_RecvByte()
{
    uchar i;
    uchar dat = 0;
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                  
    SDAIO=0;
    for (i=0; i<8; i++)         
    {
        dat <<= 1;
        SCL = 1;               
        delayus(10);          
        dat |= SDA;                     
        SCL = 0;          
        delayus(10);       
    }
    return dat;
}

void Single_WriteI2C(uchar REG_Address,uchar REG_data)
{
    I2C_Start();                  
    I2C_SendByte(SlaveAddress);   
    I2C_SendByte(REG_Address);  
    I2C_SendByte(REG_data);   
    I2C_Stop();              
}

uchar Single_ReadI2C(uchar REG_Address)
{
	uchar REG_data;
	I2C_Start();                  
	I2C_SendByte(SlaveAddress);    
	I2C_SendByte(REG_Address);    	
	I2C_Start();                   
	I2C_SendByte(SlaveAddress+1); 
	REG_data=I2C_RecvByte();      
	I2C_SendACK();               
	I2C_Stop();               
	return REG_data;
}

void InitMPU6050()                    
{
  int i=0, j=0;                      
   for(i=0;i<1000;i++)                
    for(j=0;j<1000;j++);
	Single_WriteI2C(PWR_MGMT_1, 0x00);	
	Single_WriteI2C(SMPLRT_DIV, 0x07);  
	Single_WriteI2C(CONFIG, 0x06);      
	Single_WriteI2C(GYRO_CONFIG, 0x18);  
	Single_WriteI2C(ACCEL_CONFIG, 0x01);
}

//合成数据
//**************************************
int GetData(uchar REG_Address)
{
	char H,L;
	H=Single_ReadI2C(REG_Address);
	L=Single_ReadI2C(REG_Address+1);
	return (H<<8)+L;                      //合成数据
} 