#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>



int main() {
	int n;
	scanf("%d", &n);
	int b[10] = {0}, a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		while (a[i] != 0) {
			b[a[i] % 10]++;
			a[i] /= 10;
		}
	}
	int max = b[0];
	for (int i = 1; i < 10; i++) {
		if (max < b[i]) {
			max = b[i];
		}
	}
	printf("%d:", max);
	for (int i = 0; i < 10; i++) {
		if (b[i] == max)
			printf(" %d", i);
	}
	return 0;
}