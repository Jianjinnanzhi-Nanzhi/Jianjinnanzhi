#include "DoubleNodeList.h"

DLNode DInitList()
{
	DLNode head = (DLNode)malloc(sizeof(DLNode));
	if (head == NULL) printf("初始化失败\n");
	head->data = 0;
	head->next = NULL;
	head->prev = NULL;
	return head;
}//双向链表的初始化

void DinsertHead(DLNode head, Elemtype data)
{
	DLNode p = (DLNode)malloc(sizeof(DNodeList));
	p->data = data;
	p->next = head->next;
	p->prev = head;
	if (head->next != NULL) head->next->prev = p;
	head->next = p;
}//双向链表插入数据--头插法

DLNode Dget_tail(DLNode head)
{
	DLNode p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}//获取尾节点

void DinsertTail(DLNode head, Elemtype data)
{
	DLNode p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	DLNode q = (DLNode)malloc(sizeof(DNodeList));
	q->data = data;
	q->next = p->next;
	q->prev = p;
	p->next = q;
}//双向链表插入数据--尾插法

int DinsertNode(DLNode head, int pos, Elemtype e)
{
	DLNode p = head;
	int i = 0;
	while (i < pos - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}
	}//找到要插入位置的前置节点

	DLNode q = (DLNode)malloc(sizeof(DLNode));
	q->data = e;
	q->next = p->next;
	q->prev = p;
	if (p->next != NULL) p->next->prev = q;
	p->next = q;
	return 1;
}//双向链表插入数据--在指定位置插入元素

void DPrintNode(DLNode head)
{
	DLNode p = head->next;
	while (p != NULL)
	{
		printf("%d\n ", p->data);
		p = p->next;
	}
	printf("\n");
}//遍历打印单链表中的节点

Elemtype* DgetList(DLNode head, int index)
{
	if (index < 1) return NULL;
	do
	{
		head = head->next;
		if (head == NULL) return NULL;
	} while (--index);
	return &head->data;
}//获取对应位置的元素

int DFindList(DLNode head, Elemtype data)
{
	head = head->next;
	int i = 1;
	while (head)
	{
		if (head->data == data) return i;
		head = head->next;
		i++;
	}
	return -1;//若到达尾部依然没找到,则返回-1
}//查找对应元素的位置


int DdelectNode(DLNode head, int pos)
{
	DLNode p = head;
	int i = 0;
	while (i < pos - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}
	}//找到要删除节点的前置节点

	if (p->next == NULL)
	{
		printf("要删除的位置错误\n");
		return 0;
	}

	DLNode  q = p->next;
	p->next = q->next;
	if (q->next != NULL) q->next->prev = p;
	free(q);
	return 1;
}//双向链表--删除节点

int Dlistlength(DLNode head)
{
	DLNode  p = head;
	int len = 0;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}//双向链表--获取单链表长度

void DfreeList(DLNode head)
{
	DLNode p = head->next;
	DLNode q = NULL;//存放p节点的下一个节点

	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	head->next = NULL;
}//双向链表--释放链表