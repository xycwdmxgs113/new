#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

int main() {
	double a, b;
	a = b = 100.0;
	int cnt = 1;
	do   {
		a += 100 * 0.1;
		b += b * 0.05;
		cnt++;
	} while (a - b < 0);
	printf("%.2f %.2f %d", a, b, cnt);
	return 0;
}