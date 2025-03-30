/***************************************************************************************
 *	File Name				:	Selection.h
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
#ifndef _SELECTION_H_
#define _SELECTION_H

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <time.h>

 /**
   *  @name        :  quick_nSort
   *	@description : ��������(�ǵݹ��)
   *	@param		 : arr[](�����������),len(����ĳ���)
   *	@return		 : None
   *  @notice      : None
   */
void quick_nSort(int arr[], int len);

/**
   *  @name        :  bubbleSort1
   *	@description :ð������--�Ż�1(��־λ�Ż�)
   *	@param		 : arr[](�����������),n(����ĳ���)
   *	@return		 : None
   *  @notice      : None
   */
void bubbleSort1(int arr[], int n);

/**
   *  @name        :  bubbleSort2
   *	@description :ð������--�Ż�2(��¼���һ�ν���λ��)
   *	@param		 : arr[](�����������),n(����ĳ���)
   *	@return		 : None
   *  @notice      : None
   */
void bubbleSort2(int arr[], int n);

/**
   *  @name        :  bubbleSort3
   *	@description :ð������--�Ż�3(˫��ð������)
   *	@param		 : arr[](�����������),n(����ĳ���)
   *	@return		 : None
   *  @notice      : None
   */
void bubbleSort3(int arr[], int n);

/**
   *  @name        : quick_ESort
   *	@description :��������(�ݹ������Ż�)
   *	@param		 : arr[](�����������),len(����ĳ���)
   *	@return		 : None
   *  @notice      : None
   */
void quick_ESort(int arr[], int len);

/**
   *  @name        : quick_DPSort
   *	@description :��������(�ݹ��������)
   *	@param		 : arr[](�����������),len(����ĳ���)
   *	@return		 : None
   *  @notice      : None
   */
void quick_DPSort(int arr[], int len);
#endif 

