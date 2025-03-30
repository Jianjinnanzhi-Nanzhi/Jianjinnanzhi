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


// ����ջ�ṹ
typedef struct {
    int* data;  // �洢ջԪ��
    int top;    // ջ��ָ��
    int size;   // ջ����
} Stack;

Stack* createStack(int size);//��ʼ��ջ

int isEmpty(Stack* stack);//�ж�ջ�Ƿ�Ϊ��

void push(Stack* stack, int value);//��ջ

int pop(Stack* stack);//��ջ

#endif 


