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
   *	@description : 快速排序(非递归版)
   *	@param		 : arr[](待排序的数组),len(数组的长度)
   *	@return		 : None
   *  @notice      : None
   */
void quick_nSort(int arr[], int len);

/**
   *  @name        :  bubbleSort1
   *	@description :冒泡排序--优化1(标志位优化)
   *	@param		 : arr[](待排序的数组),n(数组的长度)
   *	@return		 : None
   *  @notice      : None
   */
void bubbleSort1(int arr[], int n);

/**
   *  @name        :  bubbleSort2
   *	@description :冒泡排序--优化2(记录最后一次交换位置)
   *	@param		 : arr[](待排序的数组),n(数组的长度)
   *	@return		 : None
   *  @notice      : None
   */
void bubbleSort2(int arr[], int n);

/**
   *  @name        :  bubbleSort3
   *	@description :冒泡排序--优化3(双向冒泡排序)
   *	@param		 : arr[](待排序的数组),n(数组的长度)
   *	@return		 : None
   *  @notice      : None
   */
void bubbleSort3(int arr[], int n);

/**
   *  @name        : quick_ESort
   *	@description :快速排序(递归版随机优化)
   *	@param		 : arr[](待排序的数组),len(数组的长度)
   *	@return		 : None
   *  @notice      : None
   */
void quick_ESort(int arr[], int len);

/**
   *  @name        : quick_DPSort
   *	@description :快速排序(递归版三枢轴)
   *	@param		 : arr[](待排序的数组),len(数组的长度)
   *	@return		 : None
   *  @notice      : None
   */
void quick_DPSort(int arr[], int len);
#endif 

