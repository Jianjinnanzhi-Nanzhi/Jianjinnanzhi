#include "GQueue.h"

void initQueue(Queue* q) 
{
    q->front = q->rear = NULL;
}// ��ʼ������


int isEmpty(Queue* q) 
{
    return q->front == NULL;//��ͷ���߶�βΪ��,�����Ϊ��
}// �������Ƿ�Ϊ��

void Adqueue(Queue* q, void* data) 
{
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = data;
    nNode->next = NULL;

    if (isEmpty(q)) 
    {
        q->front = q->rear = nNode;//û��ͷ�ڵ�
    }
    else 
    {
        q->rear->next = nNode;
        q->rear = nNode;
    }
}// ���

void* Dequeue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("�ö���Ϊ��,�޷�����\n");
    }

    Node* temp = q->front;
    void* data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) 
    {
        q->rear = NULL;
    }

    free(temp);
    return data;
}// ����


void* getFront(Queue* q)
{
    if (isEmpty(q)) 
    {
        printf("�ö���Ϊ��,�޷���ȡ��ͷԪ��\n");
    }
    return q->front->data;
}// ��ȡ��ͷԪ��


void freeQueue(Queue* q) 
{
    while (!isEmpty(q)) 
    {
        Dequeue(q);
    }
}// �ͷŶ���


