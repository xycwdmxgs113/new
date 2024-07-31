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
	char ch = 'F';
	char a[6];
	for (int i = 0; i < 6; i++) {
		a[i] = ch--;
		for (int j = 0; j <= i; j++ )
			printf("%c", a[j]);
		printf("\n");
	}
	return 0;
}