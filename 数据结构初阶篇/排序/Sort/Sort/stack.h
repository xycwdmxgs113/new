#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* data;
	int capaticy;
	int top;
}ST;

void STInit(ST* ps);//��ʼ��ջ
void STDestroy(ST* ps);//����ջ

void STPush(ST* ps, STDataType x);//ѹջ
void STPop(ST* ps);//��ջ
int  STSize(ST* ps);//����ջ����Ч���ݳ���
bool STEmpty(ST* ps);//�ж�ջ���Ƿ�������
STDataType STTop(ST* ps);//����ջ��Ԫ��

