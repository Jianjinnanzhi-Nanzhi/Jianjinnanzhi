#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include <windows.h>

#define FILENAME "D:\\sort_data.txt"      //未排序的数据文件
#define SFILENAME "D:\\sorted_data.txt"   //已排序的数据文件

void read_fdata(FILE* fp, int sort)
{
    int num_arrays, array_size;
    int* array;


    // 打开文件
    fp = fopen(FILENAME, "r");
    FILE* file = fopen(SFILENAME, "w");

    if (fp == NULL)
    {
        printf("无法打开文件 %s\n", FILENAME);
        return;
    }

    if (file == NULL)
    {
        perror("无法创建输出文件");
        return;
    }

    // 读取数组数量和信息
    if (fscanf(fp, "%d %d", &num_arrays, &array_size) != 2)
    {
        printf("文件格式错误\n");
        fclose(fp);
        return;
    };
    fprintf(file, "%d %d\n", num_arrays, array_size);

    // 分配数组内存
    array = (int*)malloc(array_size * sizeof(int));
    if (array == NULL)
    {
        printf("内存分配失败\n");
        fclose(fp);
        return;
    }

    // 读取并排序每个数组
    for (int i = 0; i < num_arrays; i++)
    {
        // 读取数组
        for (int j = 0; j < array_size; j++)
        {
            fscanf(fp, "%d", &array[j]);
        }
        // 排序数组
        switch (sort)
        {
        case 1:
            insertion_sort(array, array_size);
            break;
        case 2:
            merge_sort(array, array_size);
            break;
        case 3:
            quick_sort(array, array_size);
            break;
        case 4:
            counting_sort(array, array_size);
            break;
        case 5:
            BaseSort(array, array_size);
            break;
        default:
            break;
        }
        for (int j = 0; j < array_size; j++)
        {
            fprintf(file, "%d", array[j]);
            if (i < array_size - 1) 
                fprintf(file, " ");
        }
        fprintf(file, "\n");
    }
    // 释放资源
    free(array);
    fclose(fp);
    fclose(file);
    
    printf("排序完成\n");
    printf(" - 排序数组数量: %d\n", num_arrays);
    printf(" - 每个数组大小: %d\n", array_size);
    printf(" - 生成的已排序数据的文件地址为%s", SFILENAME);
}
 

int main() 
{ 
    int sort = 0;
    printf("   该程序为排序数据程序,读取文件的地址为D:\\sort_data.txt,若读取其他文件,请确保该文件的数据格式合适且请在源程序更换地址  \n");
    printf("选择排序方法:1.插入排序  2.归并排序  3.快速排序  4.计数排序  5.基数计数排序\n");
    printf("请输入所选排序方法的序号(1-5):");
    scanf("%d", &sort);
    while (1)
    {
        if (sort < 1 || sort>5)
        {
            printf("格式错误,请重新输入:");
            scanf("%d", &sort);
        }
        else
            break;
    }
    printf("\n");
    printf("无需操作,请耐心等待\n");
    printf("\n");
    FILE* fp=NULL;
    read_fdata(fp, sort);
    printf("\n");
    system("pause");
    return 0;
}