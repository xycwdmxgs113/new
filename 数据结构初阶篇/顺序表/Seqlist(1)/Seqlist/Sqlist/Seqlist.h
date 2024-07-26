#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//����˳���ṹ
#define N 100

//��̬˳���ṹ
typedef int SLDataType;

typedef struct Seqlist
{
	SLDataType* arr;
	int size;//��Ч���ݸ���
	int capacity;//�ռ��С
}SL;

//˳���ĳ�ʼ��
void SLint(SL *ps);

//˳��������
void SLDestroy(SL* ps);
//��ӡ˳���
void SLPrint(const SL* ps);

//ͷ������ɾ��/β������ɾ��
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//��ָ��λ��֮ǰ����/ɾ������
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);

