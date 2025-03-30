#include "Selection.h"

void Sswap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Spartition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // ѡȡ���һ��Ԫ��Ϊ��Ԫ
    int i = low - 1;       // i ��С����Ԫ�ı߽�

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            Sswap(&arr[i], &arr[j]);
        }
    }
    Sswap(&arr[i + 1], &arr[high]); // ��Ԫ��λ
    return i + 1;                  // ������Ԫ����
}

// �ǵݹ��������
void q_nSort(int arr[], int low, int high) 
{
    // ����ջ���洢����������
    Stack* stack = createStack(high - low + 1);
    push(stack, low);
    push(stack, high);

    while (!isEmpty(stack)) 
    {
        // ȡ��һ������������
        high = pop(stack);
        low = pop(stack);

        // ����
        int pivotIndex = Spartition(arr, low, high);

        // ��벿����ջ��������ڣ�
        if (pivotIndex - 1 > low) 
        {
            push(stack, low);
            push(stack, pivotIndex - 1);
        }

        // �Ұ벿����ջ��������ڣ�
        if (pivotIndex + 1 < high) 
        {
            push(stack, pivotIndex + 1);
            push(stack, high);
        }
    }

    free(stack->data);
    free(stack);
}

void quick_nSort(int arr[], int len)
{
    q_nSort(arr, 0, len - 1);
}//��������(���)


void bubbleSort1(int arr[], int n) 
{
    int swap; // ��־λ����¼�Ƿ�������
    for (int i = 0; i < n - 1; i++) 
    {
        swap = 0; // ��ʼ��Ϊδ����
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                Sswap(&arr[j], &arr[j + 1]);// ���� arr[j] �� arr[j+1]
                swap = 1; // ��Ƿ�������
            }
        }      
        if (!swap) break;// �������û�н�����˵���Ѿ�����ֱ���˳�
    }
}//ð������--�Ż�1(��־λ�Ż�)

void bubbleSort2(int arr[], int n) 
{
    int lSwap = n - 1; // ��ʼ����󽻻�λ��
    for (int i = 0; i < n - 1; i++) 
    {
        int cSwap = -1; // ��ǰ�ִ���󽻻���λ��
        for (int j = 0; j < lSwap; j++) 
        {
            if (arr[j] > arr[j + 1])
            {
                Sswap(&arr[j], &arr[j + 1]);// ���� arr[j] �� arr[j+1]
                cSwap= j; // ������󽻻�λ��
            }
        }      
        if (cSwap == -1) break;// ���û�н�����˵���Ѿ�����
        lSwap = cSwap; // ������һ�ֵı�����Χ
    }
}//ð������--�Ż�2(��¼���һ�ν���λ��)


void bubbleSort3(int arr[], int n) 
{
    int left = 0, right = n - 1;
    while (left < right) 
    {
       
        for (int i = left; i < right; i++)  // ������ð�ݣ������ֵ��
        {
            if (arr[i] > arr[i + 1]) 
            {
                Sswap(&arr[i], &arr[i + 1]);
            }
        }
        right--; // ���ֵ�ѵ����ң���С�ұ߽�
   
        for (int i = right; i > left; i--) // ���ҵ���ð�ݣ�����Сֵ��
        {
            if (arr[i] < arr[i - 1])
            {
                Sswap(&arr[i], &arr[i - 1]);
            }
        }
        left++; // ��Сֵ�ѵ�������С��߽�
    }
}//ð������--�Ż�3(˫��ð������)


// ���ѡ����Ԫ����������ĩβ
void RandomPivot(int arr[], int low, int high) 
{
    srand(time(0));// ��ʼ�����������
    int Index = low + rand() % (high - low + 1);
    Sswap(&arr[Index], &arr[high]); // �������Ԫ�ŵ����
}

// ��������������
int Epartition(int arr[], int low, int high) 
{
    RandomPivot(arr, low, high); // �����Ԫ�Ż�
    int pivot = arr[high]; // ��Ԫ
    int i = low - 1;       // i ��С����Ԫ�ı߽�

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            Sswap(&arr[i], &arr[j]);
        }
    }
    Sswap(&arr[i + 1], &arr[high]); 
    return i + 1;                  // ������Ԫ����
}


void EquickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot = Epartition(arr, low, high);
        EquickSort(arr, low, pivot - 1); // ������벿��
        EquickSort(arr, pivot + 1, high); // �����Ұ벿��
    }
}//��������(���)

void quick_ESort(int arr[], int len)
{
    EquickSort(arr, 0, len - 1);
}//��������(�ݹ�����)(���)


void DPQuickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        if (arr[low] > arr[high]) 
        {
            Sswap(&arr[low], &arr[high]); // ȷ�� arr[low] <= arr[high]
        }

        int pivot1 = arr[low];  // ����Ԫ
        int pivot2 = arr[high]; // ����Ԫ

        int lt = low + 1;  // С�� pivot1 �ı߽�
        int gt = high - 1; // ���� pivot2 �ı߽�
        int i = low + 1;   // ��ǰ����ָ��

        while (i <= gt) 
        {
            if (arr[i] < pivot1) 
            {
                Sswap(&arr[i], &arr[lt]);
                lt++;
                i++;
            }
            else if (arr[i] > pivot2) 
            {
                Sswap(&arr[i], &arr[gt]);
                gt--;
            }
            else 
            {
                i++;
            }
        }

        // ����Ԫ�ŵ���ȷλ��
        Sswap(&arr[low], &arr[lt - 1]);
        Sswap(&arr[high], &arr[gt + 1]);

        // �ݹ���������������
        DPQuickSort(arr, low, lt - 2); // �󲿷�
        DPQuickSort(arr, lt, gt);      // �м䲿��
        DPQuickSort(arr, gt + 2, high); // �Ҳ���
    }
}// ���������������Ż���

void quick_DPSort(int arr[], int len)
{
    DPQuickSort(arr, 0, len - 1);
}// ���������������Ż���(���)


