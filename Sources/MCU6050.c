#include"includes.h"

void I2C_Init() 
{
    SCL=1;
    delayus(5);
    SDA=1;
    delayus(5);
}
//**************************************
//I2C起始信号
//**************************************
void I2C_Start()
{
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                    //拉高数据线
    SCL = 1;                    //拉高时钟线
    delayus(10);                 //延时
    SDA = 0;                    //产生下降沿
    delayus(10);                 //延时
    SCL = 0;                    //拉低时钟线
}
//**************************************
//I2C停止信号
//**************************************
void I2C_Stop()
{
    SDAIO=1;
    SCLIO=1;
    SDA = 0;                    //拉低数据线
    SCL = 1;                    //拉高时钟线
    delayus(10);                 //延时
    SDA = 1;                    //产生上升沿
   delayus(10);                 //延时
}
//**************************************
//I2C发送应答信号
//入口参数:ack (0:ACK 1:NAK)
//**************************************
void I2C_SendACK()
{
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                  //写应答信号
    SCL = 1;                    //拉高时钟线
   delayus(10);                 //延时
    SCL = 0;                    //拉低时钟线
   delayus(10);                 //延时
}
//**************************************
//I2C接收应答信号
//**************************************
void I2C_RecvACK()
{
   uint errtime=4200;  
    SDAIO=0;
    SCLIO=1;
    SCL=1; 
    delayus(10);  
    SCL=0;
    delayus(10);

}
//**************************************
//向I2C总线发送一个字节数据
//**************************************
void I2C_SendByte(uchar dat)
{
    uchar i;
    SDAIO=1;
    SCLIO=1;
    for (i=0; i<8; i++)         //8位计数器
    {
        if(dat&0x80)
        SDA = 1;               //送数据口
        else
        SDA = 0;
        dat <<= 1;              //移出数据的最高位
        SCL = 1;                //拉高时钟线
       delayus(10);                 //延时
        SCL = 0;                //拉低时钟线
       delayus(10);                 //延时
    }
    I2C_RecvACK();
}
//**************************************
//从I2C总线接收一个字节数据
//**************************************
uchar I2C_RecvByte()
{
    uchar i;
    uchar dat = 0;
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                    //使能内部上拉,准备读取数据,
    SDAIO=0;
    for (i=0; i<8; i++)         //8位计数器
    {
        dat <<= 1;
        SCL = 1;                //拉高时钟线
   delayus(10);                 //延时
        dat |= SDA;             //读数据               
        SCL = 0;                //拉低时钟线
   delayus(10);                 //延时
    }
    return dat;
}
//**************************************
//向I2C设备写入一个字节数据
//**************************************
void Single_WriteI2C(uchar REG_Address,uchar REG_data)
{
    I2C_Start();                  //起始信号
    I2C_SendByte(SlaveAddress);   //发送设备地址+写信号
    I2C_SendByte(REG_Address);    //内部寄存器地址，
    I2C_SendByte(REG_data);       //内部寄存器数据，
    I2C_Stop();                   //发送停止信号
}
//**************************************
//从I2C设备读取一个字节数据
//**************************************
uchar Single_ReadI2C(uchar REG_Address)
{
	uchar REG_data;
	I2C_Start();                   //起始信号
	I2C_SendByte(SlaveAddress);    //发送设备地址+写信号
	I2C_SendByte(REG_Address);     //发送存储单元地址，从0开始	
	I2C_Start();                   //起始信号
	I2C_SendByte(SlaveAddress+1);  //发送设备地址+读信号
	REG_data=I2C_RecvByte();       //读出寄存器数据
	I2C_SendACK();                //接收应答信号
	I2C_Stop();                    //停止信号
	return REG_data;
}
//**************************************
//初始化MPU6050
//**************************************
void InitMPU6050()
{
	Single_WriteI2C(PWR_MGMT_1, 0x00);	//解除休眠状态
	Single_WriteI2C(SMPLRT_DIV, 0x07);
	Single_WriteI2C(CONFIG, 0x06);
	Single_WriteI2C(GYRO_CONFIG, 0x18);
	Single_WriteI2C(ACCEL_CONFIG, 0x01);
}
//**************************************
//合成数据
//**************************************
int GetData(uchar REG_Address)
{
	char H,L;
	H=Single_ReadI2C(REG_Address);
	L=Single_ReadI2C(REG_Address+1);
	return (H<<8)+L;   //合成数据
}
//**************************************
//得到角度
//dir要得到的角度返回角度值1°
//**************************************
int MPU6050_GetAngle(float x, float y,float z,uint dir)
{
  float temp;
  float res = 0;
  switch(dir) {
    case 0:     //Z轴角度
      temp = sqrt((x*x+y*y))/z;
      res = atan(temp);
      break;
    case 1:     //X轴角度
      temp = x/sqrt((y*y+z*z));
      res = atan(temp);
      break;
    case 2:     //Y轴角度
      temp = y/sqrt((x*x+z*z));
      res = atan(temp);
      break;
  }
  return res*180/3.14;
}