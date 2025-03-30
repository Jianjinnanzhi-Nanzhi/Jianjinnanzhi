#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include <time.h>
#include <windows.h>

// �����������
void generate_random_array(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 1000; // ����0-999֮��������
    }
}

// ��������
void copy_array(int src[], int dest[], int n)//dest[]Ϊ���Ƶ�����
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

void testSort(int k,int sort)
{
    const int size = 100;      // ÿ������Ĵ�С
    const int sort_num = 100*k; // �������
    int o_array[size];     // ԭʼ����
    int t_array[size];      // ��ʱ������������

    // �����������,��ֹ����������ظ�
    srand(time(0));

    // ����ԭʼ�������
    generate_random_array(o_array, size);

    LARGE_INTEGER start, end, frequency;

    // ��ȡ��ʱ��Ƶ�ʣ�ÿ�����������
    QueryPerformanceFrequency(&frequency);

    // ��¼��ʼʱ��
    QueryPerformanceCounter(&start);

    // ִ�ж������
    switch (sort)
    {
    case 1:
        for (int i = 0; i < sort_num; i++) 
        {
            copy_array(o_array, t_array, size); // ÿ��ʹ��ԭʼ����ĸ�����������
            insertion_sort(t_array, size);          
        }
        printf("\n��������Ĳ��Խ����\n");
        break;
    case 2:
        for (int i = 0; i < sort_num; i++)
        {
            copy_array(o_array, t_array, size); // ÿ��ʹ��ԭʼ����ĸ�����������
            merge_sort(t_array, size);          
        }
        printf("\n�鲢����Ĳ��Խ����\n");
        break;
    case 3:
        for (int i = 0; i < sort_num; i++)
        {
            copy_array(o_array, t_array, size); // ÿ��ʹ��ԭʼ����ĸ�����������
            quick_sort(t_array, size);       
        }
        printf("\n��������Ĳ��Խ����\n");
        break;
    case 4:
        for (int i = 0; i < sort_num; i++)
        {
            copy_array(o_array, t_array, size); // ÿ��ʹ��ԭʼ����ĸ�����������
            counting_sort(t_array, size);
        }
        printf("\n��������Ĳ��Խ����\n");
        break;
    case 5:
        for (int i = 0; i < sort_num; i++)
        {
            copy_array(o_array, t_array, size); // ÿ��ʹ��ԭʼ����ĸ�����������
            BaseSort(t_array, size); 
        }
        printf("\n������������Ĳ��Խ����\n");
        break;
    default:
        break;
    }
    
    // ��¼����ʱ��
    QueryPerformanceCounter(&end);
    // �����ʱ���룩
    double time_elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    // ����ƽ��ÿ��������ʱ��΢�룩
    double avg_time = (time_elapsed * 1000000.0) / sort_num;
 
    printf(" - ����ʱ: %.3f ��\n", time_elapsed);
    printf(" - ƽ��ÿ��������ʱ: %.3f ΢��\n", avg_time);

}

int main() 
{
    int k=0;
    printf("       �ó������������(����,�鲢,����,����,��������)�ڴ���С�������µ�������ʱ����100������*100k������     \n ");
    printf("������k��ֵ(kֵԽ��,�ȴ�ʱ��Խ��,�����ĵȴ�): ");
    
    scanf("%d",&k);
    
    printf("\n");
    
    printf("�������ã�\n");
    printf(" - �����С: %d\n", 100);
    printf(" - �������: %d\n", 100*k);
   
    for (int i = 1; i <= 5; i++)
    {
        testSort(k, i);
    }//1��5�ֱ���� ��������,�鲢����,��������,��������,������������
   
    system("pause");
    return 0;
}