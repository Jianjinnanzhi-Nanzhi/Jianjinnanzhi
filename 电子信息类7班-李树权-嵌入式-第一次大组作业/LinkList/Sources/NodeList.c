#include"NodeList.h"

LNode InitList()
{
	LNode head = (LNode)malloc(sizeof(NodeList));
	if (head == NULL) printf("初始化失败\n");
	head->data = 0;
	head->next = NULL;
	return head;
}//单链表的初始化

void insertHead(LNode head, Elemtype data)
{
	LNode p = (LNode)malloc(sizeof(NodeList));
	p->data = data;
	p->next = head->next;
	head->next = p;
}//单链表插入数据--头插法

LNode get_tail(LNode head)
{
	LNode p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}//获取尾节点

void insertTail(LNode head, Elemtype data)
{
	LNode p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	LNode q = (LNode)malloc(sizeof(NodeList));
	q->data = data;
	q->next = p->next;
	p->next = q;
}//单链表插入数据--尾插法

int insertNode(LNode head, int pos, Elemtype e)
{
	LNode p = head;
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

	LNode q = (LNode)malloc(sizeof(NodeList));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}//单链表插入数据--在指定位置插入元素

void PrintNode(LNode head)
{
	LNode p = head->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL");
	printf("\n");
}//遍历打印单链表中的节点

Elemtype* getList(LNode head, int index)
{
	if (index < 1) return NULL;
	do
	{
		head = head->next;
		if (head == NULL) return NULL;
	} while (--index);
	return &head->data;
}//获取对应位置的元素

int FindList(LNode head, Elemtype data)
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

int delectNode(LNode head, int pos)
{
	LNode p = head;
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

	LNode  q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}//单链表--删除节点

int listlength(LNode head)
{
	LNode  p = head;
	int len = 0;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}//单链表--获取单链表长度

void freeList(LNode head)
{
	LNode p = head->next;
	LNode q = NULL;//存放p节点的下一个节点

	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	head->next = NULL;
}//单链表--释放链表

void create_CirList(LNode head)
{
	LNode p = get_tail(head);
	p->next = head;
}//构建循环链表