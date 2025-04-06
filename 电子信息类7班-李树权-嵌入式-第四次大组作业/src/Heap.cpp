#include "Heap.h"

//创建堆
Heap* createHeap(int capacity, bool isMaxHeap) 
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    heap->isMaxHeap = isMaxHeap;
    return heap;
}

// 向上调整（堆化）
void shiftUp(Heap* heap, int i) 
{
    while (i > 0) 
    {
        int p = (i - 1) / 2;//获取父节点
        
        // 根据堆类型决定比较方向
       //根据堆的性质判断是否需要交换父子节点
        bool shouldSwap = heap->isMaxHeap ? (heap->data[i] > heap->data[p]) :(heap->data[i] < heap->data[p]);

        if (shouldSwap) 
        {
            // 交换父子节点
            int temp = heap->data[i];
            heap->data[i] = heap->data[p];
            heap->data[p] = temp;
            i = p;  // 继续向上检查
        }
        else 
        {
            break;
        }
    }
}

// 插入元素
bool insert(Heap* heap, int value) 
{
    if (heap->size >= heap->capacity) 
    {        
        return false;
    }

    // 将新元素放到末尾
    heap->data[heap->size] = value;
    // 向上调整
    shiftUp(heap, heap->size);
    heap->size++;
    return true;
}

// 向下调整（堆化）
void shiftDown(Heap* heap, int i) 
{
    int MaxorMin = i; // 记录当前节点及其子节点中最大/最小值的索引
    int l = 2 * i + 1;//获取左孩子
    int r = 2 * i + 2;//获取右孩子

    // 左孩子比较
    if (l < heap->size) 
    {
        //根据堆的性质判断是否需要交换父子节点
        bool shouldUpdate = heap->isMaxHeap ?(heap->data[l] > heap->data[MaxorMin]) :(heap->data[l] < heap->data[MaxorMin]); 
        if (shouldUpdate) 
        {
            MaxorMin = l;
        }
    }

    // 右孩子比较
    if (r < heap->size)
    {
        //根据堆的性质判断是否需要交换父子节点
        bool shouldUpdate = heap->isMaxHeap ? (heap->data[r] > heap->data[MaxorMin]) :(heap->data[r] < heap->data[MaxorMin]);
        if (shouldUpdate) 
        {
            MaxorMin = r;
        }
    }

    // 如果需要交换
    if (MaxorMin != i) 
    {
        int temp = heap->data[i];
        heap->data[i] = heap->data[MaxorMin];
        heap->data[MaxorMin] = temp;
        // 递归向下调整
        shiftDown(heap, MaxorMin);
    }
}

// 删除并获取堆顶元素
int pop(Heap* heap) 
{
    if (heap->size <= 0)
    {       
        return -1;//root可能为0,所以用-1
    }

    int root = heap->data[0];
    // 将最后一个元素移到根位置
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    // 向下调整
    shiftDown(heap, 0);

    return root;
}

// 获取堆顶元素
int peek(Heap* heap) 
{
    if (heap->size <= 0)
    {      
        return -1;// heap->data[0]可能为0,所以用-1
    }
    return heap->data[0];
}

// 判断堆是否为空
bool isEmpty(Heap* heap) 
{
    return heap->size == 0;
}

// 获取当前元素个数
int getSize(Heap* heap) 
{
    return heap->size;
}

// 释放堆内存
void freeHeap(Heap* heap) 
{
    free(heap->data);
    free(heap);
}

// 向上调整建堆排序
void heapSortWithShiftUp(int arr[], int n, bool ascending) 
{
    // 创建一个临时堆
    Heap* heap = createHeap(n, !ascending); // 排序方向与堆类型相反

    // 插入所有元素（向上调整建堆）
    for (int i = 0; i < n; i++)
    {
        insert(heap, arr[i]);
    }

    // 依次取出元素
    for (int i = 0; i < n; i++) 
    {
        arr[i] = pop(heap);
    }

    freeHeap(heap);
}

// 向下调整建堆排序（更高效）
void heapSortWithShiftDown(int arr[], int n, bool ascending) 
{
    // 首先将数组视为一个堆，然后从最后一个非叶子节点开始向下调整

    // 创建虚拟堆结构
    Heap heap;
    heap.data = arr;
    heap.capacity = n;
    heap.size = n;
    heap.isMaxHeap = !ascending; // 排序方向与堆类型相反

    // 建堆：从最后一个非叶子节点开始向下调整
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        shiftDown(&heap, i);
    }

    // 依次取出堆顶元素
    for (int i = n - 1; i > 0; i--) 
    {
        // 将堆顶元素（最大/最小）与当前末尾元素交换
        int temp = heap.data[0];
        heap.data[0] = heap.data[i];
        heap.data[i] = temp;

        // 堆大小减1
        heap.size--;
        // 调整堆
        shiftDown(&heap, 0);
    }
}

