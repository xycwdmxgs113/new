#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>

void menu(void) {
	printf("**************************\n");
	printf("*****1:add, 2:sub*********\n");
	printf("*****3:mull 4:div*********\n");
	printf("*****0:exit***************\n");
	printf("**************************\n");
}

int Add(int x, int y) {
	return x + y;
}

int Sub(int x, int y) {
	return x - y;
}

int Cheng(int x, int y) {
	return x * y;
}

int Chu(int x, int y) {
	return x / y;
}


//void calc(int (*pf)(int, int)) {
//
//	scanf("%d%d", &x, &y);
//	int ret = pf(x, y);
//	printf("%d\n", ret);
//}

int main() {
	int n;
	int x, y;
	//函数指针数组
	int (*pfarr[5])(int, int) = { 0,Add,Sub,Cheng,Chu };
	do
	{
		menu();
		scanf("%d", &n);
		if (n == 0)
			printf("退出计算器\n");
		else if (n >= 1 && n <= 4) {
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			int ret = pfarr[n](x, y);
			printf("%d\n", ret);
		}
		else
		{
			printf("选择错误\n");
		}

	} while (n != 0);


	return 0;
}	