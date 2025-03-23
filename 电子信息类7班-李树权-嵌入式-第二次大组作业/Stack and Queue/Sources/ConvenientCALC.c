#include "ConvenientCALC.h"

fstack* initfstack()
{
	fstack* fs = (fstack*)malloc(sizeof(fstack));
	fs->top = -1;
	return fs;
}//初始化顺序栈(用来储存后缀表达式)

void print_fstack(fstack* fs)
{
	size_t n = strlen(fs->arr);
	for (int i = 0; i < n; i++)
	{
		printf("%c", fs->arr[i]);
	}
	printf("\n");
}//以入栈的方式打印顺序栈中的元素(打印后缀表达式)


contentType getToken(char* symbol, int index,char expr[])
{
	*symbol = expr[index];
	switch (*symbol)
	{
	case'(':
		return LEFT_PARE;
	case')':
		return RIGHT_PARE;
	case'+':
		return ADD;
	case'-':
		return SUB;
	case'*':
		return MUL;
	case'/':
		return DIV;
	case'%':
		return MOD;
	case'\0':
		return EOS;
	default:
		return NUM;
	}
}//读取表达式中的符号,转化为数字0-8,利于储存在链栈中

int Diliever_token(ElemType e,fstack* fs)
{
	switch (e)
	{
	case ADD:
		fs->arr[++fs->top] = '+';
		break;
	case SUB:
		fs->arr[++fs->top] = '-';
		break;
	case MUL:
		fs->arr[++fs->top] = '*';
		break;
	case DIV:
		fs->arr[++fs->top] = '/';
		break;
	case MOD:
		fs->arr[++fs->top] = '%';
		break;
	default:
		return 0;
	}
	return 1;
}//将获取到的元素储存到顺序栈(储存后缀表达式)相应的位置中

void postfix(LinkStack s,char expr[], fstack* fs)
{
	//每个数组元素的下标代表着相应的计算符号,数值参考符号优先级表(源于网络),数值越大,优先级越高,将EOS的优先级设为0
	int in_Stack[] = { 0,19,12,12,13,13,13,0 };//表示栈里符号的优先级,其中左括号若在栈里,它的优先级最低
	int out_Stack[] = { 20,19,12,12,13,13,13,0 };//表示栈外元素
	contentType token;
	int index = 0;//表示读取字符数组的次序
	push(s, EOS);//便于第一个符号的入栈
	char symbol='0';
	ElemType e;//表示代表计算符号的值
	
	token = getToken(&symbol,index,expr);//获取中缀表达式第一个元素
	while (token != EOS)
	{
		if (token == NUM)
		{
			fs->arr[++fs->top] = symbol;
		}
		else if (token == RIGHT_PARE)
		{
			while (s->top->data != LEFT_PARE)
			{
				pop(s, &e);
				Diliever_token(e,fs);
			}
			pop(s, &e);//去除左括号
		}
		else
		{
			while (in_Stack[s->top->data] >= out_Stack[token])
			{
				pop(s, &e);
				Diliever_token(e, fs);
			}
			push(s, token);
		}
		++index;//读取下一个
		token = getToken(&symbol,index,expr);
	}
	while (!isEmpty(s))
	{
		pop(s, &e);
		Diliever_token(e, fs);
	}//将栈内的符号全部输出
	
	fs->arr[++fs->top]= '\0';//在结尾添加\0;

}//中缀表达式转为后缀表达式

int eval(LinkStack s,fstack*fs,int *result)
{
	char symbol='0';
	int op1, op2;//表示两数计算的顺序
	int index = 0; // 表示读取字符数组的次序
	contentType token;
	token = getToken(&symbol,index,fs->arr);
	while (token != EOS)
	{
		if (token == NUM)
		{
			push(s, symbol - '0');//根据ASCII码进行计算
		}
		else
		{
			pop(s, &op2);
			pop(s, &op1);

			switch (token)
			{
			case ADD:
				push(s, op1 + op2);
				break;
			case SUB:
				push(s, op1 - op2);
				break;
			case MUL:
				push(s, op1 * op2);
				break;
			case DIV:
				push(s, op1 / op2);
				break;
			case MOD:
				push(s, op1 % op2);
				break;
			default:
				break;
			}
		}
		index++;//读取下一个
		token = getToken(&symbol, index,fs->arr);
	}
	pop(s, result);//将最后的结果赋值给result
	return 1;
}//后缀表达式求值