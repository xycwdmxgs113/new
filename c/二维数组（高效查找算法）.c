#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>


int find_num(int arr[3][3], int *pa, int *pb, int k) {
	int x = 0;
	int y = *pb - 1;
	while (x < *pa&&y>=0)
	{
		if (k > arr[x][y]) {
			x++;
		}
		else if (k < arr[x][y]) {
			y--;
		}
		else {
			*pa = x;
			*pb = y;
			return 1;
		}
	}
	*pa = -1;
	*pb = -1;
	return 0;
}


int main() {
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int n;
	scanf("%d", &n);
	int x = 3;
	int y = 3;
	int ret = find_num(arr, &x, &y, n);
	if (ret) {
		printf("%d %d", x, y);
	}
	return 0;
}