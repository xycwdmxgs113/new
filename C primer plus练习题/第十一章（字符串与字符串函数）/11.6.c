#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>


int is_within(char c, char* arr) {
	char* p = arr;
	int flag = 0;
	while (*p != '\0') {
		if (*p == c) {
			flag = 1;
			break;
		}
		p++;
	}
	return flag;
}

int main() {
	char arr[100];
	gets(arr);
	char c;
	c = getchar();
	while (1) {
		int k = is_within(c, arr);
		if (k) {
			printf("%d\n", k);
		}
		else {
			printf("%d\n", k);
			break;
		}
		getchar();
		c = getchar();
	}





	return 0;
}