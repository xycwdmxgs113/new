#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void into(double** arr, int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			scanf("%lf", &arr[i][j]);
	}
}
void outo(double** arr, int n, int m,double sum,double max) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			printf("%.0f ", arr[i][j]);
		printf("\n");
	}
	printf("所有数的平均值为%.2f\n", sum);
	printf("最大数为%.0f\n", max);
}

void average(double** arr, int n, int m) {
	int i, j;
	for( i = 0;i < n;i++) {
		double sum = 0;
		for (j = 0;j < m;j++)
			sum += arr[i][j];
		printf("第%d行的平均值为%.2f\n", i, sum / m);
	}
}

double Maxaverage(double** arr, int n, int m) {
	int i, j;
	double sum = 0;
	for (i = 0;i < n;i++) {

		for (j = 0;j < m;j++)
			sum += arr[i][j];
	}
	return sum;
}

double Max(double **arr, int n, int m) {
	double max = **arr;
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++)
			if (max < arr[i][j])
				max = arr[i][j];
	}
	return max;
}

int main() {
	printf("请输入三组数 ，每组数字里面包含 五个double类型数据\n");
	int n, m;
	scanf("%d%d", &n, &m);
	double** arr = (double**)malloc(sizeof(double) * n);
	for (int i = 0;i < m;i++) {
		arr[i]= (double*)malloc(sizeof(double) * m);
	}
	into(arr, n, m);
	
	average(arr, n, m);
	double sum = Maxaverage(arr, n, m) /(n*m);
	double max = Max(arr,n,m);
	outo(arr, n, m,sum,max);
	return 0;
}