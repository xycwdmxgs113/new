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
	int head = 1;
	int tail = 100;
	int guess = (head + tail) / 2;
	char ch;

	do {
		printf("Un...is your number %d?: ", guess);
		if (getchar() == 'y')
			break;

		printf("Well, then, %d is larger or smaller than yours? (l or s): ", guess);
		while ((ch = getchar()) == '\n')
			continue;

		if (ch == 'l' || ch == 'L') {
			tail = guess - 1;
		} else if (ch == 's' || ch == 'S') {
			head = guess + 1;
		} else {
			continue;
		}

		guess = (head + tail) / 2;
	} while (getchar() != 'y');


	printf("I knew I could do it!");

	return 0;
}