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

typedef int ElemType;//�����޸ĸö���Ԫ�ص���������

typedef struct QNode 
{  
	ElemType  data;   
	struct QNode* next; 
}QNode, * QueueNode;//ע��ṹ���Լ��ýṹ��ָ�������

typedef struct NodeListQueue
{
	QueueNode  front;//ͷָ��,ָ�����ʽ�ṹ��ͷ�ڵ�
	QueueNode  rear;//βָ��,ָ��������һ���ڵ�
}NodeListQueue, * LinkQueue;//ע��ṹ���Լ��ýṹ��ָ�������


/**
 *  @name        : initQueue()
 *	@description : ������ʽ�ṹ�ĳ�ʼ��
 *	@param		 : None
 *	@return		 : LinkQueue(�½����е�ָ��)
 *  @notice      : None
 */
LinkQueue initQueue();

/**
 *  @name        : isEmptyQueue(LinkQueue q)
 *	@description : �ж϶����Ƿ�Ϊ��
 *	@param		 : q(����)
 *	@return		 : int(1��ʾ����Ϊ��,0��ʾ���в�Ϊ��)
 *  @notice      : None
 */
int isEmptyQueue(LinkQueue q);

/**
 *  @name        : Adqueue(LinkQueue q, ElemType e)
 *	@description : ���
 *	@param		 : q(����) e(��ʾҪ��ӵ�Ԫ��)
 *	@return		 : None
 *  @notice      : ����ӷ�ʽΪ�����β�巨
 */
void Adqueue(LinkQueue q, ElemType e);

/**
 *  @name        : Dequeue(LinkQueue q, ElemType* e)
 *	@description : ����
 *	@param		 : q(����) e(��ʾҪ����Ԫ�ص�ָ��)
 *	@return		 : int(0��ʾ����Ϊ��,����ʧ��;1��ʾ���в�Ϊ��,���ӳɹ�)
 *  @notice      : �����ӵ�Ԫ����ָ�뷽ʽ����e
 */
int Dequeue(LinkQueue q, ElemType* e);

/**
 *  @name        : getFront(LinkQueue q)
 *	@description : ��ȡ��ͷԪ��
 *	@param		 : q(����)
 *	@return		 : ElemType(��ͷԪ��)
 *  @notice      : None
 */
ElemType getFront(LinkQueue q);

/**
 *  @name        : getQueueCount(LinkQueue q)
 *	@description : ��ȡ����Ԫ�ظ���
 *	@param		 : q(����)
 *	@return		 : int(���е�Ԫ�ظ���)
 *  @notice      : None
 */
int getQueueCount(LinkQueue q);

/**
 *  @name        : ShowQueue(LinkQueue q)
 *	@description : ��ʾ����Ԫ��
 *	@param		 : q(����)
 *	@return		 : None
 *  @notice      : ������printf������ʹ���˸�ʽ�ַ�%d,��������Ԫ�ص��������ͷ����ı�,�뼴ʱ����
 */
void ShowQueue(LinkQueue q);

/**
 *  @name        : ClearQueue(LinkQueue q)
 *	@description : ���������
 *	@param		 : q(����)
 *	@return		 : None
 *  @notice      : ��û�����ٶ���,ֻ����ն���Ԫ��
 */
void ClearQueue(LinkQueue q);

#endif 

