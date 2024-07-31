#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

double my_power(double n, int p) {
	double power = 1.0;
	if (n == 0) 
		return 0;

	if (p == 0) 
		return 1;
	if (p > 0) {
		for (int i = 1;i <= p;i++) {
			power *= n;
		}
	}
	else {
		for (int i = 1;i <= -p;i++)
			power /= n;
	}
	return power;

}
int main() {
	double a;
	int b;
	scanf("%lf %d", &a, &b);
	double k=my_power(a, b);
	printf("%lf", k);

	return 0;
}