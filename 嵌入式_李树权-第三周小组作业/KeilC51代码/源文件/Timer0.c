#include <REGX52.H>

/**
  * @brief 定时器0的初始化
  * @param  None
  * @retval  None
  */
void Timer0Init(void)		//1毫秒  @12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	ET0 = 1;     //打开定时器0的中断
	EA = 1;      //打开总中断开关
	PT0 = 0;     //优先级配置
}


/**
  * @brief  定时器中断函数模板
  * @param  None
  * @retval  None
  */
//void Timer0_Routine() interrupt 1
//{
//  
//	
//}