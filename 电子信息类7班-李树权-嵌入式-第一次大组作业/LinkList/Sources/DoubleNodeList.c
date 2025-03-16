#include "DoubleNodeList.h"

DLNode DInitList()
{
	DLNode head = (DLNode)malloc(sizeof(DLNode));
	if (head == NULL) printf("��ʼ��ʧ��\n");
	head->data = 0;
	head->next = NULL;
	head->prev = NULL;
	return head;
}//˫������ĳ�ʼ��

void DinsertHead(DLNode head, Elemtype data)
{
	DLNode p = (DLNode)malloc(sizeof(DNodeList));
	p->data = data;
	p->next = head->next;
	p->prev = head;
	if (head->next != NULL) head->next->prev = p;
	head->next = p;
}//˫�������������--ͷ�巨

DLNode Dget_tail(DLNode head)
{
	DLNode p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}//��ȡβ�ڵ�

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
}//˫�������������--β�巨

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
	}//�ҵ�Ҫ����λ�õ�ǰ�ýڵ�

	DLNode q = (DLNode)malloc(sizeof(DLNode));
	q->data = e;
	q->next = p->next;
	q->prev = p;
	if (p->next != NULL) p->next->prev = q;
	p->next = q;
	return 1;
}//˫�������������--��ָ��λ�ò���Ԫ��

void DPrintNode(DLNode head)
{
	DLNode p = head->next;
	while (p != NULL)
	{
		printf("%d\n ", p->data);
		p = p->next;
	}
	printf("\n");
}//������ӡ�������еĽڵ�

Elemtype* DgetList(DLNode head, int index)
{
	if (index < 1) return NULL;
	do
	{
		head = head->next;
		if (head == NULL) return NULL;
	} while (--index);
	return &head->data;
}//��ȡ��Ӧλ�õ�Ԫ��

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
	return -1;//������β����Ȼû�ҵ�,�򷵻�-1
}//���Ҷ�ӦԪ�ص�λ��


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
	}//�ҵ�Ҫɾ���ڵ��ǰ�ýڵ�

	if (p->next == NULL)
	{
		printf("Ҫɾ����λ�ô���\n");
		return 0;
	}

	DLNode  q = p->next;
	p->next = q->next;
	if (q->next != NULL) q->next->prev = p;
	free(q);
	return 1;
}//˫������--ɾ���ڵ�

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
}//˫������--��ȡ��������

void DfreeList(DLNode head)
{
	DLNode p = head->next;
	DLNode q = NULL;//���p�ڵ����һ���ڵ�

	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	head->next = NULL;
}//˫������--�ͷ�����