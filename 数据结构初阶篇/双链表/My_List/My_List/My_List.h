#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>]

typedef int ListNodeDataType;

typedef struct ListNode {
	ListNodeDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;


//声明双向链表中提供的方法

//初始化
//void LTInit(LTNode** pphead);
ListNode* LTInit();

//销毁链表
void LTDisTroy(ListNode* phead);

//打印链表
void LTPrint(ListNode* phead);

//不改变哨兵位的地址，因此传一级即可
//尾插
void LTPushBack(ListNode* phead, ListNodeDataType x);//插入数据之前，链表必须初始化到只有一个头节点的情况
//头插
void LTPushFront(ListNode* phead, ListNodeDataType x);

//头删与尾删
void LTPopBack(ListNode* phead);
void LTPopFront(ListNode* phead);

//在pos后插入数据
void LTInsert(ListNode* pos, ListNodeDataType x);
//删除pos位置数据
void LTErase(ListNode* pos);
//查找pos位置数据
ListNode* Find(ListNode* phead, ListNodeDataType x);