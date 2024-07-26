#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void reverse( char* str) {
	
	char tmp = *str;
	int len = strlen(str);
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if(strlen(str+1)>=2)
	reverse(str + 1);
	*(str + len - 1) = tmp;
}

int main() {
	char arr[]="abcdef";
	int len = sizeof(arr) / sizeof(arr[0])-1;
	char* pa = arr;
	char* pb = &arr[len - 1];
	reverse(arr);
	printf("%s", arr);
	return 0;
}