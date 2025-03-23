#include "ConvenientCALC.h"

int main()
{
	printf("\n");
	printf("     *************************            *************************\n");
	printf("     *               欢迎使用四则运算表达式求值计算器             *\n");
	printf("     * 请遵循以下原则:                                            *\n");
	printf("     *     1.本计算器只能进行一位数运算                           *\n");
	printf("     *     2.不支持小数,负数,复数,只支持正整数                    *\n");
	printf("     *     3.进行除法运算时要考虑是否整除的情况                   *\n");
	printf("     *     4.表达式不得超过100个字符                              *\n");
	printf("     *     5.请确保你的表达式没有出错                             *\n");
	printf("     *************************            *************************\n");
	LinkStack s = initStack();
	char* expr = (char*)malloc(sizeof(expr));//存储输入的中缀表达式
	printf("请输入要计算的运算表达式 : ");
	scanf("%s", expr);
	fstack* fs = initfstack();//以类似栈的形式存储转化后的后缀表达式
	printf("\n");
	postfix(s, expr, fs);
	printf("该表达式的后缀表达式为 : ");
	print_fstack(fs);
	clearStack(s);//确保该栈已清空,不影响后缀求值的使用
	int result = 0;//用来存储计算结果
	eval(s, fs,&result);
	printf("计算结果为 : %d", result);
	printf("\n");
	free(expr);
	system("pause");
	return 0;
}