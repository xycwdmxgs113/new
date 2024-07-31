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

int main() {
	char ch;
	int cnt = 0;
	while ((ch = getchar()) != EOF) {
		cnt++;
		if (ch == ' ' || ch == '\n') {
			printf("%d ", cnt - 1);
			cnt = 0;
			continue;
		}

	}


	return 0;
}