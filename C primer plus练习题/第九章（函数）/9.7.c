#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

int zf(char ch) {
	int flag = -1;
	if (ch >= 'a' && ch <= 'z')
		flag = ch - 'a'+1;
	else if (ch >= 'A' && ch <= 'Z')
		flag = ch - 'A'+1;

	return flag;
}

int main() {
	char ch;
	int a;
	while ((ch=getchar()) != EOF) {
		if (ch == '\n')
			continue;
		a = zf(ch);
		printf("%d\n", a);
	}
	return 0;
}