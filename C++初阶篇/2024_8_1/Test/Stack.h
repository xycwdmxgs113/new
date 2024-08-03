#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
namespace cat
{
	typedef int STDataType;
	typedef struct Stack
	{
		STDataType* a;
		int top;
		int capacity;
	}ST;
	void STInit(ST* ps, int n);
	void STPush(ST* ps, STDataType x);

}