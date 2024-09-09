#pragma once

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 32   // 初始的容量
#define CAPACITY_INCREMENT 32 // 扩容的容量增量

typedef struct PtrVector {
    void **data;
    int size;
    int capacity;
} PtrVector;

PtrVector *create_PtrVector()
{
    PtrVector *vec = (PtrVector *)malloc(sizeof(PtrVector));
    vec->data = (void **)malloc(INITIAL_CAPACITY * sizeof(void *));
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
    return vec;
}

void Init_PtrVector(PtrVector *vec)
{
    vec->data = (void **)malloc(INITIAL_CAPACITY * sizeof(void *));
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
}

void push_back_PtrVector(PtrVector *vec, void *ele)
{
    if (vec->size >= vec->capacity) {
        vec->capacity += CAPACITY_INCREMENT;
        vec->data = (void **)realloc(vec->data, vec->capacity * sizeof(void *));
    }
    vec->data[vec->size++] = ele;
}

void *at_PtrVector(PtrVector *vec, int index)
{
    if (index < 0 || index >= vec->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return vec->data[index];
}

void free_PtrVector(PtrVector *vec)
{
    free(vec->data);
    free(vec);
}
