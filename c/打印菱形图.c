#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>



int main() {
	int n;
	scanf("%d", &n);
	
	//上行
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n - 1 - i;j++)
			printf(" ");
		for (int j = 0;j < 2*i+1;j++)
			printf("*");
		printf("\n");
	}
	//下行
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j <= i;j++)
			printf(" ");
		for (int j = 0;j < 2 * (n - 1 - i)-1;j++)
			printf("*");
		printf("\n");

	}

	
	return 0;
}