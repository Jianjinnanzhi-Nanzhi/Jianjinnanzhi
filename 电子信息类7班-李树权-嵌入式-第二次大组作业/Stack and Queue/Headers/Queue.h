/***************************************************************************************
 *	File Name				:	Queue.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.3.22
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;//便于修改该队列元素的数据类型

typedef struct QNode 
{  
	ElemType  data;   
	struct QNode* next; 
}QNode, * QueueNode;//注意结构体以及该结构体指针的命名

typedef struct NodeListQueue
{
	QueueNode  front;//头指针,指向该链式结构的头节点
	QueueNode  rear;//尾指针,指向队列最后一个节点
}NodeListQueue, * LinkQueue;//注意结构体以及该结构体指针的命名


/**
 *  @name        : initQueue()
 *	@description : 队列链式结构的初始化
 *	@param		 : None
 *	@return		 : LinkQueue(新建队列的指针)
 *  @notice      : None
 */
LinkQueue initQueue();

/**
 *  @name        : isEmptyQueue(LinkQueue q)
 *	@description : 判断队列是否为空
 *	@param		 : q(链队)
 *	@return		 : int(1表示队列为空,0表示队列不为空)
 *  @notice      : None
 */
int isEmptyQueue(LinkQueue q);

/**
 *  @name        : Adqueue(LinkQueue q, ElemType e)
 *	@description : 入队
 *	@param		 : q(链队) e(表示要入队的元素)
 *	@return		 : None
 *  @notice      : 该入队方式为链表的尾插法
 */
void Adqueue(LinkQueue q, ElemType e);

/**
 *  @name        : Dequeue(LinkQueue q, ElemType* e)
 *	@description : 出队
 *	@param		 : q(链队) e(表示要出队元素的指针)
 *	@return		 : int(0表示队列为空,出队失败;1表示队列不为空,出队成功)
 *  @notice      : 将出队的元素以指针方式传给e
 */
int Dequeue(LinkQueue q, ElemType* e);

/**
 *  @name        : getFront(LinkQueue q)
 *	@description : 获取队头元素
 *	@param		 : q(链队)
 *	@return		 : ElemType(队头元素)
 *  @notice      : None
 */
ElemType getFront(LinkQueue q);

/**
 *  @name        : getQueueCount(LinkQueue q)
 *	@description : 获取队列元素个数
 *	@param		 : q(链队)
 *	@return		 : int(队列的元素个数)
 *  @notice      : None
 */
int getQueueCount(LinkQueue q);

/**
 *  @name        : ShowQueue(LinkQueue q)
 *	@description : 显示队列元素
 *	@param		 : q(链队)
 *	@return		 : None
 *  @notice      : 函数内printf函数中使用了格式字符%d,若队列中元素的数据类型发生改变,请即时更改
 */
void ShowQueue(LinkQueue q);

/**
 *  @name        : ClearQueue(LinkQueue q)
 *	@description : 将队列清空
 *	@param		 : q(链队)
 *	@return		 : None
 *  @notice      : 并没有销毁队列,只是清空队列元素
 */
void ClearQueue(LinkQueue q);

#endif 

