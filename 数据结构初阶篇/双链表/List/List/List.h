#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int	LTDataType;
//����˫������Ľ��
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;

}LTNode;


//����˫���������ṩ�ķ���

//��ʼ��
//void LTInit(LTNode** pphead);
LTNode* LTInit();

//��������
void LTDisTroy(LTNode* phead);

//��ӡ����
void LTPrint(LTNode* phead);

//���ı��ڱ�λ�ĵ�ַ����˴�һ������
void LTPushBack(LTNode*phead, LTDataType x);//��������֮ǰ����������ʼ����ֻ��һ��ͷ�ڵ�����
void LTPushFront(LTNode* phead, LTDataType x); 

//ͷɾ��βɾ
void LTPopBack(LTNode* phead);
void LTPopFront(LTNode* phead);

//��pos���������
void LTInsert(LTNode* pos, LTDataType x);
//ɾ��posλ������
void LTErase(LTNode* pos);
//����posλ������
LTNode* Find(LTNode* phead, LTDataType x);