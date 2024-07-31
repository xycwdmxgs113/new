#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>s



int main() {
	int n;
	
	printf("How many words do you wish to enter?");
	scanf("%d", &n);
	printf("Enter %d words now\n",n);

	char ** pb = (char**)malloc(n * sizeof(char*));
	for (int i = 0;i < n;i++) {
		char arr[100];
		scanf("%s", arr);
		int len = strlen(arr);
		char* str = (char*)malloc(len * sizeof(char));
		strcpy(str, arr);
		*(pb + i) = str;
	}

	for (int i = 0;i < n;i++) {
		printf("%s\n", *(pb + i));
	}
	free(pb);

	return 0;
}