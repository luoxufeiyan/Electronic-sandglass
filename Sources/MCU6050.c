#include"includes.h"

void I2C_Init() 
{
    SCL=1;
    delayus(5);
    SDA=1;
    delayus(5);
}
//**************************************
//I2C��ʼ�ź�
//**************************************
void I2C_Start()
{
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                    //����������
    SCL = 1;                    //����ʱ����
    delayus(10);                 //��ʱ
    SDA = 0;                    //�����½���
    delayus(10);                 //��ʱ
    SCL = 0;                    //����ʱ����
}
//**************************************
//I2Cֹͣ�ź�
//**************************************
void I2C_Stop()
{
    SDAIO=1;
    SCLIO=1;
    SDA = 0;                    //����������
    SCL = 1;                    //����ʱ����
    delayus(10);                 //��ʱ
    SDA = 1;                    //����������
   delayus(10);                 //��ʱ
}
//**************************************
//I2C����Ӧ���ź�
//��ڲ���:ack (0:ACK 1:NAK)
//**************************************
void I2C_SendACK()
{
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                  //дӦ���ź�
    SCL = 1;                    //����ʱ����
   delayus(10);                 //��ʱ
    SCL = 0;                    //����ʱ����
   delayus(10);                 //��ʱ
}
//**************************************
//I2C����Ӧ���ź�
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
//��I2C���߷���һ���ֽ�����
//**************************************
void I2C_SendByte(uchar dat)
{
    uchar i;
    SDAIO=1;
    SCLIO=1;
    for (i=0; i<8; i++)         //8λ������
    {
        if(dat&0x80)
        SDA = 1;               //�����ݿ�
        else
        SDA = 0;
        dat <<= 1;              //�Ƴ����ݵ����λ
        SCL = 1;                //����ʱ����
       delayus(10);                 //��ʱ
        SCL = 0;                //����ʱ����
       delayus(10);                 //��ʱ
    }
    I2C_RecvACK();
}
//**************************************
//��I2C���߽���һ���ֽ�����
//**************************************
uchar I2C_RecvByte()
{
    uchar i;
    uchar dat = 0;
    SDAIO=1;
    SCLIO=1;
    SDA = 1;                    //ʹ���ڲ�����,׼����ȡ����,
    SDAIO=0;
    for (i=0; i<8; i++)         //8λ������
    {
        dat <<= 1;
        SCL = 1;                //����ʱ����
   delayus(10);                 //��ʱ
        dat |= SDA;             //������               
        SCL = 0;                //����ʱ����
   delayus(10);                 //��ʱ
    }
    return dat;
}
//**************************************
//��I2C�豸д��һ���ֽ�����
//**************************************
void Single_WriteI2C(uchar REG_Address,uchar REG_data)
{
    I2C_Start();                  //��ʼ�ź�
    I2C_SendByte(SlaveAddress);   //�����豸��ַ+д�ź�
    I2C_SendByte(REG_Address);    //�ڲ��Ĵ�����ַ��
    I2C_SendByte(REG_data);       //�ڲ��Ĵ������ݣ�
    I2C_Stop();                   //����ֹͣ�ź�
}
//**************************************
//��I2C�豸��ȡһ���ֽ�����
//**************************************
uchar Single_ReadI2C(uchar REG_Address)
{
	uchar REG_data;
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(SlaveAddress);    //�����豸��ַ+д�ź�
	I2C_SendByte(REG_Address);     //���ʹ洢��Ԫ��ַ����0��ʼ	
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(SlaveAddress+1);  //�����豸��ַ+���ź�
	REG_data=I2C_RecvByte();       //�����Ĵ�������
	I2C_SendACK();                //����Ӧ���ź�
	I2C_Stop();                    //ֹͣ�ź�
	return REG_data;
}
//**************************************
//��ʼ��MPU6050
//**************************************
void InitMPU6050()
{
	Single_WriteI2C(PWR_MGMT_1, 0x00);	//�������״̬
	Single_WriteI2C(SMPLRT_DIV, 0x07);
	Single_WriteI2C(CONFIG, 0x06);
	Single_WriteI2C(GYRO_CONFIG, 0x18);
	Single_WriteI2C(ACCEL_CONFIG, 0x01);
}
//**************************************
//�ϳ�����
//**************************************
int GetData(uchar REG_Address)
{
	char H,L;
	H=Single_ReadI2C(REG_Address);
	L=Single_ReadI2C(REG_Address+1);
	return (H<<8)+L;   //�ϳ�����
}
//**************************************
//�õ��Ƕ�
//dirҪ�õ��ĽǶȷ��ؽǶ�ֵ1��
//**************************************
int MPU6050_GetAngle(float x, float y,float z,uint dir)
{
  float temp;
  float res = 0;
  switch(dir) {
    case 0:     //Z��Ƕ�
      temp = sqrt((x*x+y*y))/z;
      res = atan(temp);
      break;
    case 1:     //X��Ƕ�
      temp = x/sqrt((y*y+z*z));
      res = atan(temp);
      break;
    case 2:     //Y��Ƕ�
      temp = y/sqrt((x*x+z*z));
      res = atan(temp);
      break;
  }
  return res*180/3.14;
}