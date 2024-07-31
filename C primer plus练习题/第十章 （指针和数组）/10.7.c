#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void copy_arr(double a[3][2], double b[3][2], int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			b[i][j] = a[i][j];
	}
}

int main() {
	double a[3][2] = { 1.0,2.0,3.0,4.0,5.0,6.0 };
	double b[3][2];
	copy_arr(a, b, 3, 2);
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 2;j++)
			printf("%.0f ", b[i][j]);
	}

	return 0;
}