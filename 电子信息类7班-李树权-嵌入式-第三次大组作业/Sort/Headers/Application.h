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
   *	@description : ��ֻ��0,1,2�������������
   *	@param		 : arr[](�����������),n(����ĳ���)
   *	@return		 : None
   *  @notice      : None
   */
void sort012(int arr[], int n);

/**
  *  @name        : findKthSmallest
  *	@description : Ѱ�����������е�kС����
  *	@param		 : arr[](�����������),n(����ĳ���) k(��KС)
  *	@return		 : int(���ص�kС����)
  *  @notice      : None
  */
int findKthSmallest(int arr[], int n, int k);

/**
  *  @name        : findKthLargest
  *	@description : Ѱ�����������е�k�����
  *	@param		 : arr[](�����������),n(����ĳ���) k(��K��)
  *	@return		 : int(���ص�k�����)
  *  @notice      : None
  */
int findKthLargest(int arr[], int n, int k);

#endif 

