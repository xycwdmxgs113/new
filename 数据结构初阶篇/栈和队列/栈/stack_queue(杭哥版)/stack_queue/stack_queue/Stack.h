#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
	
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capaticy;
}ST;

void STInit(ST* ps);//��ʼ��ջ
void STDestroy(ST* ps);//����ջ

void STPush(ST* ps, STDataType x);//ѹջ
void STPop(ST* ps);//��ջ
int  STSize(ST* ps);//����ջ����Ч���ݳ���
bool STEmpty(ST* ps);//�ж�ջ���Ƿ�������
STDataType STTop(ST* ps);//����ջ��Ԫ��
