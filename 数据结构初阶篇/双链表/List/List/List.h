#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int	LTDataType;
//定义双向链表的结果
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;

}LTNode;


//声明双向链表中提供的方法

//初始化
//void LTInit(LTNode** pphead);
LTNode* LTInit();

//销毁链表
void LTDisTroy(LTNode* phead);

//打印链表
void LTPrint(LTNode* phead);

//不改变哨兵位的地址，因此传一级即可
void LTPushBack(LTNode*phead, LTDataType x);//插入数据之前，链表必须初始化到只有一个头节点的情况
void LTPushFront(LTNode* phead, LTDataType x); 

//头删与尾删
void LTPopBack(LTNode* phead);
void LTPopFront(LTNode* phead);

//在pos后插入数据
void LTInsert(LTNode* pos, LTDataType x);
//删除pos位置数据
void LTErase(LTNode* pos);
//查找pos位置数据
LTNode* Find(LTNode* phead, LTDataType x);