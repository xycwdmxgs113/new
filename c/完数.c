#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>

int factorsum( int number );
void PrintPN( int m, int n );

//完数就是该数恰好等于除自身外的因子之和。例如：6=1+2+3，其中1、2、3为6的因子。
int factorsum( int number ) {//factorsum函数用来判断该数是否为函数
	int sum = 0;
	int factorsum = number;
	for (int i = 1; i < number; i++) {
		if (number % i == 0) {
			sum += i;
		}
	}
	if (sum == factorsum) {
		return sum;
	} else {
		return 0;
	}
}

void PrintPN( int m, int n ) {
	int flag = 0;//开关值 判断这个范围内有没有完数
	for (int i = m; i <= n; i++) {
		if (factorsum(i) == i) {
			printf("%d = 1", i);
			for (int j = 2; j < i; j++) {
				if (i % j == 0) {
					printf(" + %d", j);
				}

			}
			printf("\n");
			flag = 1;
		}
	}
	if (flag == 0)
		printf("No perfect number");

}

int main() {
	int m, n;

	scanf("%d %d", &m, &n);
	if ( factorsum(m) == m )
		printf("%d is a perfect number\n", m);
	if ( factorsum(n) == n )
		printf("%d is a perfect number\n", n);
	PrintPN(m, n);

	return 0;
}
