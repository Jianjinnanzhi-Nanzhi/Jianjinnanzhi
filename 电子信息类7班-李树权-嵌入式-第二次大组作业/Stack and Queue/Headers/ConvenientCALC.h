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

#define MAXSIZE 100//��ʼ������ʽ���������Ϊ100���ַ�,���������޸�

typedef enum
{
	LEFT_PARE, RIGHT_PARE,
	ADD, SUB, MUL, DIV, MOD,
	EOS, NUM
}contentType;//��������ʽ��ʾ��ѧ����

typedef struct
{
	char arr[MAXSIZE];
	int top;
}fstack;//��˳��ջ���洢��׺���ʽ

/**
 *  @name        : initfstack()
 *	@description : ˳��ṹջ�ĳ�ʼ��(���ڴ����׺���ʽ)
 *	@param		 : None
 *	@return		 : fstack(�½�˳��ջ��ָ��)
 *  @notice      : None
 */
fstack* initfstack();

/**
 *  @name        : print_fstack(fstack *fs)
 *	@description : ����ջ��˳���ӡ˳��ջ�е�Ԫ��(��ӡ��׺���ʽ)
 *	@param		 : fs(�����׺���ʽ���������ڵĽṹ��)
 *	@return		 : None
 *  @notice      : None
 */
void print_fstack(fstack *fs);

/**
 *  @name        : getToken(char* symbol, int index, char expr[])
 *	@description : ��ȡ���ʽ�еķ���,ת��Ϊ����0-8,���ڴ�������ջ��
 *	@param		 : symbol(��ȡ����ѧ����) index(��ȡ����ĵڼ���Ԫ��) expr(�洢��׺���ʽ������)
 *	@return		 :contentType(��ѧ�����������ֵ(ö������))
 *  @notice      : None
 */
contentType getToken(char* symbol, int index, char expr[]);

/**
 *  @name        : Diliever_token(ElemType e, fstack* fs)
 *	@description : ����ȡ����Ԫ�ش��浽˳��ջ(�����׺���ʽ)��Ӧ��λ����
 *	@param		 : e (��ѧ�����������ֵ) fs(�����׺���ʽ���������ڵĽṹ��)
 *	@return		 :int(1��ʾ����ɹ�)
 *  @notice      : None
 */
int Diliever_token(ElemType e, fstack* fs);

/**
 *  @name        : postfix(LinkStack s, char expr[],fstack*fs)
 *	@description : ��׺���ʽת��Ϊ��׺���ʽ
 *	@param		 : s(��ջ) expr(�洢��׺���ʽ������)  fs(�����׺���ʽ���������ڵĽṹ��)
 *	@return		 : None
 *  @notice      : None
 */
void postfix(LinkStack s, char expr[],fstack*fs);

/**
 *  @name        :eval(LinkStack s, fstack*fs,int *result)
 *	@description : ��׺���ʽ��ֵ
 *	@param		 : s(��ջ) fs(�����׺���ʽ���������ڵĽṹ��) result(�������ս��ֵ��ָ��)
 *	@return		 :int (1��ʾ��ֵ�ɹ�)
 *  @notice      : None
 */
int eval(LinkStack s, fstack*fs,int *result);
#endif 

