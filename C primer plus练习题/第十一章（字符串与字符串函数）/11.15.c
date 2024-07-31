#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>

int myatoi(char* arr) {
	if (arr == NULL)
		return 0;
	if (*arr == '\0')
		return 0;
	char* pa = arr;
	while (isspace(*pa)) {
		pa++;
	}
	int flag = 1;
	if (*pa == '-') {
		flag = -1;
		pa++;
	}
	long long ret =0;
	while (*pa!='\0') {
		if (isdigit(*pa)) {
			ret = ret * 10 + (*pa - '0') * flag;
		}
		else {
			return (int)ret;
		}
		pa++;
	}

	return (int)ret;

}

int main() {
	char arr[100];
	gets(arr);
	int num= myatoi(arr);
	printf("%d", num);


	return 0;
}