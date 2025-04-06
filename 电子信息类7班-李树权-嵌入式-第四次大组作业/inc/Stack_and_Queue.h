/***************************************************************************************
 *	File Name				:	Stack_and_Queue.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.4.6
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

#ifndef STACK_AND_QUEUE_H
#define STACK_AND_QUEUE_H

#include "binary_sort_tree.h"

typedef struct StackNode 
{
    NodePtr treeNode;          // 存储二叉树节点指针
    struct StackNode* next;     // 下一个栈节点
} StackNode;

/* 链式栈结构 */
typedef struct 
{
    StackNode* top;            // 栈顶指针
    int size;                  // 当前栈大小
} LinkedStack;


/* 链式队列结点结构 */
typedef struct QueueNode 
{
    NodePtr treeNode;          // 存储二叉树节点指针
    struct QueueNode* next;    // 下一个队列节点
} QueueNode;

/* 链式队列结构 */
typedef struct 
{
    QueueNode* front;          // 队首指针
    QueueNode* rear;           // 队尾指针
    int size;                  // 当前队列大小
} LinkedQueue;

/**
 * 创建空栈
 */
LinkedStack* createStack();

/**
 * 入栈操作
 * @param s 栈指针
 * @param treeNode 要入栈的二叉树节点
 */
Status push(LinkedStack* s, NodePtr treeNode);

/**
 * 出栈操作
 * @param s 栈指针
 * @return 出栈的二叉树节点(栈空返回NULL)
 */
NodePtr pop(LinkedStack* s);

/**
 * 检查栈是否为空
 */
Status isStackEmpty(LinkedStack* s);

/**
 * 释放栈内存
 */
void freeStack(LinkedStack* s);


/**
 * 创建空队列
 */
LinkedQueue* createQueue();

/**
 * 入队操作
 * @param q 队列指针
 * @param treeNode 要入队的二叉树节点
 */
Status enqueue(LinkedQueue* q, NodePtr treeNode);

/**
 * 出队操作
 * @param q 队列指针
 * @return 出队的二叉树节点(队空返回NULL)
 */
NodePtr dequeue(LinkedQueue* q);

/**
 * 检查队列是否为空
 */
Status isQueueEmpty(LinkedQueue* q);

/**
 * 释放队列内存
 */
void freeQueue(LinkedQueue* q);

#endif