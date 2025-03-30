#include "Stack.h"


// ��ʼ��ջ
Stack* createStack(int size) 
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* stack) 
{
    return stack->top == -1;
}

// ��ջ
void push(Stack* stack, int value) 
{
    if (stack->top >= stack->size - 1) 
    {
        printf("ջ�������޷���ջ\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// ��ջ
int pop(Stack* stack)
{
    if (isEmpty(stack)) 
    {
        printf("ջΪ�գ��޷���ջ\n");
        return -1;
    }
    return stack->data[stack->top--];
}