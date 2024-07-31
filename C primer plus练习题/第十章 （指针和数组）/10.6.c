#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>


void px(double* arr, int sz) {
	double t = *arr;
	
	*arr = *(arr + sz - 1);
	if (arr < arr+sz-1) {
		px(arr + 1, sz - 2);
	}
	 *(arr + sz - 1)=t;
}



int main() {

	double arr[] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	px(arr, sz);
	for (int i = 0;i < sz;i++) {
		printf("%.0f ", arr[i]);
	}



	return 0;
}