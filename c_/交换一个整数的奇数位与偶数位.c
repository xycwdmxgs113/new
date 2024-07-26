#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>


#define TEMP(n) ((( n & 0xAAAAAAAA)>>1)|((n & 0x55555555)<<1))

int main() {
	int n;
	scanf("%d", &n);
	int ret = TEMP(n);
	printf("%d", ret);

	return 0;
}
