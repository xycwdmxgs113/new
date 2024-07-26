#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>
int prime( int p );
void Goldbach( int n );

int prime( int p ) {
	int sum = 1;
	if (p == 1) {
		return 0;
	}
	for (int i = 2; i < p; i++) {
		if (p % i == 0) {
			sum = 0;
			break;
		}
	}
	return sum;
}

void Goldbach( int n ) {
	int p, q;
	for (int p = 2; p < n; p++) {
		if (prime(p) == 1) {
			q = n - p;
			if (prime(q) == 1) {
				printf("%d=%d+%d", n, p, q);
				break;//这个break是一定要的 因为每次只输出p的最小解 不加break这会输出一大堆
			}
		}
	}
}


int main() {
	int m, n, i, cnt;

	scanf("%d %d", &m, &n);
	if ( prime(m) != 0 )
		printf("%d is a prime number\n", m);
	if ( m < 6 )
		m = 6;
	if ( m % 2 )
		m++;
	cnt = 0;
	for ( i = m; i <= n; i += 2 ) {
		Goldbach(i);
		cnt++;
		if ( cnt % 5 )
			printf(", ");
		else
			printf("\n");
	}


	return 0;
}
