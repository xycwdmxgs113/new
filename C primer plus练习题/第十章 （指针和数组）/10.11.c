#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void print(int* arr[], int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

}

void tow(int* arr[], int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			arr[i][j] *= arr[i][j];
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n,& m);
	int** arr = (int**)malloc(sizeof(int) * n);
	for (int i = 0;i < n;i++) {
		arr[i] = (int*)malloc(sizeof(int) * m);
	}
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			scanf("%d", &arr[i][j]);
	}

	print(arr, n, m);
	tow(arr, n, m);
	print(arr, n, m);


	return 0;
}