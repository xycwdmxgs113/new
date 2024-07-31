#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

//带数组方式
void copy_arr(double arr[], double source[], int n) {
	int i;
	for (i = 0;i < n;i++)
		arr[i] = source[i];
	for (i = 0;i < n;i++)
		printf("%.1f ",arr[i]);
	printf("\n");
}

//带指针和指针递增的方式
void copy_prr(double* arr, double source[], int n) {
	int i;
	
	for (i = 0; i < n; i++){
		*arr = source[i];
		arr++;	
		}

}

//带目标数组，源数组，指向源数组最后一个元素后面的元素的指针
void copy_ptr(double *pa, double *pb, double *pc) {

	while (pa < pc) {
		*pa = *pb;
		pa++;
		pb++;
	}
}

int main() {
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, 5);
	copy_prr(target2, source, 5);

	for (int i = 0;i < 5;i++)
		printf("%.1f ", target2[i]);
	printf("\n");

	copy_ptr(target3, source, target3 + 5);
	for (int i = 0;i < 5;i++)
		printf("%.1f ", target3[i]);
	printf("\n");
	return 0;
}