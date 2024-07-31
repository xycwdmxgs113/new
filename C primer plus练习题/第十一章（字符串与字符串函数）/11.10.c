#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

int  despace(char* arr,int len) {
	int cnt = 0;
	char* pa = arr;
	char* pb = arr;
	while (*pa != '\0') {

		if (*pa != ' ') {
			*pb = *pa;
			pb++;
		}
		else
			cnt++;
		pa++;
	}
	*pb = '\0';
	return cnt;
}

int main() {
	char arr[100];
	int len, k;
	do
	{
		gets(arr);
		 len = strlen(arr);
		 k=despace(arr,len);
		printf("%s\n", arr);
	} while (k<len);


	return 0;
}