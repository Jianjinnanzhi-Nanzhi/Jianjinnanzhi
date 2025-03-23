/***************************************************************************************
 *	File Name				:	GQueue.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.3.23
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/
#ifndef  _GQUEUE_H
#define  _QGUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;          // 数据指针
    struct Node* next;   // 指向下一个节点的指针
} Node;

typedef struct {
    Node* front;  // 队头指针
    Node* rear;   // 队尾指针
}Queue;

/**
 *  @name        : initQueue(Queue* q)
 *	@description : 初始化队列
 *	@param		 : q(Queue结构体的指针)
 *	@return		 : None
 *  @notice      : None
 */
void initQueue(Queue* q);

/**
 *  @name        : isEmpty(Queue* q)
 *	@description : 检查队列是否为空
 *	@param		 : q(Queue结构体的指针)
 *	@return		 : int(1表示该队列为空,0表示该队列非空)
 *  @notice      : None
 */
int isEmpty(Queue* q);

/**
 *  @name        : Adqueue(Queue* q, void* data)
 *	@description : 入队
 *	@param		 : q(Queue结构体的指针) data(void*类型(泛型),要插入数据的指针)
 *	@return		 : None
 *  @notice      : 可直接插入任何类型的数据(无需类型转换)
 */
void Adqueue(Queue* q, void* data);

/**
 *  @name        : Dequeue(Queue* q)
 *	@description : 出队
 *	@param		 : q(Queue结构体的指针) 
 *	@return		 : void*(返回出队数据的指针)
 *  @notice      : 泛型指针不能进行解引用,需要进行强制数据类型转换,再解引用,例如*(int*)getFront(&q)
 */
void* Dequeue(Queue* q);

/**
 *  @name        : getFront(Queue* q)
 *	@description : 获取队头元素
 *	@param		 : q(Queue结构体的指针)
 *	@return		 : void*(返回出队数据的指针)
 *  @notice      : 泛型指针不能进行解引用,需要强制数据类型转换,再解引用,例如*(int*)getFront(&q)
 */
void* getFront(Queue* q);

/**
 *  @name        : freeQueue(Queue* q)
 *	@description : 释放队列
 *	@param		 : q(Queue结构体的指针)
 *	@return		 : None
 *  @notice      : 由于该形式的队列不含头节点,所以直接释放队列,而不是清空
 */
void freeQueue(Queue* q);

#endif

