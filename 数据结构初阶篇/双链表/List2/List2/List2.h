#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��������������

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType n; //��������
	struct SListNode* next; //��һ�������ַ
}SLTNode;

//��ӡ����
void SLTPrint(const SLTNode* pphead);

//��ʼ������
SLTNode* Init(void);

//β������
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//ͷ������
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//βɾ��
void SLTPopBack(SLTNode** pphead);

//����ͷɾ
void SLTPopFront(SLTNode** pphead);

//����
SLTNode* SLTFind(SLTNode* pphead, SLTDataType x);

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos);

//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos);

//��������
void SListDesTroy(SLTNode** pphead);