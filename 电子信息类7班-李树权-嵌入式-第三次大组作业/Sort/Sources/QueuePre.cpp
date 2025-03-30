#include "QueuePre.h"

//��ʼ����ͷ������ʽ����
void InitQueue(LinkQueue& Q)
{
    //��ʼʱ front��rear��ָ��ͷ���
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//�жϴ�ͷ������ʽ�����Ƿ�Ϊ��
int IsEmpty(LinkQueue Q) 
{
    if (Q.front == Q.rear || Q.front->next == NULL)
        return 1;
    else
        return 0;
}

//��ͷ������ʽ������Ӳ���
void EnQueue(LinkQueue& Q, int x) 
{
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

//��ͷ������ʽ���г��Ӳ���
int DeQueue(LinkQueue& Q, int& x) 
{
    if (Q.front == Q.rear)          //�ж��Ƿ�Ϊ�ն�
        return 0;
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);                        //�ͷ�Ҫɾ�����Ŀռ�
    return 1;
}