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


//����˫���������ṩ�ķ���

//��ʼ��
//void LTInit(LTNode** pphead);
ListNode* LTInit();

//��������
void LTDisTroy(ListNode* phead);

//��ӡ����
void LTPrint(ListNode* phead);

//���ı��ڱ�λ�ĵ�ַ����˴�һ������
//β��
void LTPushBack(ListNode* phead, ListNodeDataType x);//��������֮ǰ����������ʼ����ֻ��һ��ͷ�ڵ�����
//ͷ��
void LTPushFront(ListNode* phead, ListNodeDataType x);

//ͷɾ��βɾ
void LTPopBack(ListNode* phead);
void LTPopFront(ListNode* phead);

//��pos���������
void LTInsert(ListNode* pos, ListNodeDataType x);
//ɾ��posλ������
void LTErase(ListNode* pos);
//����posλ������
ListNode* Find(ListNode* phead, ListNodeDataType x);