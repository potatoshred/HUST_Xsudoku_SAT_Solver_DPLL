#pragma once

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 32   // 初始的容量
#define CAPACITY_INCREMENT 32 // 扩容的容量增量

/**
 * IntVector对象，用于存放整数。
 */
typedef struct IntVector {
    int *data;    // 存放数据的数组
    int size;     // 当前的元素个数
    int capacity; // 容量
} IntVector;

/**
 * 创建IntVector对象
 * @return IntVector* 新建的IntVector对象的指针
 */
IntVector *create_IntVector()
{
    IntVector *vec = (IntVector *)malloc(sizeof(IntVector));
    vec->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
    return vec;
}

/**
 * 初始化IntVector对象。
 * @param vec IntVector对象指针
 * @return void
 */
void Init_IntVector(IntVector *vec)
{
    vec->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
}

/**
 * 向IntVector中添加元素，添加在末尾。
 * 如果容量不够，则自动扩容。
 * @param vec IntVector对象指针
 * @param value 要添加的元素
 * @return void
 */
void push_back_IntVector(IntVector *vec, int value)
{
    if (vec->size >= vec->capacity) {
        vec->capacity += CAPACITY_INCREMENT;
        vec->data = (int *)realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = value;
}

/**
 * 删除IntVector中最后一个元素。
 * @param vec IntVector对象指针
 * @return void
 */
void pop_back_IntVector(IntVector *vec)
{
    if (vec->size <= 0) {
        printf("IntVector ERROR: Vector is empty\n");
        exit(1);
    }
    vec->size--;
}

/**
 * 获取IntVector中指定位置的元素。
 * @param vec IntVector对象指针
 * @param index 要获取元素的位置
 * @return int 元素的值
 */
int at_IntVector(IntVector *vec, int index)
{
    if (index < 0 || index >= vec->size) {
        printf("IntVector ERROR: Index out of bounds\n");
        exit(1);
    }
    return vec->data[index];
}

/**
 * 释放IntVector对象。
 * @param vec IntVector对象指针
 * @return void
 */
void free_IntVector(IntVector *vec)
{
    free(vec->data);
    free(vec);
}
