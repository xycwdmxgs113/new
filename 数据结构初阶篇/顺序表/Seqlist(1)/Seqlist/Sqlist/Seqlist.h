#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//定义顺序表结构
#define N 100

//动态顺便表结构
typedef int SLDataType;

typedef struct Seqlist
{
	SLDataType* arr;
	int size;//有效数据个数
	int capacity;//空间大小
}SL;

//顺序表的初始化
void SLint(SL *ps);

//顺序表的销毁
void SLDestroy(SL* ps);
//打印顺序表
void SLPrint(const SL* ps);

//头部插入删除/尾部插入删除
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//在指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);

