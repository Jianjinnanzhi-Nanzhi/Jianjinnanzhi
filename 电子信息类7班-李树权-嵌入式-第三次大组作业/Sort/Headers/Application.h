/***************************************************************************************
 *	File Name				:	Application.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.3.30
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 ***************************************************************************************/
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <stdio.h>
#include <stdlib.h>
#include  "sort.h"

 /**
   *  @name        : sort012
   *	@description : 将只含0,1,2的数组进行排序
   *	@param		 : arr[](待排序的数组),n(数组的长度)
   *	@return		 : None
   *  @notice      : None
   */
void sort012(int arr[], int n);

/**
  *  @name        : findKthSmallest
  *	@description : 寻找无序数组中第k小的数
  *	@param		 : arr[](待排序的数组),n(数组的长度) k(第K小)
  *	@return		 : int(返回第k小的数)
  *  @notice      : None
  */
int findKthSmallest(int arr[], int n, int k);

/**
  *  @name        : findKthLargest
  *	@description : 寻找无序数组中第k大的数
  *	@param		 : arr[](待排序的数组),n(数组的长度) k(第K大)
  *	@return		 : int(返回第k大的数)
  *  @notice      : None
  */
int findKthLargest(int arr[], int n, int k);

#endif 

