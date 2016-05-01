#ifndef _MCU6050_H_
#define _MCU6050_H_




#define SCL PORTB_PB0  		
#define SDA PORTB_PB1		 

#define SCLIO DDRB_DDRB0
#define SDAIO DDRB_DDRB1




#define	SMPLRT_DIV		0x19
#define	CONFIG		    0x06
#define	GYRO_CONFIG		0x1B
#define	ACCEL_CONFIG	0x1C
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B
#define	WHO_AM_I			0x75
#define	SlaveAddress	 0xD0

void  InitMPU6050(void);											    		   
void  I2C_Init(void); 
void  I2C_Start(void);
void  I2C_Stop(void);
void  I2C_SendACK(void);
void  I2C_RecvACK(void);
void  I2C_SendByte(uchar dat);
uchar I2C_RecvByte(void);
uchar Single_ReadI2C(uchar REG_Address);				      	
void  Single_WriteI2C(uchar REG_Address,uchar REG_data);
int   GetData(uchar REG_Address);
void delayus(uint8 x);

#endif 
