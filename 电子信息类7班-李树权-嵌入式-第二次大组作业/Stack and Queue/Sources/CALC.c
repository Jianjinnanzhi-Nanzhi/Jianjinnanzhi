#include "ConvenientCALC.h"

int main()
{
	printf("\n");
	printf("     *************************            *************************\n");
	printf("     *               ��ӭʹ������������ʽ��ֵ������             *\n");
	printf("     * ����ѭ����ԭ��:                                            *\n");
	printf("     *     1.��������ֻ�ܽ���һλ������                           *\n");
	printf("     *     2.��֧��С��,����,����,ֻ֧��������                    *\n");
	printf("     *     3.���г�������ʱҪ�����Ƿ����������                   *\n");
	printf("     *     4.���ʽ���ó���100���ַ�                              *\n");
	printf("     *     5.��ȷ����ı��ʽû�г���                             *\n");
	printf("     *************************            *************************\n");
	LinkStack s = initStack();
	char* expr = (char*)malloc(sizeof(expr));//�洢�������׺���ʽ
	printf("������Ҫ�����������ʽ : ");
	scanf("%s", expr);
	fstack* fs = initfstack();//������ջ����ʽ�洢ת����ĺ�׺���ʽ
	printf("\n");
	postfix(s, expr, fs);
	printf("�ñ��ʽ�ĺ�׺���ʽΪ : ");
	print_fstack(fs);
	clearStack(s);//ȷ����ջ�����,��Ӱ���׺��ֵ��ʹ��
	int result = 0;//�����洢������
	eval(s, fs,&result);
	printf("������Ϊ : %d", result);
	printf("\n");
	free(expr);
	system("pause");
	return 0;
}