#ifndef _IIC_H_
#define _IIC_H_

/**
  * @brief I2C开始
  * @param  None
  * @retval  None
  */
void I2C_Start(void);

/**
  * @brief  I2C结束
  * @param  None
  * @retval  None
  */
void I2C_Stop(void);

/**
  * @brief I2C发送一个字节
  * @param  Byte(要发送的一个字节)
  * @retval  None
  */
void I2C_SendByte(unsigned char Byte);
	
/**
  * @brief I2C接收一个字节
  * @param  None
  * @retval  接收到的一个字节数据
  */
unsigned char I2C_ReceiveByte(void);
		
/**
  * @brief I2C发送应答
  * @param  AckBit(应答位,0表示应答,1表示非应答)
  * @retval  None
 */
void I2C_SendAck(unsigned char AckBit);

/**
  * @brief I2C接收应答
  * @param  None
  * @retval  接收到的应答位(0表示应答,1表示非应答)
  */	
unsigned char I2C_ReceiveAck(void);
#endif