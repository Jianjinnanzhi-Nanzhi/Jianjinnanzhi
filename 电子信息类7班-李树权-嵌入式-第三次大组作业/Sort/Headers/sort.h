/***************************************************************************************
 *	File Name				:	sort.h
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
#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <math.h>
#include "QueuePre.h"

 /**
  *  @name        : insertion_sort
  *	@description : 插入排序
  *	@param		 : arr[](待排序的数组),n(数组的长度)
  *	@return		 : None
  *  @notice      : None
  */
void insertion_sort(int arr[], int n);

/**
 *  @name        : merge_sort
 *	@description : 归并排序
 *	@param		 : arr[](待排序的数组),n(数组的长度)
 *	@return		 : None
 *  @notice      : None
 */
void merge_sort(int arr[], int n);

/**
 *  @name        : quick_sort
 *	@description : 快速排序
 *	@param		 : arr[](待排序的数组),len(数组的长度)
 *	@return		 : None
 *  @notice      : None
 */
void quick_sort(int arr[], int len);

/**
 *  @name        : counting_sort
 *	@description : 计数排序
 *	@param		 : arr[](待排序的数组),len(数组的长度)
 *	@return		 : None
 *  @notice      : None
 */
void counting_sort(int arr[], int len);

/**
 *  @name        : BaseSort
 *	@description : 基数计数排序
 *	@param		 : arr[](待排序的数组),len(数组的长度)
 *	@return		 : None
 *  @notice      : None
 */
void BaseSort(int arr[], int len);

#endif // !_SORT_H_
