#include "Stack_and_Queue.h"

/**
 * ������ջ
 */
LinkedStack* createStack() 
{
    LinkedStack* s = (LinkedStack*)malloc(sizeof(LinkedStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

/**
 * ��ջ����
 * @param s ջָ��
 * @param treeNode Ҫ��ջ�Ķ������ڵ�
 */
Status push(LinkedStack* s, NodePtr treeNode)
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) return failed;

    newNode->treeNode = treeNode;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    return succeed;
}

/**
 * ��ջ����
 * @param s ջָ��
 * @return ��ջ�Ķ������ڵ�(ջ�շ���NULL)
 */
NodePtr pop(LinkedStack* s) 
{
    if (s->top == NULL) return NULL;

    StackNode* temp = s->top;
    NodePtr treeNode = temp->treeNode;

    s->top = s->top->next;
    free(temp);
    s->size--;
    return treeNode;
}

/**
 * ���ջ�Ƿ�Ϊ��
 */
Status isStackEmpty(LinkedStack* s) 
{
    return s->top == NULL;
}

/**
 * �ͷ�ջ�ڴ�
 */
void freeStack(LinkedStack* s) 
{
    while (!isStackEmpty(s)) 
    {
        pop(s);
    }
    free(s);
}

/**
 * �����ն���
 */
LinkedQueue* createQueue() 
{
    LinkedQueue* q = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

/**
 * ��Ӳ���
 * @param q ����ָ��
 * @param treeNode Ҫ��ӵĶ������ڵ�
 */
Status enqueue(LinkedQueue* q, NodePtr treeNode) 
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) return failed;

    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else 
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    return succeed;
}

/**
 * ���Ӳ���
 * @param q ����ָ��
 * @return ���ӵĶ������ڵ�(�ӿշ���NULL)
 */
NodePtr dequeue(LinkedQueue* q) 
{
    if (q->front == NULL) return NULL;

    QueueNode* temp = q->front;
    NodePtr treeNode = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL) 
    {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return treeNode;
}

/**
 * �������Ƿ�Ϊ��
 */
Status isQueueEmpty(LinkedQueue* q)
{
    return q->front == NULL;
}

/**
 * �ͷŶ����ڴ�
 */
void freeQueue(LinkedQueue* q) 
{

    while (!isQueueEmpty(q)) 
    {
        dequeue(q);
    }
    free(q);
}