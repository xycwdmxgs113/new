#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* a;
	int size;
	int capaticy;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);

void HeapPush(HP* php, HeapDataType x);
void HeapPop(HP* php);

bool HeapEmpty(HP* php);
HeapDataType HeapTop(HP* php);
int HeapSize(HP* php);
void AdjustDown(HeapDataType* a, int parent, int size);
void AdjustUp(HeapDataType* a, int child);
void Swap(HeapDataType* x, HeapDataType* y);


