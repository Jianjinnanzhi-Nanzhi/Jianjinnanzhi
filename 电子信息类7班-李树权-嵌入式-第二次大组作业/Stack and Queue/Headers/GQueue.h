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
    void* data;          // ����ָ��
    struct Node* next;   // ָ����һ���ڵ��ָ��
} Node;

typedef struct {
    Node* front;  // ��ͷָ��
    Node* rear;   // ��βָ��
}Queue;

/**
 *  @name        : initQueue(Queue* q)
 *	@description : ��ʼ������
 *	@param		 : q(Queue�ṹ���ָ��)
 *	@return		 : None
 *  @notice      : None
 */
void initQueue(Queue* q);

/**
 *  @name        : isEmpty(Queue* q)
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : q(Queue�ṹ���ָ��)
 *	@return		 : int(1��ʾ�ö���Ϊ��,0��ʾ�ö��зǿ�)
 *  @notice      : None
 */
int isEmpty(Queue* q);

/**
 *  @name        : Adqueue(Queue* q, void* data)
 *	@description : ���
 *	@param		 : q(Queue�ṹ���ָ��) data(void*����(����),Ҫ�������ݵ�ָ��)
 *	@return		 : None
 *  @notice      : ��ֱ�Ӳ����κ����͵�����(��������ת��)
 */
void Adqueue(Queue* q, void* data);

/**
 *  @name        : Dequeue(Queue* q)
 *	@description : ����
 *	@param		 : q(Queue�ṹ���ָ��) 
 *	@return		 : void*(���س������ݵ�ָ��)
 *  @notice      : ����ָ�벻�ܽ��н�����,��Ҫ����ǿ����������ת��,�ٽ�����,����*(int*)getFront(&q)
 */
void* Dequeue(Queue* q);

/**
 *  @name        : getFront(Queue* q)
 *	@description : ��ȡ��ͷԪ��
 *	@param		 : q(Queue�ṹ���ָ��)
 *	@return		 : void*(���س������ݵ�ָ��)
 *  @notice      : ����ָ�벻�ܽ��н�����,��Ҫǿ����������ת��,�ٽ�����,����*(int*)getFront(&q)
 */
void* getFront(Queue* q);

/**
 *  @name        : freeQueue(Queue* q)
 *	@description : �ͷŶ���
 *	@param		 : q(Queue�ṹ���ָ��)
 *	@return		 : None
 *  @notice      : ���ڸ���ʽ�Ķ��в���ͷ�ڵ�,����ֱ���ͷŶ���,���������
 */
void freeQueue(Queue* q);

#endif

