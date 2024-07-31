#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

double my_power(double n, int p) {
	if (n == 0 && p == 0)
		return 1;
	if (n == 0)
		return 0;
	if (p == 0)
		return 1;

	if (p > 0) {
		return n * my_power(n, p - 1);
	} else

		return 1.0 / (n * my_power(n, -p - 1));

}

int main() {
	double a;
	int b;
	scanf("%lf %d", &a, &b);
	double k = my_power(a, b);
	printf("%lf", k);

	return 0;
}
*/*
��������Ҫ���� 2 �� 3 ���ݣ��� my_power(2, 3)��

���ȣ���������������������Ϊ p ���� 0���������������һ���֡��������ǽ��� if (p > 0) ��֧��

�������֧�У����ǽ����� n���� 2������ my_power(n, p - 1) �Ľ����Ҳ���Ǽ��� 2 * my_power(2, 2)��

���ڣ�������Ҫ���� my_power(2, 2)��ͬ���أ���Ϊ p ��Ȼ���� 0�����Ǽ������� if (p > 0) ��֧��

���ǽ����� n���� 2������ my_power(n, p - 1) �Ľ����Ҳ���Ǽ��� 2 * my_power(2, 1)��

���ڣ�������Ҫ���� my_power(2, 1)����Ϊ p ��Ȼ���� 0�����Ǽ������� if (p > 0) ��֧��

���ǽ����� n���� 2������ my_power(n, p - 1) �Ľ����Ҳ���Ǽ��� 2 * my_power(2, 0)��

���ڣ�������Ҫ���� my_power(2, 0)�����ݻ���������κ����� 0 ���ݶ�Ϊ 1�����Է��� 1��

���ڣ����ص���һ�����ã������� my_power(2, 1) �ĵط�����ʱ�����Ϊ 2 * 1 = 2��

�ٴη��ص���һ�����ã������� my_power(2, 2) �ĵط�����ʱ�����Ϊ 2 * 2 = 4��

�ٴη��ص�����ĵ��ã������� my_power(2, 3) �ĵط�����ʱ�����Ϊ 2 * 4 = 8��

���գ��������� 8������� 2 �� 3 ���ݵĽ����*/