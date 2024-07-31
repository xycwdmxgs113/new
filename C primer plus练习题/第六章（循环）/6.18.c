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
	int a = 5;
	int cnt = 1;
	while (a < 150) {
		a -= cnt;
		a *= 2;
		cnt++;
		printf("%d ", a);
	}
	return 0;
}