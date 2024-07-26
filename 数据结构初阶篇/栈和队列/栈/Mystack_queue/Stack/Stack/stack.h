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

void STInit(ST* ps);//初始化栈
void STDestroy(ST* ps);//销毁栈

void STPush(ST* ps, STDataType x);//压栈
void STPop(ST* ps);//出栈
int  STSize(ST* ps);//计算栈的有效数据长度
bool STEmpty(ST* ps);//判断栈里是否有数据
STDataType STTop(ST* ps);//访问栈顶元素

