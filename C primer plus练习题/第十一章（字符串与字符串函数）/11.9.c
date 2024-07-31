#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void reverse(char* arr) {
	int len = strlen(arr);
	int begin = 0, end = len-1;
	while (begin < end) {
		char t = arr[begin];
		arr[begin] = arr[end];
		arr[end] = t;
		begin++, end--;
	}
	
}

int main() {
	char arr[100];
	gets(arr);
	reverse(arr);
	printf("%s", arr);
	return 0;
}