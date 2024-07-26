#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataTpye;

typedef struct SListNode
{
	SLTDataTpye data;
	struct SListNode* next;
}SLTNode;


//打印链表
void SLPrint(SLTNode* phead);
//尾插链表
void SLPushBack(SLTNode** phead, SLTDataTpye x);
//头插链表
void SLPushFront(SLTNode** phead, SLTDataTpye x);
//链表尾删
void SLPopBack(SLTNode** phead);
//链表头删
void SLPopFront(SLTNode** phead);
//单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataTpye x);
//pos之前插入
void SListInsert(SLTNode**phead, SLTNode* pos, SLTDataTpye x);
//pos位置删除
void SListErase(SLTNode**phead, SLTNode* pos);
//pos之后插入
void SListInsertAfter(SLTNode* pos, SLTDataTpye x);
//pos位置后面删除
void SListEraseAfter(SLTNode* pos);
//销毁链表
void SLTDestroy(SLTNode** pphead);
