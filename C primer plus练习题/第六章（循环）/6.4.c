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
	char ch = 'A';
	char a[20];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%c", ch++);
		}
		printf("\n");
	}
	return 0;
}