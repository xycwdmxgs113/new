#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//创建单链表数据

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType n; //链表数据
	struct SListNode* next; //下一个链表地址
}SLTNode;

//打印链表
void SLTPrint(const SLTNode* pphead);

//初始化链表
SLTNode* Init(void);

//尾部插入
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//头部插入
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//尾删除
void SLTPopBack(SLTNode** pphead);

//链表头删
void SLTPopFront(SLTNode** pphead);

//查找
SLTNode* SLTFind(SLTNode* pphead, SLTDataType x);

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos);

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos);

//销毁链表
void SListDesTroy(SLTNode** pphead);