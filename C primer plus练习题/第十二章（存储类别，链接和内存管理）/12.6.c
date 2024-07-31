#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>


int main() {
	int arr[1000];
	int b[11] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 0;i < 1000;i++) {
		arr[i] = rand() % 10 + 1;
		b[arr[i]]++;
	}

	for (int i = 1;i <=10;i++) {
		printf("%d ", b[i]);
	}


	return 0;
}