#pragma once
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 32
#define CAPACITY_INCREMENT 32 // 扩容的容量增量

typedef struct IntStack {
    int *data;
    int top;
    int capacity;
} IntStack;

IntStack *create_IntStack()
{
    IntStack *stack = (IntStack *)malloc(sizeof(IntStack));
    stack->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    stack->top = -1;
    stack->capacity = INITIAL_CAPACITY;
    return stack;
}

void Init_IntStack(IntStack *stack)
{
    stack->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    stack->top = -1;
    stack->capacity = INITIAL_CAPACITY;
}

int is_empty_IntStack(IntStack *stack)
{
    return stack->top == -1;
}

void push_IntStack(IntStack *stack, int value)
{
    if (stack->top == stack->capacity - 1) {
        stack->capacity += CAPACITY_INCREMENT;
        stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = value;
}

int pop_IntStack(IntStack *stack)
{
    if (is_empty_IntStack(stack)) {
        printf("IntStack is empty\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

/**
 * @brief 此为peek函数的实现，返回栈顶元素的值，但不弹出栈顶元素
 * @param stack 栈的指针
 * @return int 栈顶元素的值
 */
int peek_IntStack(IntStack *stack)
{
    if (is_empty_IntStack(stack)) {
        printf("IntStack is empty\n");
        exit(1);
    }
    return stack->data[stack->top];
}

void free_IntStack(IntStack *stack)
{
    free(stack->data);
    free(stack);
}
