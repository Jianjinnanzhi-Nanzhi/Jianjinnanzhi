#include "ConvenientCALC.h"

fstack* initfstack()
{
	fstack* fs = (fstack*)malloc(sizeof(fstack));
	fs->top = -1;
	return fs;
}//��ʼ��˳��ջ(���������׺���ʽ)

void print_fstack(fstack* fs)
{
	size_t n = strlen(fs->arr);
	for (int i = 0; i < n; i++)
	{
		printf("%c", fs->arr[i]);
	}
	printf("\n");
}//����ջ�ķ�ʽ��ӡ˳��ջ�е�Ԫ��(��ӡ��׺���ʽ)


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
}//��ȡ���ʽ�еķ���,ת��Ϊ����0-8,���ڴ�������ջ��

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
}//����ȡ����Ԫ�ش��浽˳��ջ(�����׺���ʽ)��Ӧ��λ����

void postfix(LinkStack s,char expr[], fstack* fs)
{
	//ÿ������Ԫ�ص��±��������Ӧ�ļ������,��ֵ�ο��������ȼ���(Դ������),��ֵԽ��,���ȼ�Խ��,��EOS�����ȼ���Ϊ0
	int in_Stack[] = { 0,19,12,12,13,13,13,0 };//��ʾջ����ŵ����ȼ�,��������������ջ��,�������ȼ����
	int out_Stack[] = { 20,19,12,12,13,13,13,0 };//��ʾջ��Ԫ��
	contentType token;
	int index = 0;//��ʾ��ȡ�ַ�����Ĵ���
	push(s, EOS);//���ڵ�һ�����ŵ���ջ
	char symbol='0';
	ElemType e;//��ʾ���������ŵ�ֵ
	
	token = getToken(&symbol,index,expr);//��ȡ��׺���ʽ��һ��Ԫ��
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
			pop(s, &e);//ȥ��������
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
		++index;//��ȡ��һ��
		token = getToken(&symbol,index,expr);
	}
	while (!isEmpty(s))
	{
		pop(s, &e);
		Diliever_token(e, fs);
	}//��ջ�ڵķ���ȫ�����
	
	fs->arr[++fs->top]= '\0';//�ڽ�β���\0;

}//��׺���ʽתΪ��׺���ʽ

int eval(LinkStack s,fstack*fs,int *result)
{
	char symbol='0';
	int op1, op2;//��ʾ���������˳��
	int index = 0; // ��ʾ��ȡ�ַ�����Ĵ���
	contentType token;
	token = getToken(&symbol,index,fs->arr);
	while (token != EOS)
	{
		if (token == NUM)
		{
			push(s, symbol - '0');//����ASCII����м���
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
		index++;//��ȡ��һ��
		token = getToken(&symbol, index,fs->arr);
	}
	pop(s, result);//�����Ľ����ֵ��result
	return 1;
}//��׺���ʽ��ֵ