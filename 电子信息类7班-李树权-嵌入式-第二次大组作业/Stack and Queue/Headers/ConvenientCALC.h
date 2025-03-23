/***************************************************************************************
 *	File Name				:	ConvenientCALC.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.3.23
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/
#ifndef _CONVENIENTCALC_H
#define _CONVENIENTCALC_H

#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"
#include <string.h>

#define MAXSIZE 100//初始定义表达式的最大容量为100个字符,若需更多可修改

typedef enum
{
	LEFT_PARE, RIGHT_PARE,
	ADD, SUB, MUL, DIV, MOD,
	EOS, NUM
}contentType;//以数字形式表示数学符号

typedef struct
{
	char arr[MAXSIZE];
	int top;
}fstack;//用顺序栈来存储后缀表达式

/**
 *  @name        : initfstack()
 *	@description : 顺序结构栈的初始化(用于储存后缀表达式)
 *	@param		 : None
 *	@return		 : fstack(新建顺序栈的指针)
 *  @notice      : None
 */
fstack* initfstack();

/**
 *  @name        : print_fstack(fstack *fs)
 *	@description : 以入栈的顺序打印顺序栈中的元素(打印后缀表达式)
 *	@param		 : fs(储存后缀表达式的数组所在的结构体)
 *	@return		 : None
 *  @notice      : None
 */
void print_fstack(fstack *fs);

/**
 *  @name        : getToken(char* symbol, int index, char expr[])
 *	@description : 读取表达式中的符号,转化为数字0-8,利于储存在链栈中
 *	@param		 : symbol(读取的数学符号) index(读取数组的第几个元素) expr(存储中缀表达式的数组)
 *	@return		 :contentType(数学符号所代表的值(枚举类型))
 *  @notice      : None
 */
contentType getToken(char* symbol, int index, char expr[]);

/**
 *  @name        : Diliever_token(ElemType e, fstack* fs)
 *	@description : 将获取到的元素储存到顺序栈(储存后缀表达式)相应的位置中
 *	@param		 : e (数学符号所代表的值) fs(储存后缀表达式的数组所在的结构体)
 *	@return		 :int(1表示储存成功)
 *  @notice      : None
 */
int Diliever_token(ElemType e, fstack* fs);

/**
 *  @name        : postfix(LinkStack s, char expr[],fstack*fs)
 *	@description : 中缀表达式转化为后缀表达式
 *	@param		 : s(链栈) expr(存储中缀表达式的数组)  fs(储存后缀表达式的数组所在的结构体)
 *	@return		 : None
 *  @notice      : None
 */
void postfix(LinkStack s, char expr[],fstack*fs);

/**
 *  @name        :eval(LinkStack s, fstack*fs,int *result)
 *	@description : 后缀表达式求值
 *	@param		 : s(链栈) fs(储存后缀表达式的数组所在的结构体) result(保存最终结果值的指针)
 *	@return		 :int (1表示求值成功)
 *  @notice      : None
 */
int eval(LinkStack s, fstack*fs,int *result);
#endif 

