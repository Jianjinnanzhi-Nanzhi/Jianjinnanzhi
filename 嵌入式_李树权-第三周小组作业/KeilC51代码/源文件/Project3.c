#include <REGX52.H>
#include "UART.h"
#include "Nixie.h"

void main()
{
	 UART_Init();
  
	while(1)
  {
		
  }
}

void UART_Rountine() interrupt 4
{
  if(RI==1)
	{
	 ShowNum(SBUF);
	 RI=0;
	}
}