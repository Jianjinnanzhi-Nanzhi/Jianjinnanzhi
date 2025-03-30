#include <time.h>
#include "sort.h"
#include <windows.h>

// 生成随机数组
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 100000; // 生成0-99999之间的随机数
    }
}


void testSortPerformance(int size,int sort) 
{
    // 设置随机种子,防止随机生成数重复
    srand(time(0));

    LARGE_INTEGER start, end, frequency;

    // 获取计时器频率（每秒计数次数）
    QueryPerformanceFrequency(&frequency);

    // 记录开始时间
    QueryPerformanceCounter(&start);
   
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) 
    {
        printf("内存分配失败!\n");
        return;
    }

    // 生成随机数组
    generateRandomArray(arr, size);

    // 执行排序
    switch (sort)
    {
    case 1:
        insertion_sort(arr, size);
        break;
    case 2:
        merge_sort(arr, size);
        break;
    case 3:
        quick_sort(arr, size);
        break;
    case 4:
        counting_sort(arr, size);
        break;
    case 5:
        BaseSort(arr, size);
        break;
    default:
        break;
    }
   
    // 记录结束时间
    QueryPerformanceCounter(&end);
    // 计算耗时（秒）
    double time_elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("数据量: %d, 排序用时: %.3f 毫秒\n", size, time_elapsed*1000.0);//保留三位小数,若需更精确可修改

    free(arr);
}// 测试排序函数并计时

int main() 
{
    printf("该测试程序结果保留三位小数,若需更精确的数据可在源程序修改,且数据需要一定时间生成,请耐心等待\n\n");
    
    // 测试不同数据量
    for (int i = 1; i <=5; i++)
    {
        switch (i)
        {
        case 1:
            printf("插入排序性能测试:\n");
            break;
        case 2:
            printf("归并排序性能测试:\n");
            break;
        case 3:
            printf("快速排序性能测试:\n");
            break;
        case 4:
            printf("计数排序性能测试:\n");
            break;
        case 5:
            printf("基数计数排序性能测试:\n");
            break;
        default:
            break;
        }
        testSortPerformance(10000,i);
        testSortPerformance(50000,i);
        testSortPerformance(200000,i);
        printf("\n");
    }//1到5分别代表 插入排序,归并排序,快速排序,计数排序,基数计数排序
    system("pause");
    return 0;
}
