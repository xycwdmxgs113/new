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

int zhisu(int n) {
	int flag = 1;
	if (n == 1) {
		return 1;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main() {
	int n;
	scanf("%d", &n);
	if (n > 0 && n != 1) {
		for (int i = 1; i <= n; i++) {
			if (zhisu(i)) {
				printf("%d ", i);
			}
		}
	} else if (n == 1) {
		printf("%d", n);
	} else
		printf("DONW");

	return 0;
}