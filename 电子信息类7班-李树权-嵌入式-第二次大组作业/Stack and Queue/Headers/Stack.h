/***************************************************************************************
 *	File Name				:	Stack.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.3.22
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

#ifndef  _STACK_H
#define  _STACK_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;//�����޸Ľڵ����������

typedef struct Node {
	ElemType data;
	struct Node* next;
}Node, *StackNode;//ע��ṹ���Լ��ýṹ��ָ�������

typedef  struct  NodeListStack
{
	StackNode top;	//ջ��ָ��
	int	 count;  //ջ��Ԫ�ظ���
}NodeListStack,*LinkStack;//ע��ṹ���Լ��ýṹ��ָ�������

/**
 *  @name        : initStack()
 *	@description : ջ��ʽ�ṹ�ĳ�ʼ��
 *	@param		 : None
 *	@return		 : LinkStack(�½�ջ��ָ��)
 *  @notice      : None
 */
LinkStack initStack();

/**
 *  @name        : isEmpty(LinkStack s)
 *	@description : �ж�ջ�Ƿ�Ϊ��
 *	@param		 : s(��ջ)
 *	@return		 : int(1��ʾ��ջΪ��,0��ʾջ�д���Ԫ��)
 *  @notice      : None
 */
int isEmpty(LinkStack s);

/**
 *  @name        : push(LinkStack s, ElemType e)
 *	@description : ��ջ
 *	@param		 : s(��ջ) e(Ҫ��ջ��Ԫ��)
 *	@return		 : None
 *  @notice      : None
 */
void push(LinkStack s, ElemType e);

/**
 *  @name        : pop(LinkStack s, ElemType* e)
 *	@description : ��ջ
 *	@param		 : s(��ջ) e(Ҫ��ջԪ�ص�ָ��)
 *	@return		 : int(0��ʾ��ջΪ��,��ջʧ��;1��ʾ��ջ��Ϊ��,��ջ�ɹ�)
 *  @notice      : ����ջ��Ԫ����ָ�뷽ʽ����e
 */
int pop(LinkStack s, ElemType* e);

/**
 *  @name        : getTop(LinkStack s, ElemType* e)
 *	@description : ��ȡջ��Ԫ��
 *	@param		 : s(��ջ) e(ջ��Ԫ�ص�ָ��)
 *	@return		 : int(0��ʾ��ջΪ��,��ȡʧ��;1��ʾ��ջ��Ϊ��,��ȡ�ɹ�)
 *  @notice      : ��ջ����Ԫ����ָ�뷽ʽ����e
 */
int getTop(LinkStack s, ElemType* e);

/**
 *  @name        : clearStack(LinkStack s)
 *	@description : ����ջԪ�����
 *	@param		 : s(��ջ)
 *	@return		 : None
 *  @notice      : ��û������ջ
 */
void clearStack(LinkStack s);

/**
 *  @name        : printStack(LinkStack s)
 *	@description : �Գ�ջ˳���ӡջ��Ԫ��
 *	@param		 : s(��ջ)
 *	@return		 : None
 *  @notice      : ������printf������ʹ���˸�ʽ�ַ�%d,��������Ԫ�ص��������ͷ����ı�,�뼴ʱ����
 */
void printStack(LinkStack s);

#endif