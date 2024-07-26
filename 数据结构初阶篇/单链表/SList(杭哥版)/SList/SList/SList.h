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


//��ӡ����
void SLPrint(SLTNode* phead);
//β������
void SLPushBack(SLTNode** phead, SLTDataTpye x);
//ͷ������
void SLPushFront(SLTNode** phead, SLTDataTpye x);
//����βɾ
void SLPopBack(SLTNode** phead);
//����ͷɾ
void SLPopFront(SLTNode** phead);
//���������
SLTNode* SListFind(SLTNode* phead, SLTDataTpye x);
//pos֮ǰ����
void SListInsert(SLTNode**phead, SLTNode* pos, SLTDataTpye x);
//posλ��ɾ��
void SListErase(SLTNode**phead, SLTNode* pos);
//pos֮�����
void SListInsertAfter(SLTNode* pos, SLTDataTpye x);
//posλ�ú���ɾ��
void SListEraseAfter(SLTNode* pos);
//��������
void SLTDestroy(SLTNode** pphead);
