#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include <stdio.h>

//������� ���е����ֵ�е��е���Сֵ
int main() {
	int n, i, j, k;
	int max, flag; // max���ڼ�¼���е����Ԫ�ص�λ�ã�flag���ڱ���Ƿ�Ϊ����λ��
	scanf("%d", &n);
	int a[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	for (i = 0; i < n; i++) {
		max = 0; // ��ʼ�����Ԫ��λ��Ϊ0
		for (j = 0; j < n; j++) {
			if (a[i][j] >= a[i][max]) // �ҵ���ǰ�е����Ԫ��λ��
				max = j;
		}

		flag = 1; // ���赱ǰλ��������λ��
		for (k = 0; k < n; k++) {
			if (a[i][max] > a[k][max]) {
				flag = 0; // ������ڱȵ�ǰλ��Ԫ��С��Ԫ�أ���flag��Ϊ0
				break;
			}
		}

		if (flag == 1) { // flagΪ1��ʾ��ǰλ��������λ��
			printf("%d %d\n", i, max);
			break;
		}
	}

	if (flag == 0) // flagΪ0��ʾ����������λ��
		printf("NONE\n");

	return 0;
}