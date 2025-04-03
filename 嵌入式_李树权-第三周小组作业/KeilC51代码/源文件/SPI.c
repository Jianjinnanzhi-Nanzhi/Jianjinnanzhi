#include <REGX52.H>
#include <INTRINS.h>


sbit CLK =P1^0;    //时钟信号
sbit MOSI=P1^1;    //主发从接
sbit MISO=P1^2;    //主接从发
sbit SS  =P1^3;    //片选（使能）信号

void SPI_Init()
{
    SS = 1;    // 初始不选中从机
    CLK = 0;    // 时钟初始低电平
    MOSI = 0;   // MOSI初始低电平
}//SPI模式0的初始化

void Master_Send_Byte(unsigned char dat) //发送数据程序
{
  unsigned char i;
    SS = 0;                     // 选中从机
    
   for(i = 0; i < 8; i++) 
	 {
        MOSI = (dat & 0x80) ? 1 : 0;  // 输出最高位
        dat <<= 1;                    // 左移准备下一位       
        CLK = 1;                // 上升沿（从机采样MOSI）
        _nop_();                       
		    CLK = 0;                // 下降沿
        _nop_();                
   }
    SS = 1;                     // 释放从机   
}

unsigned char Master_Receive_Byte(void)
{
 unsigned char i,dat=0;
	 SS = 0;                     // 选中从机
    
   for(i = 0; i < 8; i++) 
	 {
      CLK = 1;                // 上升沿
      _nop_();                // 短暂延时
        
      dat <<= 1;              // 左移腾出最低位
      if(MISO) dat |= 0x01;   // 采样MISO
        
      CLK = 0;                // 下降沿
      _nop_();                // 时钟低电平保持时间
   }    
   SS = 1;                     // 释放从机
	return dat;
}



void Slave_Send_Byte(unsigned char dat) 
{
    unsigned char i;
    while(SS);  //等待SS拉低
    
   for(i = 0; i < 8; i++) 
	 {
        if(dat & 0x80) MISO = 1;  // 在时钟上升沿前准备好数据
        else MISO = 0;
        dat <<= 1;
        
        while(!CLK);  // 等待上升沿(主机准备采样)
        while(CLK);   // 等待下降沿
    }
    
    while(!SS);  //等待SS拉高
}


unsigned char Slave_Receive_Byte(void) 
{
    unsigned char i, dat = 0;
    while(SS);  //等待SS拉低
    
    for(i = 0; i < 8; i++)
  	{
        while(!CLK);  // 等待上升沿(主机输出数据)
        
        // 在上升沿采样MOSI
        dat <<= 1;
        if(MOSI) dat |= 0x01;
        
        while(CLK);   // 等待下降沿
    }
    
    while(!SS);  //等待SS拉高
    return dat;
}