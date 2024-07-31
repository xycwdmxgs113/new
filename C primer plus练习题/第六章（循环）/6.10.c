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
	int n, m;
	printf("Enter lower and upper integer limits:");
	scanf("%d%d", &n, &m);
	while (n < m) {
		int sum = 0;
		for (int i = n; i <= m; i++) {
			sum += i * i;
		}
		printf("the sums of then squares from %d to %d is %d\n", n * n, m * m, sum);
		printf("Enter bext set of limist:");
		scanf("%d%d", &n, &m);
	}
	printf("DONE");
	return 0;
}