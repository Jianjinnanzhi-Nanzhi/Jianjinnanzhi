#include "GQueue.h"

void initQueue(Queue* q) 
{
    q->front = q->rear = NULL;
}// 初始化队列


int isEmpty(Queue* q) 
{
    return q->front == NULL;//对头或者队尾为空,则队列为空
}// 检查队列是否为空

void Adqueue(Queue* q, void* data) 
{
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = data;
    nNode->next = NULL;

    if (isEmpty(q)) 
    {
        q->front = q->rear = nNode;//没有头节点
    }
    else 
    {
        q->rear->next = nNode;
        q->rear = nNode;
    }
}// 入队

void* Dequeue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("该队列为空,无法出队\n");
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
}// 出队


void* getFront(Queue* q)
{
    if (isEmpty(q)) 
    {
        printf("该队列为空,无法获取对头元素\n");
    }
    return q->front->data;
}// 获取队头元素


void freeQueue(Queue* q) 
{
    while (!isEmpty(q)) 
    {
        Dequeue(q);
    }
}// 释放队列


