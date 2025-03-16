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
#ifndef  _NODELIST_H
#define  _NODELIST_H

#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;//�����޸Ľڵ���������

typedef struct NodeList
{
	Elemtype data;
	struct NodeList* next;
}NodeList, * LNode;

/**
 *  @name        : InitList()
 *	@description : ������ĳ�ʼ��
 *	@param		 : None
 *	@return		 : LNode(�½������ͷָ��)
 *  @notice      : None
 */
LNode InitList();

/**
 *  @name        : insertHead(LNode head,Elemtype data)
 *	@description : �������������--ͷ�巨
 *	@param		 : head(�����ͷָ��)  data(Ҫ���������)
 *	@return		 : None
 *  @notice      : None
 */
void insertHead(LNode head, Elemtype data);

/**
 *  @name        : get_tail(LNode head)
 *	@description : ��ȡβ�ڵ�
 *	@param		 : head(�����ͷָ��)
 *	@return		 : LNode(��β�ڵ��ָ��)
 *  @notice      : None
 */
LNode get_tail(LNode head);

/**
 *  @name        : insertTail(LNode head,Elemtype data)
 *	@description : �������������--β�巨
 *	@param		 : head(�����ͷָ��)  data(Ҫ���������)
 *	@return		 : None
 *  @notice      : None
 */
void insertTail(LNode head, Elemtype data);

/**
 *  @name        : insertNode(LNode head, int pos, Elemtype e)
 *	@description : �������������--��ָ��λ�ò���Ԫ��
 *	@param		 : head(�����ͷָ��)  pos(Ҫ�����λ��)  e(Ҫ���������)
 *	@return		 : 0��ʾ����ʧ��,1��ʾ����ɹ�
 *  @notice      : None
 */
int insertNode(LNode head, int pos, Elemtype e);

/**
 *  @name        : PrintNode(LNode head)
 *	@description : ������ӡ�������еĽڵ�
 *	@param		 : head(�����ͷָ��)
 *	@return		 : None
 *  @notice      : None
 */
void PrintNode(LNode head);

/**
 *  @name        : getList(LNode head,int index)
 *	@description : ��ȡ��Ӧλ�õ�Ԫ��
 *	@param		 : head(�����ͷָ��)  index(Ҫ��ȡ��λ��)
 *	@return		 : Elemtype*(��λ�ýڵ����ݵ�ָ��)
 *  @notice      : None
 */
Elemtype* getList(LNode head, int index);

/**
 *  @name        : FindList(LNode head,Elemtype data)
 *	@description : ���Ҷ�ӦԪ�ص�λ��
 *	@param		 : head(�����ͷָ��)    data(Ҫ����λ�õ�Ԫ��)
 *	@return		 : 0��ʾ����ʧ��,1��ʾ����ɹ�
 *  @notice      : None
 */
int FindList(LNode head, Elemtype data);

/**
 *  @name        : delectNode(LNode head, int pos)
 *	@description : ������--ɾ���ڵ�
 *	@param		 : head(�����ͷָ��)    pos(Ҫɾ���ڵ��λ��)
 *	@return		 : 0��ʾ����ʧ��,1��ʾ����ɹ�
 *  @notice      : None
 */
int delectNode(LNode head, int pos);

/**
 *  @name        : listlength(LNode head)
 *	@description : ������--��ȡ��������
 *	@param		 : head(�����ͷָ��)
 *	@return		 : int(������ĳ���(����ͷ�ڵ�))
 *  @notice      : None
 */
int listlength(LNode head);

/**
 *  @name        : freeList(LNode head)
 *	@description : ������--�ͷ�����
 *	@param		 : head(�����ͷָ��)
 *	@return		 : None
 *  @notice      : ������ͷ�ڵ�
 */
void freeList(LNode head);

/**
 *  @name        : create_CirList(LNode head)
 *	@description : ����ѭ������
 *	@param		 : head(�����ͷָ��)
 *	@return		 : None
 *  @notice      : None
 */
void create_CirList(LNode head);
#endif

