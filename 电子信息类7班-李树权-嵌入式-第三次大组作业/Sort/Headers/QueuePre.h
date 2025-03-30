/***************************************************************************************
 *	File Name				:	QueuePre.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.3.30
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/
#ifndef _QUEUEPRE_H_
#define _QUEUEPRE_H_

#include <stdio.h>
#include <stdlib.h>

//定义链结构
typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;

//定义链队列
typedef struct {
    LinkNode* front, * rear;
} LinkQueue;

//初始化带头结点的链式队列
void InitQueue(LinkQueue& Q);

//判断带头结点的链式队列是否为空
int IsEmpty(LinkQueue Q);

//带头结点的链式队列入队操作
void EnQueue(LinkQueue& Q, int x);

//带头结点的链式队列出队操作
int DeQueue(LinkQueue& Q, int& x);

#endif // !_QUEUE_H_
