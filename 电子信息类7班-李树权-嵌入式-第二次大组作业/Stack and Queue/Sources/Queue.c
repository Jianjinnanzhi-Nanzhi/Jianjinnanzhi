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
}//队列链式结构的初始化

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
}//判断是否为空

void Adqueue(LinkQueue q, ElemType e)
{
	QueueNode node = (QueueNode)malloc(sizeof(QNode));
	node->data = e;
	node->next = NULL;
	q->rear->next = node;
	q->rear = node;
}//入队

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
}//出队

ElemType getFront(LinkQueue q)
{
	if (isEmptyQueue(q))
	{
		return 0;
	}
	return q->front->next->data;
}//获取队头元素

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
}//获取队列元素个数

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
}//显示队列元素

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
}//清空链队列