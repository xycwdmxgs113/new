#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
//最大值
int Max(int* a, int n) {
	int max = *a;
	for (int i = 0;i < n;i++) {
		if (max < *(a + i))
			max = *(a + i);
	}
	return max;
}
//最大值下标
int Max1(int* a, int n) {
	int max = *a;
	int k;
	for (int i = 0;i < n;i++) {
		if (max < *(a + i))
			k=i;
	}
	return k;
}
//最大值与最小值的差值
int PK(int* a, int n) {
	int max, min;
	max = min = *a;
	int i;
	for (i = 0;i < n;i++) {
		if (max < *(a + i))
			max = *(a + i);
		if (min > *(a + i))
			max = *(a + i);
	}
	return max - min;
}

int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = Max(a, 10);
	int len1 = Max1(a, 10);
	int p = PK(a, 10);
	printf("%d %d %d", len,len1,p);


	return 0;
}