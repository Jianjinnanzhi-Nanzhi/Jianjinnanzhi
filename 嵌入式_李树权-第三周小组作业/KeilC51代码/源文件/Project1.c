#include <REGX52.H>
#include "Timer0.h"
#include "INTRINS.h"

void main()
{
   Timer0Init(); //定时器0的初始化
   P2=0xFE;   
	 P3_0=0;
	 while(1)
  {

  }
}

void Timer0_Routine() interrupt 1
{
  static unsigned int T0Count;
	TL0 = 0x18;
	TH0 = 0xFC;
	T0Count++;
	
	if(T0Count>=1000)//每一毫秒产生一次中断
	{
	   T0Count=0;
		P2=_crol_(P2,1); //流水灯配置
		P3_0=~P3_0;      //LED灯闪烁配置
	}
}