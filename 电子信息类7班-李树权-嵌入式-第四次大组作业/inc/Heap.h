/***************************************************************************************
 *	File Name				:	Heap.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.4.6
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/
#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// �ѽṹ����
typedef struct Heap 
{
    int* data;      // �洢��Ԫ�ص�����
    int capacity;   // �ѵ��������
    int size;       // �ѵ�ǰԪ�ظ���
    bool isMaxHeap; // ����Ƿ�Ϊ���ѣ�true-���ѣ�false-��С�ѣ�
} Heap;

/*
  *������
  * @param capacity: ������
  * @param isMaxHeap: �Ƿ�����
  * @return Heap(�ѵ�ָ��)
  */
Heap* createHeap(int capacity, bool isMaxHeap);
 
/*
 * ����Ԫ��
 * @param heap  ��ָ��
 * @param value ������ֵ
 * @return true��ʾ����ɹ�,false��ʾ����ʧ��(����)
 */
bool insert(Heap* heap, int value);

/**
 *������ɾ���Ѷ�Ԫ��
 * @param heap ��ָ��
 * @return �Ѷ�ֵ������Ϊ�գ�����-1;
 */
int pop(Heap* heap);


/**
 *��ȡ�Ѷ�Ԫ��
 * @param heap ��ָ��
 * @return �Ѷ�ֵ������Ϊ�գ�����-1;
 */
int peek(Heap* heap);

/**
 *�ж϶��Ƿ�Ϊ��
 * @param heap ��ָ��
 * @return trueΪ��,falseΪ�ǿ�
 */
bool isEmpty(Heap* heap);

/**
 *��ȡ��ǰ��Ԫ�ظ���
 * @param heap ��ָ��
 * @return Ԫ�ظ���
 */
int getSize(Heap* heap);

/**
 *�ͷŶ��ڴ�
 * @param heap ��ָ��
 * @return None
 */
void freeHeap(Heap* heap);

/**
*���ϵ�����������
*@param arr ����������
*@param n ���鳤��
*@param ascending �Ƿ���������trueΪ����falseΪ����
*/
void heapSortWithShiftUp(int arr[], int n, bool ascending);

/**
*���µ�����������
*@param arr ����������
*@param n ���鳤��
*@param ascending �Ƿ���������trueΪ����falseΪ����
*/
void heapSortWithShiftDown(int arr[], int n, bool ascending);

#endif // !HEAP_H

