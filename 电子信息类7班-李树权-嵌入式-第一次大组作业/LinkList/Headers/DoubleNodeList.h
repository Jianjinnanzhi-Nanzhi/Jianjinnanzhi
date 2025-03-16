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

typedef int Elemtype;//便于修改节点数据类型

typedef struct DNodeList
{
	Elemtype data;
	struct DNodeList* next;
	struct DNodeList* prev;
}DNodeList, * DLNode;

/**
 *  @name        : DInitList()
 *	@description : 双向链表的初始化
 *	@param		 : None
 *	@return		 : LNode(新建链表的头指针)
 *  @notice      : None
 */
DLNode DInitList();

/**
 *  @name        : DinsertHead(DLNode head,Elemtype data)
 *	@description : 双向链表插入数据--头插法
 *	@param		 : head(链表的头指针)  data(要插入的数据)
 *	@return		 : None
 *  @notice      : None
 */
void DinsertHead(DLNode head, Elemtype data);

/**
 *  @name        : Dget_tail(LNode head)
 *	@description : 获取尾节点
 *	@param		 : head(链表的头指针)
 *	@return		 : DLNode(该尾节点的指针)
 *  @notice      : None
 */
DLNode Dget_tail(DLNode head);

/**
 *  @name        : DinsertTail(DLNode head,Elemtype data)
 *	@description : 双向链表插入数据--尾插法
 *	@param		 : head(链表的头指针)  data(要插入的数据)
 *	@return		 : None
 *  @notice      : None
 */
void DinsertTail(DLNode head, Elemtype data);

/**
 *  @name        : DinsertNode(DLNode head, int pos, Elemtype e)
 *	@description : 双向链表插入数据--在指定位置插入元素
 *	@param		 : head(链表的头指针)  pos(要插入的位置)  e(要插入的数据)
 *	@return		 : 0表示插入失败,1表示插入成功
 *  @notice      : None
 */
int DinsertNode(DLNode head, int pos, Elemtype e);

/**
 *  @name        : DPrintNode(LNode head)
 *	@description : 遍历打印单链表中的节点
 *	@param		 : head(链表的头指针)
 *	@return		 : None
 *  @notice      : None
 */
void DPrintNode(DLNode head);

/**
 *  @name        : DgetList(DLNode head,int index)
 *	@description : 获取对应位置的元素
 *	@param		 : head(链表的头指针)  index(要获取的位置)
 *	@return		 : Elemtype*(该位置节点数据的指针)
 *  @notice      : None
 */
Elemtype* DgetList(DLNode head, int index);

/**
 *  @name        : DFindList(DLNode head,Elemtype data)
 *	@description : 查找对应元素的位置
 *	@param		 : head(链表的头指针)    data(要查找位置的元素)
 *	@return		 : 0表示插入失败,1表示插入成功
 *  @notice      : None
 */
int DFindList(DLNode head, Elemtype data);

/**
 *  @name        : DdelectNode(DLNode head, int pos)
 *	@description : 双向链表--删除节点
 *	@param		 : head(链表的头指针)    pos(要删除节点的位置)
 *	@return		 : 0表示插入失败,1表示插入成功
 *  @notice      : None
 */
int DdelectNode(DLNode head, int pos);

/**
 *  @name        : Dlistlength(DLNode head)
 *	@description : 双向链表--获取单链表长度
 *	@param		 : head(链表的头指针)
 *	@return		 : int(该链表的长度(包括头节点))
 *  @notice      : None
 */
int Dlistlength(DLNode head);

/**
 *  @name        : DfreeList(DLNode head)
 *	@description : 双向链表--释放链表
 *	@param		 : head(链表的头指针)
 *	@return		 : None
 *  @notice      : 保留了头节点
 */
void DfreeList(DLNode head);

#endif
