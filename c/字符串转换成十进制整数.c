#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*
����һ����#�������ַ���������Ҫ����ȥ���еķ�ʮ�������ַ������ִ�Сд�������һ���µı�ʾʮ���������ֵ��ַ�����Ȼ����ת��Ϊʮ�����������������ڵ�һ��ʮ�������ַ�֮ǰ�����ַ���-�������������Ǹ�����

�����ʽ��
������һ���и���һ����#�����ķǿ��ַ�����

�����ʽ��
��һ�������ת�����ʮ����������Ŀ��֤����ڳ����ͷ�Χ�ڡ�

����������
+-P-xf4+-1!#
���������
-3905
*/
int pd(char *pa) {
	int flag = 0;
	if ((*pa >= '0' && *pa <= '9') || (*pa >= 'a' && *pa <= 'f') || (*pa >= 'A' && *pa <= 'F') || (*pa == '-'
	        || *pa == '+'))
		flag = 1;
	return flag;
}

int main() {
	char a[100], *pa;
	int i = 0;
	while ((a[i] = getchar()) != '#')
		i++;
	a[i] = '\0';
	pa = a;
	int k = 0;
	while (*pa != '\0') {
		if (pd(pa) == 1) {
			a[k] = *pa;
			k++;
		}
		pa++;
	}
	a[k] = '\0';
	printf("%s\n", a);
	int flag = 1;
	for (i = 0; a[i] != '\0'; i++) {
		if ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'a' && a[i] <= 'f') || (a[i] >= 'A' && a[i] <= 'F')) {
			break;
		} else {
			if (a[i] == '-') {
				flag = -1;
			}
		}
	}
	long int sum = 0;
	for (k = 0; a[k] != '\0'; k++) {
		if (a[k] >= '0' && a[k] <= '9')
			sum = sum * 16 + a[k] - '0';
		else if (a[k] >= 'a' && a[k] <= 'f')
			sum = sum * 16 + a[k] - 'a' + 10;
		else if (a[k] >= 'A' && (a[k] <= 'F'))
			sum = sum * 16 + a[k] - 'A' + 10;
	}

	printf("%ld", flag * sum);

	return 0;
}