#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>


int  test(void) {
	static int sum = 0;
	return ++sum;
}

int main() {

	int i;
	for (i = 0;i < 10;i++) {
		int s=test();
		printf("%d ", s);
	}

	return 0;	
}