#include "Selection.h"

void Sswap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Spartition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // 选取最后一个元素为主元
    int i = low - 1;       // i 是小于主元的边界

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            Sswap(&arr[i], &arr[j]);
        }
    }
    Sswap(&arr[i + 1], &arr[high]); // 主元归位
    return i + 1;                  // 返回主元索引
}

// 非递归快速排序
void q_nSort(int arr[], int low, int high) 
{
    // 创建栈，存储待排序区间
    Stack* stack = createStack(high - low + 1);
    push(stack, low);
    push(stack, high);

    while (!isEmpty(stack)) 
    {
        // 取出一个待排序区间
        high = pop(stack);
        low = pop(stack);

        // 分区
        int pivotIndex = Spartition(arr, low, high);

        // 左半部分入栈（如果存在）
        if (pivotIndex - 1 > low) 
        {
            push(stack, low);
            push(stack, pivotIndex - 1);
        }

        // 右半部分入栈（如果存在）
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
}//快速排序(入口)


void bubbleSort1(int arr[], int n) 
{
    int swap; // 标志位，记录是否发生交换
    for (int i = 0; i < n - 1; i++) 
    {
        swap = 0; // 初始化为未交换
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                Sswap(&arr[j], &arr[j + 1]);// 交换 arr[j] 和 arr[j+1]
                swap = 1; // 标记发生交换
            }
        }      
        if (!swap) break;// 如果本轮没有交换，说明已经有序，直接退出
    }
}//冒泡排序--优化1(标志位优化)

void bubbleSort2(int arr[], int n) 
{
    int lSwap = n - 1; // 初始化最后交换位置
    for (int i = 0; i < n - 1; i++) 
    {
        int cSwap = -1; // 当前轮次最后交换的位置
        for (int j = 0; j < lSwap; j++) 
        {
            if (arr[j] > arr[j + 1])
            {
                Sswap(&arr[j], &arr[j + 1]);// 交换 arr[j] 和 arr[j+1]
                cSwap= j; // 更新最后交换位置
            }
        }      
        if (cSwap == -1) break;// 如果没有交换，说明已经有序
        lSwap = cSwap; // 更新下一轮的遍历范围
    }
}//冒泡排序--优化2(记录最后一次交换位置)


void bubbleSort3(int arr[], int n) 
{
    int left = 0, right = n - 1;
    while (left < right) 
    {
       
        for (int i = left; i < right; i++)  // 从左到右冒泡（找最大值）
        {
            if (arr[i] > arr[i + 1]) 
            {
                Sswap(&arr[i], &arr[i + 1]);
            }
        }
        right--; // 最大值已到最右，缩小右边界
   
        for (int i = right; i > left; i--) // 从右到左冒泡（找最小值）
        {
            if (arr[i] < arr[i - 1])
            {
                Sswap(&arr[i], &arr[i - 1]);
            }
        }
        left++; // 最小值已到最左，缩小左边界
    }
}//冒泡排序--优化3(双向冒泡排序)


// 随机选择主元，并交换到末尾
void RandomPivot(int arr[], int low, int high) 
{
    srand(time(0));// 初始化随机数种子
    int Index = low + rand() % (high - low + 1);
    Sswap(&arr[Index], &arr[high]); // 把随机主元放到最后
}

// 分区函数（升序）
int Epartition(int arr[], int low, int high) 
{
    RandomPivot(arr, low, high); // 随机主元优化
    int pivot = arr[high]; // 主元
    int i = low - 1;       // i 是小于主元的边界

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            Sswap(&arr[i], &arr[j]);
        }
    }
    Sswap(&arr[i + 1], &arr[high]); 
    return i + 1;                  // 返回主元索引
}


void EquickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot = Epartition(arr, low, high);
        EquickSort(arr, low, pivot - 1); // 排序左半部分
        EquickSort(arr, pivot + 1, high); // 排序右半部分
    }
}//快速排序(随机)

void quick_ESort(int arr[], int len)
{
    EquickSort(arr, 0, len - 1);
}//快速排序(递归版随机)(入口)


void DPQuickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        if (arr[low] > arr[high]) 
        {
            Sswap(&arr[low], &arr[high]); // 确保 arr[low] <= arr[high]
        }

        int pivot1 = arr[low];  // 左主元
        int pivot2 = arr[high]; // 右主元

        int lt = low + 1;  // 小于 pivot1 的边界
        int gt = high - 1; // 大于 pivot2 的边界
        int i = low + 1;   // 当前遍历指针

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

        // 将主元放到正确位置
        Sswap(&arr[low], &arr[lt - 1]);
        Sswap(&arr[high], &arr[gt + 1]);

        // 递归排序三个子数组
        DPQuickSort(arr, low, lt - 2); // 左部分
        DPQuickSort(arr, lt, gt);      // 中间部分
        DPQuickSort(arr, gt + 2, high); // 右部分
    }
}// 快速排序（三枢轴优化）

void quick_DPSort(int arr[], int len)
{
    DPQuickSort(arr, 0, len - 1);
}// 快速排序（三枢轴优化）(入口)


