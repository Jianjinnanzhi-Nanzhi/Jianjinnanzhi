#include <REGX52.H>
#include "Delay.h"
#include "UART.h"


void main()
{
	 UART_Init();
  
	while(1)
  {
    UART_SendString("Helloword!");
		UART_SendNewLine();//回车换行
		Delay(1000);//延时1秒
  }
}

