#include "sort.h"
/************************************************************************************************************
 * @brief �������漰��������Ĵ���
 *************************************************************************************************************/

void insertion_sort(int arr[], int n)
{
	
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)//ѭ���ҵ��ò����λ��
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}//��������


/************************************************************************************************************
 * @brief �������漰�鲢����Ĵ���
 *************************************************************************************************************/

void merge(int arr[], int tempArr[], int left, int mid, int right)
{
	//����������һ��δ�����Ԫ��
	int l_pos = left;
	//����Ұ�����һ��δ�����Ԫ��
	int r_pos = mid + 1;
	//��ʱ����Ԫ�ص��±�
	int pos = left;

	//�ϲ�
	while (l_pos <= mid && r_pos <= right)
	{
		if (arr[l_pos] < arr[r_pos])//�������һ��ʣ��Ԫ�ظ�С,�Ⱥ���Ϊ�������ȶ�
			tempArr[pos++] = arr[l_pos++];
		else
			tempArr[pos++] = arr[r_pos++];
	}
	//�ϲ������ʣ���Ԫ��
	while (l_pos <= mid)
		tempArr[pos++] = arr[l_pos++];

	//�ϲ��Ұ���ʣ���Ԫ��
	while (r_pos <= right)
		tempArr[pos++] = arr[r_pos++];

	//����ʱ�����кϲ����Ԫ�ظ��ƻ���ԭ��������
	while (left <= right)
	{
		arr[left] = tempArr[left];
		left++;
	}
}//�ϲ�


void msort(int arr[], int tempArr[], int left, int right)
{
	//���ֻ��һ��Ԫ��,��ô�Ͳ���Ҫ��������
	//ֻ��һ��Ԫ�ص�����,�������������,ֻ��Ҫ���鲢����
	if (left < right)
	{
		//���м��
		int mid = (left + right) / 2;
		//�ݹ黮�������
		msort(arr, tempArr, left, mid);
		//�ݹ黮���Ұ���
		msort(arr, tempArr, mid + 1, right);
		//�ϲ��Ѿ�����Ĳ���
		merge(arr, tempArr, left, mid, right);
	}
}//�鲢����


void merge_sort(int arr[], int n)
{
	//����һ����������
	int* tempArr = (int*)malloc(n * sizeof(int));
	if (tempArr)//�����������ɹ�
	{
		msort(arr, tempArr, 0, n - 1);
		free(tempArr);
	}
	else
	{
		printf("error: failed to allocate memory");
	}
}//�鲢�������


/************************************************************************************************************
 * @brief �������漰��������(�ݹ�)�Ĵ���
 *************************************************************************************************************/

void swap(int* e, int* f)
{
	int temp = *e;
	*e = *f;
	*f = temp;
}//���ݽ�������

int partition(int arr[], int low, int high)//pivotΪ��׼,arr����ߵ�����,high���ұߵ�����
{
	int pivot = arr[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		//��pivotС��,ȫ������ǰ��ȥ
		if (arr[j] < pivot)
			swap(&arr[j], &arr[i++]);
	}
	//��ʱ,iָ���Ԫ��һ�����ڵ���pivot
	swap(&arr[high], &arr[i]);

	return i;
}//����

void qsort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = partition(arr, low, high);
		qsort(arr, low, mid - 1);//���ϻ�����벿��
		qsort(arr, mid + 1, high);//���ϻ����Ұ벿��
	}
}//�ݹ�,���ϻ��������ŵ���ȷ����

void quick_sort(int arr[], int len)
{
	qsort(arr, 0, len - 1);
}//��������

/************************************************************************************************************
 * @brief �������漰��������Ĵ���
 *************************************************************************************************************/

void counting_sort(int arr[], int len)
{
	if (len < 1) return;

	//Ѱ�����Ԫ��
	int max = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//����һ������Ϊmax+1�����鴢�����,����ʼ��Ϊ��
	int* count = (int*)malloc(sizeof(int) * (max + 1));
	memset(count, 0, sizeof(int) * (max + 1));//memset����,���ڽ�һ���ڴ������ÿ���ֽ�����Ϊָ����ֵ(����,���õ�ֵ,Ҫ���õ��ֽ���)

	//����
	for (int i = 0; i < len; i++)
		count[arr[i]]++;

	//ͳ�Ƽ������ۼ�ֵ
	for (int i = 1; i < max + 1; i++)
	{
		count[i] += count[i - 1];
	}

	//����һ����ʱ���鱣����
	int* output = (int*)malloc(sizeof(int) * len);

	//��Ԫ�طŵ���ȷ��λ����(�Ӻ���ǰ����,�����ȶ���)
	for (int i = len - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//��������ƻص�ԭ����
	for (size_t i = 0; i < len; i++)
		arr[i] = output[i];
}//��������(�ʺ����ٵ�)

/************************************************************************************************************
 * @brief �������漰������������Ĵ���
 *************************************************************************************************************/

//ȡ����λ��ֵ
int GetNum(int a, int i) {
	int n;
	if (i == 1)
		n = a / 1 % 10;
	else {
		int k = (int)pow(10, i - 1);//pow(x,y)���x��y�η�
		n = a / k % 10;
	}
	return n;
}

void BaseSort_pre(int arr[], LinkQueue Q[], int len)
{
	int max = arr[0];
	// �ҳ������е����ֵ
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int maxDigit = 0;
	// �������ֵ��λ��
	while (max > 0)
	{
		max /= 10;
		maxDigit++;
	}
	for (int i = 1; i <= maxDigit; ++i) //���������ֵ�Ǽ�λ������Ҫѭ������
	{
		for (int j = 0; j < len; ++j)
		{
			int k = GetNum(arr[j], i);        //��ȡarr�����и���ֵ�ڵ�iλ�ϵ�ֵ
			EnQueue(Q[k], arr[j]);         //��arr�����и���ֵ���յ�iλ��ֵ�����Ӧ����
		}
		for (int j = 0, p = 0; j < len && p < len; ++j) //ѭ�����е�������
		{
			while (!IsEmpty(Q[j])) 
			{        //�����зǿգ�ѭ�����Ӳ������ӵ�Ԫ�����β���A����
				int x;
				DeQueue(Q[j], x);
				arr[p] = x;
				p++;
			}
		}
	}
}//������������

void BaseSort(int arr[], int len)
{
	//����������
	LinkQueue Q[10];
	//��ʼ��������
	for (int i = 0; i < 10; ++i) 
	{
		InitQueue(Q[i]);
	}
	BaseSort_pre(arr, Q, len);
}//���������������

