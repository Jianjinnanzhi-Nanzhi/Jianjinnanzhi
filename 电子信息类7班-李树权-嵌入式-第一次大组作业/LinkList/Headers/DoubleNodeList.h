/***************************************************************************************
 *	File Name				:	DoubleNodeList.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.3.16
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

#ifndef  _DOUBLENODELIST_H
#define  _DOUBLENODELIST_H

#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;//�����޸Ľڵ���������

typedef struct DNodeList
{
	Elemtype data;
	struct DNodeList* next;
	struct DNodeList* prev;
}DNodeList, * DLNode;

/**
 *  @name        : DInitList()
 *	@description : ˫������ĳ�ʼ��
 *	@param		 : None
 *	@return		 : LNode(�½������ͷָ��)
 *  @notice      : None
 */
DLNode DInitList();

/**
 *  @name        : DinsertHead(DLNode head,Elemtype data)
 *	@description : ˫�������������--ͷ�巨
 *	@param		 : head(�����ͷָ��)  data(Ҫ���������)
 *	@return		 : None
 *  @notice      : None
 */
void DinsertHead(DLNode head, Elemtype data);

/**
 *  @name        : Dget_tail(LNode head)
 *	@description : ��ȡβ�ڵ�
 *	@param		 : head(�����ͷָ��)
 *	@return		 : DLNode(��β�ڵ��ָ��)
 *  @notice      : None
 */
DLNode Dget_tail(DLNode head);

/**
 *  @name        : DinsertTail(DLNode head,Elemtype data)
 *	@description : ˫�������������--β�巨
 *	@param		 : head(�����ͷָ��)  data(Ҫ���������)
 *	@return		 : None
 *  @notice      : None
 */
void DinsertTail(DLNode head, Elemtype data);

/**
 *  @name        : DinsertNode(DLNode head, int pos, Elemtype e)
 *	@description : ˫�������������--��ָ��λ�ò���Ԫ��
 *	@param		 : head(�����ͷָ��)  pos(Ҫ�����λ��)  e(Ҫ���������)
 *	@return		 : 0��ʾ����ʧ��,1��ʾ����ɹ�
 *  @notice      : None
 */
int DinsertNode(DLNode head, int pos, Elemtype e);

/**
 *  @name        : DPrintNode(LNode head)
 *	@description : ������ӡ�������еĽڵ�
 *	@param		 : head(�����ͷָ��)
 *	@return		 : None
 *  @notice      : None
 */
void DPrintNode(DLNode head);

/**
 *  @name        : DgetList(DLNode head,int index)
 *	@description : ��ȡ��Ӧλ�õ�Ԫ��
 *	@param		 : head(�����ͷָ��)  index(Ҫ��ȡ��λ��)
 *	@return		 : Elemtype*(��λ�ýڵ����ݵ�ָ��)
 *  @notice      : None
 */
Elemtype* DgetList(DLNode head, int index);

/**
 *  @name        : DFindList(DLNode head,Elemtype data)
 *	@description : ���Ҷ�ӦԪ�ص�λ��
 *	@param		 : head(�����ͷָ��)    data(Ҫ����λ�õ�Ԫ��)
 *	@return		 : 0��ʾ����ʧ��,1��ʾ����ɹ�
 *  @notice      : None
 */
int DFindList(DLNode head, Elemtype data);

/**
 *  @name        : DdelectNode(DLNode head, int pos)
 *	@description : ˫������--ɾ���ڵ�
 *	@param		 : head(�����ͷָ��)    pos(Ҫɾ���ڵ��λ��)
 *	@return		 : 0��ʾ����ʧ��,1��ʾ����ɹ�
 *  @notice      : None
 */
int DdelectNode(DLNode head, int pos);

/**
 *  @name        : Dlistlength(DLNode head)
 *	@description : ˫������--��ȡ��������
 *	@param		 : head(�����ͷָ��)
 *	@return		 : int(������ĳ���(����ͷ�ڵ�))
 *  @notice      : None
 */
int Dlistlength(DLNode head);

/**
 *  @name        : DfreeList(DLNode head)
 *	@description : ˫������--�ͷ�����
 *	@param		 : head(�����ͷָ��)
 *	@return		 : None
 *  @notice      : ������ͷ�ڵ�
 */
void DfreeList(DLNode head);

#endif
