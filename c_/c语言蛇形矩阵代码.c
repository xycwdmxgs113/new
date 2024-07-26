#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n * 2 - 1][n * 2 - 1];
	int cnt = 1;
	for (int i = 0; i < n * 2 - 1; i++) {
		for (int j = 0; j < n * 2 - 1; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 1; i <= n * 2 - 1; i++) {
		int l = 1;
		int h = i;
		while (h >= 1) {
			if (l <= n && h <= n) {
				if (i % 2 != 0) {
					a[h][l] = cnt++;
				} else {
					a[l][h] = cnt++;
				}
			}
			h--;
			l++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n ; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}