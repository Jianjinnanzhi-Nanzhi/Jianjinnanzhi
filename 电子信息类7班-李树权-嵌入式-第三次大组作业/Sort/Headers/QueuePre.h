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

//�������ṹ
typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;

//����������
typedef struct {
    LinkNode* front, * rear;
} LinkQueue;

//��ʼ����ͷ������ʽ����
void InitQueue(LinkQueue& Q);

//�жϴ�ͷ������ʽ�����Ƿ�Ϊ��
int IsEmpty(LinkQueue Q);

//��ͷ������ʽ������Ӳ���
void EnQueue(LinkQueue& Q, int x);

//��ͷ������ʽ���г��Ӳ���
int DeQueue(LinkQueue& Q, int& x);

#endif // !_QUEUE_H_
