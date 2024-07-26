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
	int space, max, star;
	max = (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		space = (max - i) * 2;
		if (space < 0)
			space = -space;
		star = n - space;
		for (int j = 1; j <= space; j++)
			printf(" ");
		for (int k = 1; k <= star; k++)
			printf(" *");
		printf("\n");
	}


	return 0;
}