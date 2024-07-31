#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

char* my_strchr(char* arr,char i) {
	char* p = arr;
	int flag = 0;
	while (*p != '\0') {
		if (*p == i) {
			flag = 1;
			break;
		}
		p++;
	}
	if (!flag)
		p = NULL;
	return p;
		
}

int main() {
	char arr[100];
	gets(arr);
	char i;
	do
	{
		printf("请输入要查找的字符\n");
		 i = getchar();
		 if (i == 'q') {
			 break;
		 }
		 else {
			 if (my_strchr(arr, i)) {
				 printf("找到了位置在%d\n", my_strchr(arr, i) - arr + 1);
			 }
			 else
				 printf("没找到\n");
		 }
		 getchar();
	} while (1);


	return 0;
}