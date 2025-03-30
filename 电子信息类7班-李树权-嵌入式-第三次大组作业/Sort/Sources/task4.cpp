#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include <windows.h>

#define FILENAME "D:\\sort_data.txt"      //δ����������ļ�
#define SFILENAME "D:\\sorted_data.txt"   //������������ļ�

void read_fdata(FILE* fp, int sort)
{
    int num_arrays, array_size;
    int* array;


    // ���ļ�
    fp = fopen(FILENAME, "r");
    FILE* file = fopen(SFILENAME, "w");

    if (fp == NULL)
    {
        printf("�޷����ļ� %s\n", FILENAME);
        return;
    }

    if (file == NULL)
    {
        perror("�޷���������ļ�");
        return;
    }

    // ��ȡ������������Ϣ
    if (fscanf(fp, "%d %d", &num_arrays, &array_size) != 2)
    {
        printf("�ļ���ʽ����\n");
        fclose(fp);
        return;
    };
    fprintf(file, "%d %d\n", num_arrays, array_size);

    // ���������ڴ�
    array = (int*)malloc(array_size * sizeof(int));
    if (array == NULL)
    {
        printf("�ڴ����ʧ��\n");
        fclose(fp);
        return;
    }

    // ��ȡ������ÿ������
    for (int i = 0; i < num_arrays; i++)
    {
        // ��ȡ����
        for (int j = 0; j < array_size; j++)
        {
            fscanf(fp, "%d", &array[j]);
        }
        // ��������
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
    // �ͷ���Դ
    free(array);
    fclose(fp);
    fclose(file);
    
    printf("�������\n");
    printf(" - ������������: %d\n", num_arrays);
    printf(" - ÿ�������С: %d\n", array_size);
    printf(" - ���ɵ����������ݵ��ļ���ַΪ%s", SFILENAME);
}
 

int main() 
{ 
    int sort = 0;
    printf("   �ó���Ϊ�������ݳ���,��ȡ�ļ��ĵ�ַΪD:\\sort_data.txt,����ȡ�����ļ�,��ȷ�����ļ������ݸ�ʽ����������Դ���������ַ  \n");
    printf("ѡ�����򷽷�:1.��������  2.�鲢����  3.��������  4.��������  5.������������\n");
    printf("��������ѡ���򷽷������(1-5):");
    scanf("%d", &sort);
    while (1)
    {
        if (sort < 1 || sort>5)
        {
            printf("��ʽ����,����������:");
            scanf("%d", &sort);
        }
        else
            break;
    }
    printf("\n");
    printf("�������,�����ĵȴ�\n");
    printf("\n");
    FILE* fp=NULL;
    read_fdata(fp, sort);
    printf("\n");
    system("pause");
    return 0;
}