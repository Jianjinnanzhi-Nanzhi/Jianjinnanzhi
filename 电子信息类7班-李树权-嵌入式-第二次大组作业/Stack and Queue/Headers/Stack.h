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

typedef int ElemType;//便于修改节点的数据类型

typedef struct Node {
	ElemType data;
	struct Node* next;
}Node, *StackNode;//注意结构体以及该结构体指针的命名

typedef  struct  NodeListStack
{
	StackNode top;	//栈顶指针
	int	 count;  //栈中元素个数
}NodeListStack,*LinkStack;//注意结构体以及该结构体指针的命名

/**
 *  @name        : initStack()
 *	@description : 栈链式结构的初始化
 *	@param		 : None
 *	@return		 : LinkStack(新建栈的指针)
 *  @notice      : None
 */
LinkStack initStack();

/**
 *  @name        : isEmpty(LinkStack s)
 *	@description : 判断栈是否为空
 *	@param		 : s(链栈)
 *	@return		 : int(1表示该栈为空,0表示栈中存有元素)
 *  @notice      : None
 */
int isEmpty(LinkStack s);

/**
 *  @name        : push(LinkStack s, ElemType e)
 *	@description : 入栈
 *	@param		 : s(链栈) e(要入栈的元素)
 *	@return		 : None
 *  @notice      : None
 */
void push(LinkStack s, ElemType e);

/**
 *  @name        : pop(LinkStack s, ElemType* e)
 *	@description : 出栈
 *	@param		 : s(链栈) e(要出栈元素的指针)
 *	@return		 : int(0表示该栈为空,出栈失败;1表示该栈不为空,出栈成功)
 *  @notice      : 将出栈的元素以指针方式传给e
 */
int pop(LinkStack s, ElemType* e);

/**
 *  @name        : getTop(LinkStack s, ElemType* e)
 *	@description : 获取栈顶元素
 *	@param		 : s(链栈) e(栈顶元素的指针)
 *	@return		 : int(0表示该栈为空,获取失败;1表示该栈不为空,获取成功)
 *  @notice      : 将栈顶的元素以指针方式传给e
 */
int getTop(LinkStack s, ElemType* e);

/**
 *  @name        : clearStack(LinkStack s)
 *	@description : 将该栈元素清空
 *	@param		 : s(链栈)
 *	@return		 : None
 *  @notice      : 并没有销毁栈
 */
void clearStack(LinkStack s);

/**
 *  @name        : printStack(LinkStack s)
 *	@description : 以出栈顺序打印栈的元素
 *	@param		 : s(链栈)
 *	@return		 : None
 *  @notice      : 函数内printf函数中使用了格式字符%d,若队列中元素的数据类型发生改变,请即时更改
 */
void printStack(LinkStack s);

#endif