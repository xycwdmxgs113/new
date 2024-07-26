#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>

int fib( int n );
void PrintFN( int m, int n );

int fib( int n ) {
	if (n == 2 || n == 1) {
		return 1;
	}
	int a = 1, b = 1, sum;
	for (int i = 3; i <= n; i++) {
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}

void PrintFN( int m, int n ) {
	int flag = 1, f = 1, sum = 0;
//flag �ж����� 쳲��������� f����ֵ ��f=1 ��֮������� Ȼ��f=0 ���һ���ո����
	for (int i = 1;; i++) {
		sum = fib(i);
		if (sum > n) {
			break;
		}
		if (sum >= m && sum <= n) {
			if (f) {
				printf("%d", sum);
				f = 0;
			} else {
				printf(" %d", sum);
				flag = 0;
			}
		}

	}
	if (flag == 1) {
		printf("No Fibonacci number");
	}
}

int main() {
	int m, n, t;

	scanf("%d %d %d", &m, &n, &t);
	printf("fib(%d) = %d\n", t, fib(t));
	PrintFN(m, n);

	return 0;
}
