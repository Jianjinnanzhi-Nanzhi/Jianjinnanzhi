#include "Heap.h"

//������
Heap* createHeap(int capacity, bool isMaxHeap) 
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    heap->isMaxHeap = isMaxHeap;
    return heap;
}

// ���ϵ������ѻ���
void shiftUp(Heap* heap, int i) 
{
    while (i > 0) 
    {
        int p = (i - 1) / 2;//��ȡ���ڵ�
        
        // ���ݶ����;����ȽϷ���
       //���ݶѵ������ж��Ƿ���Ҫ�������ӽڵ�
        bool shouldSwap = heap->isMaxHeap ? (heap->data[i] > heap->data[p]) :(heap->data[i] < heap->data[p]);

        if (shouldSwap) 
        {
            // �������ӽڵ�
            int temp = heap->data[i];
            heap->data[i] = heap->data[p];
            heap->data[p] = temp;
            i = p;  // �������ϼ��
        }
        else 
        {
            break;
        }
    }
}

// ����Ԫ��
bool insert(Heap* heap, int value) 
{
    if (heap->size >= heap->capacity) 
    {        
        return false;
    }

    // ����Ԫ�طŵ�ĩβ
    heap->data[heap->size] = value;
    // ���ϵ���
    shiftUp(heap, heap->size);
    heap->size++;
    return true;
}

// ���µ������ѻ���
void shiftDown(Heap* heap, int i) 
{
    int MaxorMin = i; // ��¼��ǰ�ڵ㼰���ӽڵ������/��Сֵ������
    int l = 2 * i + 1;//��ȡ����
    int r = 2 * i + 2;//��ȡ�Һ���

    // ���ӱȽ�
    if (l < heap->size) 
    {
        //���ݶѵ������ж��Ƿ���Ҫ�������ӽڵ�
        bool shouldUpdate = heap->isMaxHeap ?(heap->data[l] > heap->data[MaxorMin]) :(heap->data[l] < heap->data[MaxorMin]); 
        if (shouldUpdate) 
        {
            MaxorMin = l;
        }
    }

    // �Һ��ӱȽ�
    if (r < heap->size)
    {
        //���ݶѵ������ж��Ƿ���Ҫ�������ӽڵ�
        bool shouldUpdate = heap->isMaxHeap ? (heap->data[r] > heap->data[MaxorMin]) :(heap->data[r] < heap->data[MaxorMin]);
        if (shouldUpdate) 
        {
            MaxorMin = r;
        }
    }

    // �����Ҫ����
    if (MaxorMin != i) 
    {
        int temp = heap->data[i];
        heap->data[i] = heap->data[MaxorMin];
        heap->data[MaxorMin] = temp;
        // �ݹ����µ���
        shiftDown(heap, MaxorMin);
    }
}

// ɾ������ȡ�Ѷ�Ԫ��
int pop(Heap* heap) 
{
    if (heap->size <= 0)
    {       
        return -1;//root����Ϊ0,������-1
    }

    int root = heap->data[0];
    // �����һ��Ԫ���Ƶ���λ��
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    // ���µ���
    shiftDown(heap, 0);

    return root;
}

// ��ȡ�Ѷ�Ԫ��
int peek(Heap* heap) 
{
    if (heap->size <= 0)
    {      
        return -1;// heap->data[0]����Ϊ0,������-1
    }
    return heap->data[0];
}

// �ж϶��Ƿ�Ϊ��
bool isEmpty(Heap* heap) 
{
    return heap->size == 0;
}

// ��ȡ��ǰԪ�ظ���
int getSize(Heap* heap) 
{
    return heap->size;
}

// �ͷŶ��ڴ�
void freeHeap(Heap* heap) 
{
    free(heap->data);
    free(heap);
}

// ���ϵ�����������
void heapSortWithShiftUp(int arr[], int n, bool ascending) 
{
    // ����һ����ʱ��
    Heap* heap = createHeap(n, !ascending); // ��������������෴

    // ��������Ԫ�أ����ϵ������ѣ�
    for (int i = 0; i < n; i++)
    {
        insert(heap, arr[i]);
    }

    // ����ȡ��Ԫ��
    for (int i = 0; i < n; i++) 
    {
        arr[i] = pop(heap);
    }

    freeHeap(heap);
}

// ���µ����������򣨸���Ч��
void heapSortWithShiftDown(int arr[], int n, bool ascending) 
{
    // ���Ƚ�������Ϊһ���ѣ�Ȼ������һ����Ҷ�ӽڵ㿪ʼ���µ���

    // ��������ѽṹ
    Heap heap;
    heap.data = arr;
    heap.capacity = n;
    heap.size = n;
    heap.isMaxHeap = !ascending; // ��������������෴

    // ���ѣ������һ����Ҷ�ӽڵ㿪ʼ���µ���
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        shiftDown(&heap, i);
    }

    // ����ȡ���Ѷ�Ԫ��
    for (int i = n - 1; i > 0; i--) 
    {
        // ���Ѷ�Ԫ�أ����/��С���뵱ǰĩβԪ�ؽ���
        int temp = heap.data[0];
        heap.data[0] = heap.data[i];
        heap.data[i] = temp;

        // �Ѵ�С��1
        heap.size--;
        // ������
        shiftDown(&heap, 0);
    }
}

