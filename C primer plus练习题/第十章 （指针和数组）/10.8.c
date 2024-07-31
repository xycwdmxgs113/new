#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void copy_arr(int *arr,int * brr,int * crr) {
	while (arr < crr) {
		*brr = *arr;
		arr++;
		brr ++;

	}
}
int main() {
	int arr[7] = { 1,2,3,4,5,6,7 };
	int brr[3];
	copy_arr(arr + 2, brr, arr + 5);
	for (int i = 0;i < 3;i++)
		printf("%d ", brr[i]);

	return 0;
}