#ifndef _SPI_H_
#define _SPI_H_

/**
  * @brief SPI的初始化(模式0)
  * @param  None
  * @retval  None
  */
void SPI_Init();

/**
  * @brief 主机发送数据
  * @param  dat(要发送的数据)
  * @retval  None
  */
void Master_Send_Byte(unsigned char dat);

/**
  * @brief 主机接收数据
  * @param  None
  * @retval  主机要接收的数据
  */
unsigned char Master_Receive_Byte(void);

/**
  * @brief 从机发送数据
  * @param  dat(从机要发送的数据)
  * @retval  None
  */
void Slave_Send_Byte(unsigned char dat);

/**
  * @brief 从机接收数据
  * @param  None
  * @retval  从机要接收的数据
  */
unsigned char Slave_Receive_Byte(void); 
#endif