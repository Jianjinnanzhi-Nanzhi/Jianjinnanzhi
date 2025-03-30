#include "Application.h"

void sort012(int arr[], int n) 
{
    int low = 0, mid = 0, high = n - 1;//lowָ���������0��ĩβ����һ��λ��,midΪ��ǰ����Ԫ��λ��,highָ���������2�Ŀ�ͷ��ǰһ��λ��

    for (; mid<=high;)//һ��mid����high,˵�����������Ѿ�ȫ��������� 
    {
        switch (arr[mid]) 
        {
        case 0:         
            arr[mid] = arr[low];
            arr[low] = 0;// ����low��midλ�õ�Ԫ��
            low++;//������һλ
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:          
            arr[mid] = arr[high];
            arr[high] = 2; // ����mid��highλ�õ�Ԫ��
            high--;//��ǰ��һλ
            break;
        }
    }
}


//���������ʱ�临�Ӷ�ΪO(nlog n),��Ѱ�����ݵ�ʱ��ĸ��Ӷ�ΪO(1),���Լ������պ�O(nlog n)
int findKthSmallest(int arr[], int n, int k)
{
    quick_sort(arr, n - 1); // ������
    return arr[k - 1];         // ���ص�KС����������������0��ʼ��
}// �ҵ�K�������k��1��ʼ��


int findKthLargest(int arr[], int n, int k) 
{
    quick_sort(arr, n - 1); // ������
    return arr[n - k];         // ���ص�K�����������������0��ʼ��
}// �ҵ�KС������k��1��ʼ��


