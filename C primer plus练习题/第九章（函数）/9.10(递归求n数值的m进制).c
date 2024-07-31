#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>


void to_binary(unsigned long n, int c) {
	int t = n % c;
	if (n >= c) {
		to_binary(n / c, c);
	}
	printf("%d", t);
}

int main() {
	unsigned long n;
	int c;
	printf("Enter an integer (q to quit):\n");
	while (scanf("%lu", &n) == 1) {
		scanf("%d", &c);
		printf("Binary equivalent:");
		to_binary(n, c);
		printf("\n");
		printf("Enter an integer (q to quit):\n");
	}
	printf("Don.\n");

	return 0;
}