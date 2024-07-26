#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int  QueDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QueDataType val;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	int size;
}Queue;

void QInit(Queue* pq);
void QDestroy(Queue* pq);

void QPush(Queue* pq, QueDataType x);
void QPop(Queue* pq);

int  QSize(Queue* pq);
bool QEmpty(Queue* pq);

QueDataType QFront(Queue* pq);
QueDataType QBack(Queue* pq);
