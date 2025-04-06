#include "Stack_and_Queue.h"

/**
 * 创建空栈
 */
LinkedStack* createStack() 
{
    LinkedStack* s = (LinkedStack*)malloc(sizeof(LinkedStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

/**
 * 入栈操作
 * @param s 栈指针
 * @param treeNode 要入栈的二叉树节点
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
 * 出栈操作
 * @param s 栈指针
 * @return 出栈的二叉树节点(栈空返回NULL)
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
 * 检查栈是否为空
 */
Status isStackEmpty(LinkedStack* s) 
{
    return s->top == NULL;
}

/**
 * 释放栈内存
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
 * 创建空队列
 */
LinkedQueue* createQueue() 
{
    LinkedQueue* q = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

/**
 * 入队操作
 * @param q 队列指针
 * @param treeNode 要入队的二叉树节点
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
 * 出队操作
 * @param q 队列指针
 * @return 出队的二叉树节点(队空返回NULL)
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
 * 检查队列是否为空
 */
Status isQueueEmpty(LinkedQueue* q)
{
    return q->front == NULL;
}

/**
 * 释放队列内存
 */
void freeQueue(LinkedQueue* q) 
{

    while (!isQueueEmpty(q)) 
    {
        dequeue(q);
    }
    free(q);
}