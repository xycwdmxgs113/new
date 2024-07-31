#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void copy(double** arr, double** brr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			brr[i][j] = arr[i][j];
	}
}

void print(double** arr, double** brr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%.0f ", arr[i][j]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%.0f ", brr[i][j]);
	}
	printf("\n");
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	double** arr = (double**)malloc(sizeof(double) * n);
	for (int i = 0;i < m;i++) {
		arr[i] = (double *)malloc(sizeof(double) * m);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%lf", &arr[i][j]);
	}
	double ** brr = arr;
	copy(arr, brr, n, m);
	print(arr, brr, n, m);

	return 0;
}