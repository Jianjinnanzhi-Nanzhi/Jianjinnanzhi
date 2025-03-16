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

typedef int Elemtype;//�����޸Ľڵ���������

/**
 *  @name        : ExchangeOE(LNode head)
 *	@description : ������żλ�õĽڵ�
 *	@param		 : head(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void ExchangeOE(LNode head);

/**
 *  @name        : delMiddleNode(LNode head)
 *	@description : �ҵ������м�Ľڵ�
 *	@param		 : head(the head node)
 *	@return		 : LNode(���м�ڵ��ָ��)
 *  @notice      : None
 */
LNode FindMiddleNode(LNode head);

/**
 *  @name        : isCycle(LNode head)
 *	@description : �ж������Ƿ��л�,�л��򷵻�1,�޻��򷵻�0
 *	@param		 : head(the head node)
 *	@return		 : 1��0
 *  @notice      : None
 */
int isCycle(LNode head);

/**
 *  @name        : reverseListNR(LNode head)
 *	@description : ��ת����(�ǵݹ�)
 *	@param		 : head(the head node)
 *	@return		 : LNode(��ת���ͷָ��)
 *  @notice      : None
 */
LNode reverseListNR(LNode head);

/**
 *  @name        : reverseListR(LNode head)
 *	@description : ��ת����(�ǵݹ�)
 *	@param		 : head(the head node)
 *	@return		 : LNode(��ת���ͷָ��)
 *  @notice      : None
 */
LNode reverseListR(LNode head);
//��ת����(�ݹ�)

#endif
