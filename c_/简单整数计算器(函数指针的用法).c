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

 
void calc(int (*pf)(int, int)) {
	int x, y;
	scanf("%d%d", &x, &y);
	int ret = pf(x, y);
	printf("%d\n", ret);
}

int main() {
	int n;

	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Cheng);
			break;
		case 4:
			calc(Chu);
			break;
		default:
			printf("Ñ¡Ôñ´íÎó\n");
			break;
		}

	} while (n!=0);


	return 0;
}