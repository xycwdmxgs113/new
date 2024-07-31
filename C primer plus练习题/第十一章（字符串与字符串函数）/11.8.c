#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

char* string_in(char* arr1, char* arr2) {
	char *pa = arr1;
	char* pb = arr2;
	char* pc=NULL;
	int len = strlen(arr2);

	int flag = 0;
	while (*pa != '\0') {
		if (*pa == *pb) {
			pc = pa;
			flag = 1;
			break;
		}
		pa++;
	}
	if (!flag) {
		return pc;
	}
	
	for (int i = 0;i < len;i++) {
		if (*pa == *pb) {
			pa++, pb++;
			}
		else {
			flag = 0;
			pc = NULL;
			break;
		}
	}
	return pc;
}

int main() {
	char arr1[100];
	char arr2[100];
	int n;
	printf("ÇëÊäÈënÖµ\n");
	scanf("%d", &n);
	while (n!=0) {
		getchar();
		printf("ÇëÊäÈëarr1×Ö·û´®\n");
		gets(arr1);
		printf("ÇëÊäÈëarr2×Ö·û´®\n");
		gets(arr2);
		if (string_in(arr1, arr2)) {
			printf("arr1°üº¬arr2\n");
		}
		else {
			printf("arr1²»°üº¬arr2\n");
		}

		printf("ÇëÊäÈënÖµ\n");
		scanf("%d", &n);
	}





	return 0;
}