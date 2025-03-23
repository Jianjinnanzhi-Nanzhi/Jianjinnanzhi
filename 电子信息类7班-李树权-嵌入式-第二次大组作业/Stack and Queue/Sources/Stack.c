#include "Stack.h"

LinkStack initStack()
{
	LinkStack s = (LinkStack)malloc(sizeof(NodeListStack));
	s->top = NULL;
	s->count = 0;
	return s;
}//初始化栈

int isEmpty(LinkStack s)
{
	if (s->top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//判断栈是否为空

void push(LinkStack s, ElemType e)
{
	StackNode p = (StackNode)malloc(sizeof(Node));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
}//进栈/压栈

int pop(LinkStack s, ElemType* e)
{
	if (s->top == NULL)
	{
		return 0;
	}
	*e = s->top->data;
	StackNode p = s->top;
	s->top = p->next;
	free(p);
	s->count--;
	return 1;
}//出栈

int getTop(LinkStack s, ElemType* e)
{
	if (s->top== NULL)
	{
		return 0;
	}
	*e = s->top->data;
	return 1;
}//获取栈顶元素

void clearStack(LinkStack s)
{
	if (s->top == NULL)
	{
		return;
	}
	StackNode q=NULL;
	while (s->count != 0)
	{
		q = s->top;
		s->top = s->top->next;
		free(q);
		s->count--;
	}
}//清空栈元素

void printStack(LinkStack s)
{
	StackNode q = s->top;
	if (q == NULL)
		return;
	while (q != NULL)
	{
		printf("%d->", q->data);
		q =q->next;
	}
	printf("NULL");
	printf("\n");
}//按出栈顺序打印
