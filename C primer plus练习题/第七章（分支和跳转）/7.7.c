#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>

#define JB 10
#define JIABAN 40

int main() {
	int n;
	scanf("%d", &n);
	const int  a = 45, b = 30, c = 450;
	int sum = 0;
	if (n < JIABAN) {
		sum = n * JB;
		if (sum <= 300)
			sum -= a;
		else if (sum > 300 && sum <= 400)
			sum -= (a + b);
	}	else {
		int c = n - JIABAN;
		sum = 400 + c * 15;
		if (sum > 400 && sum <= 450)
			sum -= (a + b);
		else {
			int h = sum - 450;
			int r = h * 0.25;
			sum -= (a + b + r);
		}
	}
	printf("%d", sum);
	return 0;
}