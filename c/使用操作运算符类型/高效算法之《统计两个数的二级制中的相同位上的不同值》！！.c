#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//ͳ���������Ķ������е���ͬλ�ϵĲ�ֵͬ
int count_diff_bit(int n, int m) {
	int cnt = 0;
	//'^'��������
	//��ͬΪ0 ������Ϊ1
	int ret = m ^ n;
	/*
	������������������ n = 5 (�����Ʊ�ʾΪ 101) �� m = 3 (�����Ʊ�ʾΪ 011)��

	�������Ƕ�����������������������

	  101   (n = 5)
	^ 011   (m = 3)
	-----
	  110   (ret = 6)
	���ԣ�m ^ n �Ľ���� 6�������Ʊ�ʾΪ 110�������ʾ�ڶ������У�n �� m �в�ͬ��λ��1����ͬ��λ��0��

	��ˣ�int ret = m ^ n; ��һ�������Ľ�����ǵõ����������������Ʊ�ʾ�в�ͬ��λ����һ���µ���������ʾ��
	*/
//���õ���retֵ�����ж�ֵ���м���1�ͱ�ʾ n �� m ����ͬλ���м�����ֵͬ
	while (ret != 0) {
		ret = ret & (ret - 1);
		cnt++;
	}
	return cnt;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int c =  count_diff_bit( n, m) ;
	printf("%d", c);
	return 0;
}