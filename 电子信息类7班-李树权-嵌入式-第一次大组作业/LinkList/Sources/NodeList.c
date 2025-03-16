#include"NodeList.h"

LNode InitList()
{
	LNode head = (LNode)malloc(sizeof(NodeList));
	if (head == NULL) printf("��ʼ��ʧ��\n");
	head->data = 0;
	head->next = NULL;
	return head;
}//������ĳ�ʼ��

void insertHead(LNode head, Elemtype data)
{
	LNode p = (LNode)malloc(sizeof(NodeList));
	p->data = data;
	p->next = head->next;
	head->next = p;
}//�������������--ͷ�巨

LNode get_tail(LNode head)
{
	LNode p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}//��ȡβ�ڵ�

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
}//�������������--β�巨

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
	}//�ҵ�Ҫ����λ�õ�ǰ�ýڵ�

	LNode q = (LNode)malloc(sizeof(NodeList));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}//�������������--��ָ��λ�ò���Ԫ��

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
}//������ӡ�������еĽڵ�

Elemtype* getList(LNode head, int index)
{
	if (index < 1) return NULL;
	do
	{
		head = head->next;
		if (head == NULL) return NULL;
	} while (--index);
	return &head->data;
}//��ȡ��Ӧλ�õ�Ԫ��

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
	return -1;//������β����Ȼû�ҵ�,�򷵻�-1
}//���Ҷ�ӦԪ�ص�λ��

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
	}//�ҵ�Ҫɾ���ڵ��ǰ�ýڵ�

	if (p->next == NULL)
	{
		printf("Ҫɾ����λ�ô���\n");
		return 0;
	}

	LNode  q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}//������--ɾ���ڵ�

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
}//������--��ȡ��������

void freeList(LNode head)
{
	LNode p = head->next;
	LNode q = NULL;//���p�ڵ����һ���ڵ�

	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	head->next = NULL;
}//������--�ͷ�����

void create_CirList(LNode head)
{
	LNode p = get_tail(head);
	p->next = head;
}//����ѭ������