/***************************************************************************************
 *	File Name				:	Stack.h
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
#ifndef _STACK_H_
#define _STACK_H

#include<stdio.h>
#include<stdlib.h>


// 定义栈结构
typedef struct {
    int* data;  // 存储栈元素
    int top;    // 栈顶指针
    int size;   // 栈容量
} Stack;

Stack* createStack(int size);//初始化栈

int isEmpty(Stack* stack);//判断栈是否为空

void push(Stack* stack, int value);//入栈

int pop(Stack* stack);//出栈

#endif 


