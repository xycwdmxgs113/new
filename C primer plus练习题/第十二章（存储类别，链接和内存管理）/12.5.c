#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>


int main() {
	int arr[100];
	srand((unsigned int)time(NULL));
	for (int i = 0;i < 100;i++) {
		arr[i] = rand() % 10 + 1;
	}
	int t;
	for (int i = 0;i < 99;i++) {
		for (int j = i + 1;j < 100;j++) {
			if (arr[i] < arr[j]) {
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
	for (int i = 0;i < 100;i++) {
		
		printf("%d ", arr[i]);
		if (i % 10 == 0) {
			printf("\n");
		}
		
	}


	return 0;
}