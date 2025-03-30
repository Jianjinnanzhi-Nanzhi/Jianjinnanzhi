#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "D:\\sort_data.txt" //��printf�����ǵ�ɾȥһ��'/'
#define ARRAY_SIZE 100     //�����С(�ɸ�)

void generate_random_array(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 1000; // ����0-999֮��������,�ɵ���Χ
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
}//���浽�ļ���

int main() {
    int k = 0;
    printf("   �ó�������ɲ������ݣ������浽�ļ���������100*k����100�����ݵ����飩   \n ");
    printf("������k��ֵ(kֵԽ��,�ȴ�ʱ��Խ��,�����ĵȴ�): ");
   
    scanf("%d", &k);
    
    printf("\n");
    printf("�������,�����ĵȴ�\n");
    printf("\n");
    
    FILE* fp;
    int array[ARRAY_SIZE];
    
    // ��ʼ�������������
    srand(time(0));

    // ���ļ�
    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("�޷������ļ� %s\n", FILENAME);
        return 1;
    }

    // ��һ��д��������������Ϣ
    fprintf(fp, "%d %d\n", 100*k, ARRAY_SIZE);

    // ���ɲ�����������
    for (int i = 0; i < 100*k; i++) 
    {
        generate_random_array(array, ARRAY_SIZE);
        save_array_to_file(fp, array, ARRAY_SIZE);
    }

    fclose(fp);
    printf("������ %d ����СΪ %d �����鲢���浽 %s\n", 100*k, ARRAY_SIZE, FILENAME);
    system("pause");
    return 0;
}