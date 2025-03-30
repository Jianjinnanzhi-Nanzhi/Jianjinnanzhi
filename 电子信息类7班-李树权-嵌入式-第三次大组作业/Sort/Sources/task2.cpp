#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include <time.h>
#include <windows.h>

// 生成随机数组
void generate_random_array(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 1000; // 生成0-999之间的随机数
    }
}

// 复制数组
void copy_array(int src[], int dest[], int n)//dest[]为复制的数组
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

void testSort(int k,int sort)
{
    const int size = 100;      // 每个数组的大小
    const int sort_num = 100*k; // 排序次数
    int o_array[size];     // 原始数组
    int t_array[size];      // 临时数组用于排序

    // 设置随机种子,防止随机生成数重复
    srand(time(0));

    // 生成原始随机数组
    generate_random_array(o_array, size);

    LARGE_INTEGER start, end, frequency;

    // 获取计时器频率（每秒计数次数）
    QueryPerformanceFrequency(&frequency);

    // 记录开始时间
    QueryPerformanceCounter(&start);

    // 执行多次排序
    switch (sort)
    {
    case 1:
        for (int i = 0; i < sort_num; i++) 
        {
            copy_array(o_array, t_array, size); // 每次使用原始数组的副本进行排序
            insertion_sort(t_array, size);          
        }
        printf("\n插入排序的测试结果：\n");
        break;
    case 2:
        for (int i = 0; i < sort_num; i++)
        {
            copy_array(o_array, t_array, size); // 每次使用原始数组的副本进行排序
            merge_sort(t_array, size);          
        }
        printf("\n归并排序的测试结果：\n");
        break;
    case 3:
        for (int i = 0; i < sort_num; i++)
        {
            copy_array(o_array, t_array, size); // 每次使用原始数组的副本进行排序
            quick_sort(t_array, size);       
        }
        printf("\n快速排序的测试结果：\n");
        break;
    case 4:
        for (int i = 0; i < sort_num; i++)
        {
            copy_array(o_array, t_array, size); // 每次使用原始数组的副本进行排序
            counting_sort(t_array, size);
        }
        printf("\n计数排序的测试结果：\n");
        break;
    case 5:
        for (int i = 0; i < sort_num; i++)
        {
            copy_array(o_array, t_array, size); // 每次使用原始数组的副本进行排序
            BaseSort(t_array, size); 
        }
        printf("\n基数计数排序的测试结果：\n");
        break;
    default:
        break;
    }
    
    // 记录结束时间
    QueryPerformanceCounter(&end);
    // 计算耗时（秒）
    double time_elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    // 计算平均每次排序用时（微秒）
    double avg_time = (time_elapsed * 1000000.0) / sort_num;
 
    printf(" - 总用时: %.3f 秒\n", time_elapsed);
    printf(" - 平均每次排序用时: %.3f 微秒\n", avg_time);

}

int main() 
{
    int k=0;
    printf("       该程序输出排序函数(插入,归并,快速,计数,基数计数)在大量小数据量下的排序用时（如100个数据*100k次排序）     \n ");
    printf("请输入k的值(k值越大,等待时间越长,请耐心等待): ");
    
    scanf("%d",&k);
    
    printf("\n");
    
    printf("测试配置：\n");
    printf(" - 数组大小: %d\n", 100);
    printf(" - 排序次数: %d\n", 100*k);
   
    for (int i = 1; i <= 5; i++)
    {
        testSort(k, i);
    }//1到5分别代表 插入排序,归并排序,快速排序,计数排序,基数计数排序
   
    system("pause");
    return 0;
}