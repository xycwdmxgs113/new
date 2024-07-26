#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

//定义节点的结构
//数据+指向下一个节点的指针
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SLlistNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);

//链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//链表头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//链表尾删
void SLTPopBack(SLTNode** pphead);

//链表头删
void SLTPopFront(SLTNode** pphead);

//查找
SLTNode *SLTFind(SLTNode* pphead, SLTDataType x);

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead,SLTNode* pos, SLTDataType x);

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos);

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos);

//销毁链表
void SListDesTroy(SLTNode** pphead);