/***************************************************************************************
 *	File Name				:	Choice.h
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
#ifndef  _Choice_H
#define  _Choice_H

#include<stdio.h>
#include<stdlib.h>
#include "NodeList.h"

typedef int Elemtype;//便于修改节点数据类型

/**
 *  @name        : ExchangeOE(LNode head)
 *	@description : 交换奇偶位置的节点
 *	@param		 : head(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void ExchangeOE(LNode head);

/**
 *  @name        : delMiddleNode(LNode head)
 *	@description : 找到链表中间的节点
 *	@param		 : head(the head node)
 *	@return		 : LNode(该中间节点的指针)
 *  @notice      : None
 */
LNode FindMiddleNode(LNode head);

/**
 *  @name        : isCycle(LNode head)
 *	@description : 判断链表是否有环,有环则返回1,无环则返回0
 *	@param		 : head(the head node)
 *	@return		 : 1或0
 *  @notice      : None
 */
int isCycle(LNode head);

/**
 *  @name        : reverseListNR(LNode head)
 *	@description : 反转链表(非递归)
 *	@param		 : head(the head node)
 *	@return		 : LNode(反转后的头指针)
 *  @notice      : None
 */
LNode reverseListNR(LNode head);

/**
 *  @name        : reverseListR(LNode head)
 *	@description : 反转链表(非递归)
 *	@param		 : head(the head node)
 *	@return		 : LNode(反转后的头指针)
 *  @notice      : None
 */
LNode reverseListR(LNode head);
//反转链表(递归)

#endif
