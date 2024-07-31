#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void move(char* arr, int max) {
	int i = 0;
	for (;i < max-1;i++) {
		arr[i] = getchar();
		if (arr[i] == '\n' || arr[i] == ' ' || arr[i] == '\t') {
			break;
		}
	}
	arr[i] = '\0';
}

int main() {
	char arr[100];
    int max;
    scanf("%d", &max);
	getchar();
	move(arr,max);
    printf("%s",arr);
	return 0;	
 }