#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>

int factorsum( int number );
void PrintPN( int m, int n );

//�������Ǹ���ǡ�õ��ڳ������������֮�͡����磺6=1+2+3������1��2��3Ϊ6�����ӡ�
int factorsum( int number ) {//factorsum���������жϸ����Ƿ�Ϊ����
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
	int flag = 0;//����ֵ �ж������Χ����û������
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
