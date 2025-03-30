#include "Stack.h"


// 初始化栈
Stack* createStack(int size) 
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// 判断栈是否为空
int isEmpty(Stack* stack) 
{
    return stack->top == -1;
}

// 入栈
void push(Stack* stack, int value) 
{
    if (stack->top >= stack->size - 1) 
    {
        printf("栈已满，无法入栈\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// 出栈
int pop(Stack* stack)
{
    if (isEmpty(stack)) 
    {
        printf("栈为空，无法出栈\n");
        return -1;
    }
    return stack->data[stack->top--];
}