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

typedef int Elemtype;//便于修改节点数据类型

typedef struct NodeList
{
	Elemtype data;
	struct NodeList* next;
}NodeList, * LNode;

/**
 *  @name        : InitList()
 *	@description : 单链表的初始化
 *	@param		 : None
 *	@return		 : LNode(新建链表的头指针)
 *  @notice      : None
 */
LNode InitList();

/**
 *  @name        : insertHead(LNode head,Elemtype data)
 *	@description : 单链表插入数据--头插法
 *	@param		 : head(链表的头指针)  data(要插入的数据)
 *	@return		 : None
 *  @notice      : None
 */
void insertHead(LNode head, Elemtype data);

/**
 *  @name        : get_tail(LNode head)
 *	@description : 获取尾节点
 *	@param		 : head(链表的头指针)
 *	@return		 : LNode(该尾节点的指针)
 *  @notice      : None
 */
LNode get_tail(LNode head);

/**
 *  @name        : insertTail(LNode head,Elemtype data)
 *	@description : 单链表插入数据--尾插法
 *	@param		 : head(链表的头指针)  data(要插入的数据)
 *	@return		 : None
 *  @notice      : None
 */
void insertTail(LNode head, Elemtype data);

/**
 *  @name        : insertNode(LNode head, int pos, Elemtype e)
 *	@description : 单链表插入数据--在指定位置插入元素
 *	@param		 : head(链表的头指针)  pos(要插入的位置)  e(要插入的数据)
 *	@return		 : 0表示插入失败,1表示插入成功
 *  @notice      : None
 */
int insertNode(LNode head, int pos, Elemtype e);

/**
 *  @name        : PrintNode(LNode head)
 *	@description : 遍历打印单链表中的节点
 *	@param		 : head(链表的头指针)
 *	@return		 : None
 *  @notice      : None
 */
void PrintNode(LNode head);

/**
 *  @name        : getList(LNode head,int index)
 *	@description : 获取对应位置的元素
 *	@param		 : head(链表的头指针)  index(要获取的位置)
 *	@return		 : Elemtype*(该位置节点数据的指针)
 *  @notice      : None
 */
Elemtype* getList(LNode head, int index);

/**
 *  @name        : FindList(LNode head,Elemtype data)
 *	@description : 查找对应元素的位置
 *	@param		 : head(链表的头指针)    data(要查找位置的元素)
 *	@return		 : 0表示插入失败,1表示插入成功
 *  @notice      : None
 */
int FindList(LNode head, Elemtype data);

/**
 *  @name        : delectNode(LNode head, int pos)
 *	@description : 单链表--删除节点
 *	@param		 : head(链表的头指针)    pos(要删除节点的位置)
 *	@return		 : 0表示插入失败,1表示插入成功
 *  @notice      : None
 */
int delectNode(LNode head, int pos);

/**
 *  @name        : listlength(LNode head)
 *	@description : 单链表--获取单链表长度
 *	@param		 : head(链表的头指针)
 *	@return		 : int(该链表的长度(包括头节点))
 *  @notice      : None
 */
int listlength(LNode head);

/**
 *  @name        : freeList(LNode head)
 *	@description : 单链表--释放链表
 *	@param		 : head(链表的头指针)
 *	@return		 : None
 *  @notice      : 保留了头节点
 */
void freeList(LNode head);

/**
 *  @name        : create_CirList(LNode head)
 *	@description : 构建循环链表
 *	@param		 : head(链表的头指针)
 *	@return		 : None
 *  @notice      : None
 */
void create_CirList(LNode head);
#endif

