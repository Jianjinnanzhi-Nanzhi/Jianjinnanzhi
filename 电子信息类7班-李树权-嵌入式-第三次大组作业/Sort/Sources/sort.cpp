#include "sort.h"
/************************************************************************************************************
 * @brief 以下是涉及插入排序的代码
 *************************************************************************************************************/

void insertion_sort(int arr[], int n)
{
	
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)//循环找到该插入的位置
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}//插入排序


/************************************************************************************************************
 * @brief 以下是涉及归并排序的代码
 *************************************************************************************************************/

void merge(int arr[], int tempArr[], int left, int mid, int right)
{
	//标记左半区第一个未排序的元素
	int l_pos = left;
	//标记右半区第一个未排序的元素
	int r_pos = mid + 1;
	//临时数组元素的下标
	int pos = left;

	//合并
	while (l_pos <= mid && r_pos <= right)
	{
		if (arr[l_pos] < arr[r_pos])//左半区第一个剩余元素更小,等号是为了排序稳定
			tempArr[pos++] = arr[l_pos++];
		else
			tempArr[pos++] = arr[r_pos++];
	}
	//合并左半区剩余的元素
	while (l_pos <= mid)
		tempArr[pos++] = arr[l_pos++];

	//合并右半区剩余的元素
	while (r_pos <= right)
		tempArr[pos++] = arr[r_pos++];

	//把临时数组中合并后的元素复制回来原来的数组
	while (left <= right)
	{
		arr[left] = tempArr[left];
		left++;
	}
}//合并


void msort(int arr[], int tempArr[], int left, int right)
{
	//如果只有一个元素,那么就不需要继续划分
	//只有一个元素的区域,本来就是有序的,只需要被归并即可
	if (left < right)
	{
		//找中间点
		int mid = (left + right) / 2;
		//递归划分左半区
		msort(arr, tempArr, left, mid);
		//递归划分右半区
		msort(arr, tempArr, mid + 1, right);
		//合并已经排序的部分
		merge(arr, tempArr, left, mid, right);
	}
}//归并排序


void merge_sort(int arr[], int n)
{
	//分配一个辅助数组
	int* tempArr = (int*)malloc(n * sizeof(int));
	if (tempArr)//辅助数组分配成功
	{
		msort(arr, tempArr, 0, n - 1);
		free(tempArr);
	}
	else
	{
		printf("error: failed to allocate memory");
	}
}//归并排序入口


/************************************************************************************************************
 * @brief 以下是涉及快速排序(递归)的代码
 *************************************************************************************************************/

void swap(int* e, int* f)
{
	int temp = *e;
	*e = *f;
	*f = temp;
}//数据交换函数

int partition(int arr[], int low, int high)//pivot为基准,arr最左边的索引,high最右边的索引
{
	int pivot = arr[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		//比pivot小的,全部换到前面去
		if (arr[j] < pivot)
			swap(&arr[j], &arr[i++]);
	}
	//此时,i指向的元素一定大于等于pivot
	swap(&arr[high], &arr[i]);

	return i;
}//划分

void qsort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = partition(arr, low, high);
		qsort(arr, low, mid - 1);//不断划分左半部分
		qsort(arr, mid + 1, high);//不断划分右半部分
	}
}//递归,不断划分最终排到正确排序

void quick_sort(int arr[], int len)
{
	qsort(arr, 0, len - 1);
}//快速排序

/************************************************************************************************************
 * @brief 以下是涉及计数排序的代码
 *************************************************************************************************************/

void counting_sort(int arr[], int len)
{
	if (len < 1) return;

	//寻找最大元素
	int max = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//分配一个长度为max+1的数组储存计数,并初始化为零
	int* count = (int*)malloc(sizeof(int) * (max + 1));
	memset(count, 0, sizeof(int) * (max + 1));//memset函数,用于将一块内存区域的每个字节设置为指定的值(区域,设置的值,要设置的字节数)

	//计数
	for (int i = 0; i < len; i++)
		count[arr[i]]++;

	//统计计数的累计值
	for (int i = 1; i < max + 1; i++)
	{
		count[i] += count[i - 1];
	}

	//创建一个临时数组保存结果
	int* output = (int*)malloc(sizeof(int) * len);

	//将元素放到正确的位置上(从后往前遍历,保持稳定性)
	for (int i = len - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//将结果复制回到原数组
	for (size_t i = 0; i < len; i++)
		arr[i] = output[i];
}//计数排序(适合数少的)

/************************************************************************************************************
 * @brief 以下是涉及基数计数排序的代码
 *************************************************************************************************************/

//取各个位的值
int GetNum(int a, int i) {
	int n;
	if (i == 1)
		n = a / 1 % 10;
	else {
		int k = (int)pow(10, i - 1);//pow(x,y)求解x的y次方
		n = a / k % 10;
	}
	return n;
}

void BaseSort_pre(int arr[], LinkQueue Q[], int len)
{
	int max = arr[0];
	// 找出数组中的最大值
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int maxDigit = 0;
	// 计算最大值的位数
	while (max > 0)
	{
		max /= 10;
		maxDigit++;
	}
	for (int i = 1; i <= maxDigit; ++i) //数组中最大值是几位数就需要循环几趟
	{
		for (int j = 0; j < len; ++j)
		{
			int k = GetNum(arr[j], i);        //获取arr数组中各个值在第i位上的值
			EnQueue(Q[k], arr[j]);         //将arr数组中各个值按照第i位的值插入对应队列
		}
		for (int j = 0, p = 0; j < len && p < len; ++j) //循环所有的链队列
		{
			while (!IsEmpty(Q[j])) 
			{        //若队列非空，循环出队并将出队的元素依次插入A表中
				int x;
				DeQueue(Q[j], x);
				arr[p] = x;
				p++;
			}
		}
	}
}//基数计数排序

void BaseSort(int arr[], int len)
{
	//声明链队列
	LinkQueue Q[10];
	//初始化链队列
	for (int i = 0; i < 10; ++i) 
	{
		InitQueue(Q[i]);
	}
	BaseSort_pre(arr, Q, len);
}//基数计数排序入口

