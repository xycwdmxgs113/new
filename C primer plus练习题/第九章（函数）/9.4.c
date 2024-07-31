#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

double ds(double x, double y) {
	return 1/((1/x+1/y)/2);
}

int main() {
	double x, y,z;
	scanf("%lf%lf", &x, &y);
	z = ds(x, y);
	printf("%lf", z);
	return 0;
}