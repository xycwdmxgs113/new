#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void menu(void) {
	printf("1:打印源字串列表\n2:以ASCII中的顺序打印字符串\n3:按长度打印字符串\n4:按字符串中第一个单词的长度打印字符串\n0：退出\n");
}

void ASCpx(char** arr, int n) {
	int i, j;
	for ( i = 0;i < n - 1;i++) {
		for ( j = 0;j < n - 1 - i;j++) {
			if (strcmp(arr[j], arr[j + 1]) > 0) {
				char* t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

void sizepx(char **arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (strlen(arr[j])>strlen(arr[j+1])) {
				char* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int wordsize(char* arr) {
	int cnt = 0;
	while (*arr != '\0') {
		if (*arr == ' ')
			break;
		cnt++;
		arr++;
	}
	return cnt;
}

void wordpx(char** arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (wordsize(arr[j])> wordsize(arr[j+1])) {
				char* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {

	char* arr[10];
	int i;
	for ( i = 0;i < 10;i++) {
		arr[i] = (char*)malloc(100 * sizeof(char));
		gets(arr[i]);

	}
	int n;
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			for (i = 0;i < 10;i++) {
				printf("%s\n", arr[i]);

			}
			break;
		case 2:
			ASCpx(arr, 10);
			for (i = 0;i < 10;i++) {
				printf("%s\n", arr[i]);

			}
			break;
		case 3:
			sizepx(arr, 10);
			for (i = 0;i < 10;i++) {
				printf("%s\n", arr[i]);

			}
			break;
		case 4:
			wordpx(arr, 10);
			for (i = 0;i < 10;i++) {
				printf("%s\n", arr[i]);

			}
			break;
		default:
			break;
		}
		printf("\n");
	} while (n!=0);

	return 0;
}