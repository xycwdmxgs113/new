#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>



void Ge(char* p) {
	//*p���β� ��strû�й�ϵ
	p = (char*)malloc(100);
}

void test(void) {
	//����ջ�ռ������
	char* str = NULL;
	printf("%p\n", str);
	printf("%p\n", &str);
	Ge(str);
	//str���ǿ�ָ��
	strcpy(str, "hello");
	printf(str);
	
}

int * test2() {
	//����ջ�ռ������
	int a = 1;
	return (&a);
	//���˺��� a��ַ�����ݾ������˱�ɿ�ָ��
}

int main() {
	
	test();
	int* ret = test2();
	printf("hh\n");
	printf("%d", *ret);
	return 0;
}