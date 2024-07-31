#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void addc(int a[], int b[], int c[], int n) {
	for (int i = 0;i < n;i++) {
		c[i] = a[i] + b[i];
	}
}

int main() {
	int a[] = { 1,2,3,4 };
	int b[] = { 1,0,4,6 };
	int len = sizeof(a) / sizeof(a[0]);
	int c[10];
	 addc(a, b, c, len);
	for (int i = 0;i < len;i++) {
		printf("%d ", c[i]);
	}


	return 0;
}