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
//ѭ����������ᵼ������Ķ������� �Ƿ�����ʽ
void my_for(long n) {
	int a;
	while (n > 0) {
		a = n % 2;
		printf("%d ", a);
		n /= 2;
	}
}
//�����õݹ�����Ծ��ܺܺõĽ���������
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