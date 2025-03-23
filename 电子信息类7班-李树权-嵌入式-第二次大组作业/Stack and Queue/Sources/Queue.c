#include "Queue.h"

LinkQueue initQueue()
{
	LinkQueue q = (LinkQueue)malloc(sizeof(NodeListQueue));
	QueueNode node = (QueueNode)malloc(sizeof(QNode));
	node->data = 0;
	node->next = NULL;
	q->front = node;
	q->rear = node;
	return q;
}//������ʽ�ṹ�ĳ�ʼ��

int isEmptyQueue(LinkQueue q)
{
	if (q->front == q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//�ж��Ƿ�Ϊ��

void Adqueue(LinkQueue q, ElemType e)
{
	QueueNode node = (QueueNode)malloc(sizeof(QNode));
	node->data = e;
	node->next = NULL;
	q->rear->next = node;
	q->rear = node;
}//���

int Dequeue(LinkQueue q, ElemType* e)
{
	if (isEmptyQueue(q)) return 0;
	QueueNode node = q->front->next;
	*e = node->data;
	q->front->next = node->next;
	if (q->rear == node)
	{
		q->rear = q->front;
	}
	free(node);
	return 1;
}//����

ElemType getFront(LinkQueue q)
{
	if (isEmptyQueue(q))
	{
		return 0;
	}
	return q->front->next->data;
}//��ȡ��ͷԪ��

int getQueueCount(LinkQueue q)
{
	int count = 0;
	QueueNode n = q->front->next;
	while (n)
	{
		count++;
		n = n->next;
	}
	return count;
}//��ȡ����Ԫ�ظ���

void ShowQueue(LinkQueue q)
{
	int n = getQueueCount(q);
	QueueNode p = q->front->next;
	for (int i = 0; i < n; i++)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL");
	printf("\n");
}//��ʾ����Ԫ��

void ClearQueue(LinkQueue q)
{
	if (isEmptyQueue(q)) return;
	QueueNode p = NULL;
	while (!isEmptyQueue(q))
	{
		p = q->front->next;
		q->front->next = p->next;
		if (q->rear == p)
		{
			q->rear = q->front;
		}
		free(p);
	}
}//���������