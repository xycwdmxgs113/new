#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void my_get(char arr[], int n) {
    int i = 0;
    for (; i < n - 1; i++) {
        arr[i] = getchar();
        if (arr[i] == '\n' || arr[i] == ' ' || arr[i] == '\t') {
            arr[i] = '\0';
            break;
        }
    }
    arr[i] = '\0';
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	char arr[100];
	my_get(arr,n);
	printf("%s", arr);


	return 0;	
}