#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "D:\\sort_data.txt" //在printf函数记得删去一条'/'
#define ARRAY_SIZE 100     //数组大小(可改)

void generate_random_array(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 1000; // 生成0-999之间的随机数,可调范围
    }
}

void save_array_to_file(FILE* fp, int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        fprintf(fp, "%d", arr[i]);
        if (i < n - 1) fprintf(fp, " ");
    }
    fprintf(fp, "\n");
}//储存到文件中

int main() {
    int k = 0;
    printf("   该程序可生成测试数据，并保存到文件（如生成100*k个含100个数据的数组）   \n ");
    printf("请输入k的值(k值越大,等待时间越长,请耐心等待): ");
   
    scanf("%d", &k);
    
    printf("\n");
    printf("无需操作,请耐心等待\n");
    printf("\n");
    
    FILE* fp;
    int array[ARRAY_SIZE];
    
    // 初始化随机数生成器
    srand(time(0));

    // 打开文件
    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("无法创建文件 %s\n", FILENAME);
        return 1;
    }

    // 第一行写入数组数量和信息
    fprintf(fp, "%d %d\n", 100*k, ARRAY_SIZE);

    // 生成并保存多个数组
    for (int i = 0; i < 100*k; i++) 
    {
        generate_random_array(array, ARRAY_SIZE);
        save_array_to_file(fp, array, ARRAY_SIZE);
    }

    fclose(fp);
    printf("已生成 %d 个大小为 %d 的数组并保存到 %s\n", 100*k, ARRAY_SIZE, FILENAME);
    system("pause");
    return 0;
}