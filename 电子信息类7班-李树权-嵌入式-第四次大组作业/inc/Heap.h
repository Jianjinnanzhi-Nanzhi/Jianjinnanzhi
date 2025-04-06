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

// 堆结构定义
typedef struct Heap 
{
    int* data;      // 存储堆元素的数组
    int capacity;   // 堆的最大容量
    int size;       // 堆当前元素个数
    bool isMaxHeap; // 标记是否为最大堆（true-最大堆，false-最小堆）
} Heap;

/*
  *创建堆
  * @param capacity: 堆容量
  * @param isMaxHeap: 是否最大堆
  * @return Heap(堆的指针)
  */
Heap* createHeap(int capacity, bool isMaxHeap);
 
/*
 * 插入元素
 * @param heap  堆指针
 * @param value 待插入值
 * @return true表示插入成功,false表示插入失败(已满)
 */
bool insert(Heap* heap, int value);

/**
 *弹出并删除堆顶元素
 * @param heap 堆指针
 * @return 堆顶值；若堆为空，返回-1;
 */
int pop(Heap* heap);


/**
 *获取堆顶元素
 * @param heap 堆指针
 * @return 堆顶值；若堆为空，返回-1;
 */
int peek(Heap* heap);

/**
 *判断堆是否为空
 * @param heap 堆指针
 * @return true为空,false为非空
 */
bool isEmpty(Heap* heap);

/**
 *获取当前堆元素个数
 * @param heap 堆指针
 * @return 元素个数
 */
int getSize(Heap* heap);

/**
 *释放堆内存
 * @param heap 堆指针
 * @return None
 */
void freeHeap(Heap* heap);

/**
*向上调整建堆排序
*@param arr 待排序数组
*@param n 数组长度
*@param ascending 是否升序排序（true为升序，false为降序）
*/
void heapSortWithShiftUp(int arr[], int n, bool ascending);

/**
*向下调整建堆排序
*@param arr 待排序数组
*@param n 数组长度
*@param ascending 是否升序排序（true为升序，false为降序）
*/
void heapSortWithShiftDown(int arr[], int n, bool ascending);

#endif // !HEAP_H

