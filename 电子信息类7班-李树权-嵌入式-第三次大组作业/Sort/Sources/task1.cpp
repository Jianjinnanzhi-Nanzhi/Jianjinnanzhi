#include <time.h>
#include "sort.h"
#include <windows.h>

// �����������
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 100000; // ����0-99999֮��������
    }
}


void testSortPerformance(int size,int sort) 
{
    // �����������,��ֹ����������ظ�
    srand(time(0));

    LARGE_INTEGER start, end, frequency;

    // ��ȡ��ʱ��Ƶ�ʣ�ÿ�����������
    QueryPerformanceFrequency(&frequency);

    // ��¼��ʼʱ��
    QueryPerformanceCounter(&start);
   
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) 
    {
        printf("�ڴ����ʧ��!\n");
        return;
    }

    // �����������
    generateRandomArray(arr, size);

    // ִ������
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
   
    // ��¼����ʱ��
    QueryPerformanceCounter(&end);
    // �����ʱ���룩
    double time_elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("������: %d, ������ʱ: %.3f ����\n", size, time_elapsed*1000.0);//������λС��,�������ȷ���޸�

    free(arr);
}// ��������������ʱ

int main() 
{
    printf("�ò��Գ�����������λС��,�������ȷ�����ݿ���Դ�����޸�,��������Ҫһ��ʱ������,�����ĵȴ�\n\n");
    
    // ���Բ�ͬ������
    for (int i = 1; i <=5; i++)
    {
        switch (i)
        {
        case 1:
            printf("�����������ܲ���:\n");
            break;
        case 2:
            printf("�鲢�������ܲ���:\n");
            break;
        case 3:
            printf("�����������ܲ���:\n");
            break;
        case 4:
            printf("�����������ܲ���:\n");
            break;
        case 5:
            printf("���������������ܲ���:\n");
            break;
        default:
            break;
        }
        testSortPerformance(10000,i);
        testSortPerformance(50000,i);
        testSortPerformance(200000,i);
        printf("\n");
    }//1��5�ֱ���� ��������,�鲢����,��������,��������,������������
    system("pause");
    return 0;
}
