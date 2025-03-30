#include "QueuePre.h"

//初始化带头结点的链式队列
void InitQueue(LinkQueue& Q)
{
    //初始时 front和rear都指向头结点
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//判断带头结点的链式队列是否为空
int IsEmpty(LinkQueue Q) 
{
    if (Q.front == Q.rear || Q.front->next == NULL)
        return 1;
    else
        return 0;
}

//带头结点的链式队列入队操作
void EnQueue(LinkQueue& Q, int x) 
{
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

//带头结点的链式队列出队操作
int DeQueue(LinkQueue& Q, int& x) 
{
    if (Q.front == Q.rear)          //判断是否为空队
        return 0;
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);                        //释放要删除结点的空间
    return 1;
}