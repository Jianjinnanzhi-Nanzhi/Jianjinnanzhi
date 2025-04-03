#include <REGX52.H>

/**
  * @brief  软件延时函数(@12.000MHz)
  * @param   xms(毫秒)
  * @retval  None
  */
void Delay(unsigned int xms)		
{
	unsigned char i, j;

	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

