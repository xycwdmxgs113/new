#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
//循环方法输出会导致输出的二进制数 是反的形式
void my_for(long n) {
	int a;
	while (n > 0) {
		a = n % 2;
		printf("%d ", a);
		n /= 2;
	}
}
//而利用递归的特性就能很好的解决这个问题
void to_binary(long n) {
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	printf("%d ", r == (0 ? 0 : 1));
}

int main() {
	unsigned  long  n;
	scanf("%d", &n);
	my_for(n);
	printf("\n");
	to_binary(n);

	return 0;
}