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
	int a = 100;
	int cnt = 0;
	while (a > 9) {
		a += a * 0.08;
		a -= 10;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}