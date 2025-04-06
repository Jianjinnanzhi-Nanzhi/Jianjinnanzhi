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
    NodePtr treeNode;          // �洢�������ڵ�ָ��
    struct StackNode* next;     // ��һ��ջ�ڵ�
} StackNode;

/* ��ʽջ�ṹ */
typedef struct 
{
    StackNode* top;            // ջ��ָ��
    int size;                  // ��ǰջ��С
} LinkedStack;


/* ��ʽ���н��ṹ */
typedef struct QueueNode 
{
    NodePtr treeNode;          // �洢�������ڵ�ָ��
    struct QueueNode* next;    // ��һ�����нڵ�
} QueueNode;

/* ��ʽ���нṹ */
typedef struct 
{
    QueueNode* front;          // ����ָ��
    QueueNode* rear;           // ��βָ��
    int size;                  // ��ǰ���д�С
} LinkedQueue;

/**
 * ������ջ
 */
LinkedStack* createStack();

/**
 * ��ջ����
 * @param s ջָ��
 * @param treeNode Ҫ��ջ�Ķ������ڵ�
 */
Status push(LinkedStack* s, NodePtr treeNode);

/**
 * ��ջ����
 * @param s ջָ��
 * @return ��ջ�Ķ������ڵ�(ջ�շ���NULL)
 */
NodePtr pop(LinkedStack* s);

/**
 * ���ջ�Ƿ�Ϊ��
 */
Status isStackEmpty(LinkedStack* s);

/**
 * �ͷ�ջ�ڴ�
 */
void freeStack(LinkedStack* s);


/**
 * �����ն���
 */
LinkedQueue* createQueue();

/**
 * ��Ӳ���
 * @param q ����ָ��
 * @param treeNode Ҫ��ӵĶ������ڵ�
 */
Status enqueue(LinkedQueue* q, NodePtr treeNode);

/**
 * ���Ӳ���
 * @param q ����ָ��
 * @return ���ӵĶ������ڵ�(�ӿշ���NULL)
 */
NodePtr dequeue(LinkedQueue* q);

/**
 * �������Ƿ�Ϊ��
 */
Status isQueueEmpty(LinkedQueue* q);

/**
 * �ͷŶ����ڴ�
 */
void freeQueue(LinkedQueue* q);

#endif