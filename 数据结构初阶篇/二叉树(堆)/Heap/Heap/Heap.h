#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<Windows.h>
#include<time.h>

typedef int	HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capaticy;
}HP;

void HeapInit(HP* php);
void HeapInitArray(HP* php,int *a,int n);
void HeapDestory(HP* php);
void HeapPush(HP* php,HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
//int HeapSize(HP* php);

void AdjustDown(HPDataType* a, int size, int parent);
void AdjustUp(HPDataType* a, int child);

void Swap(HPDataType* p1, HPDataType* p2);


