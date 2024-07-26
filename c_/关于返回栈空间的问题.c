#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>



void Ge(char* p) {
	//*p是形参 跟str没有关系
	p = (char*)malloc(100);
}

void test(void) {
	//返回栈空间的问题
	char* str = NULL;
	printf("%p\n", str);
	printf("%p\n", &str);
	Ge(str);
	//str还是空指针
	strcpy(str, "hello");
	printf(str);
	
}

int * test2() {
	//返回栈空间的问题
	int a = 1;
	return (&a);
	//出了函数 a地址的内容就销毁了变成空指针
}

int main() {
	
	test();
	int* ret = test2();
	printf("hh\n");
	printf("%d", *ret);
	return 0;
}