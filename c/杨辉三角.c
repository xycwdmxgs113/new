#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

int main() {
	
	int a[10][10] = { 0 };
	
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j <= i;j++) {
			if (j == 0)
				a[i][j] = 1;
			if (i == j)
				a[i][j] =1;
			if (i >= 2 && j >= 1) {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}

	for (int i = 0;i < 10;i++) {
		for (int j = 0;j <= i;j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}