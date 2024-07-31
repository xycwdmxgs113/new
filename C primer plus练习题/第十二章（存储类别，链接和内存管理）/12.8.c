#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>

int* make_array(int elem, int val);
void show_array(const int ar[], int n);


int main() {
	int* pa;
	int size;
	int value;

	printf("Enter the number of elements:");
	while (scanf("%d", &size) == 1 && size > 0) {
		printf("Enter the initialization value:");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa) {
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit):");
	}
	printf("Done.\n");

	return 0;
}


int* make_array(int elem, int val) {
	int* arr;
	arr = (int*)malloc(elem * sizeof(int));
	char* ar = arr;
	for (int i = 0;i < elem;i++) {
		arr[i] = val;
	}
	return ar;
}

void show_array(const int ar[], int n) {
	int cnt = 0;
	for (int i = 0;i < n;i++) {

		printf("%d ", ar[i]);
		cnt++;
		if (cnt == 8) {
			putchar('\n');
			cnt = 0;
		}
	}
	printf("\n");
}