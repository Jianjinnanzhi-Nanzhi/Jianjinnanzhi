#include "Application.h"

void sort012(int arr[], int n) 
{
    int low = 0, mid = 0, high = n - 1;//low指向已排序的0的末尾的下一个位置,mid为当前检查的元素位置,high指向已排序的2的开头的前一个位置

    for (; mid<=high;)//一旦mid超过high,说明数组数据已经全部排序完毕 
    {
        switch (arr[mid]) 
        {
        case 0:         
            arr[mid] = arr[low];
            arr[low] = 0;// 交换low和mid位置的元素
            low++;//往后移一位
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:          
            arr[mid] = arr[high];
            arr[high] = 2; // 交换mid和high位置的元素
            high--;//往前移一位
            break;
        }
    }
}


//快速排序的时间复杂度为O(nlog n),而寻找数据的时间的复杂度为O(1),所以加起来刚好O(nlog n)
int findKthSmallest(int arr[], int n, int k)
{
    quick_sort(arr, n - 1); // 先排序
    return arr[k - 1];         // 返回第K小的数（数组索引从0开始）
}// 找第K大的数（k从1开始）


int findKthLargest(int arr[], int n, int k) 
{
    quick_sort(arr, n - 1); // 先排序
    return arr[n - k];         // 返回第K大的数（数组索引从0开始）
}// 找第K小的数（k从1开始）


