#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

int main() {
	float n, m;
	while (scanf("%f%f", &n, &m) == 2) {
		/*scanf()�����ķ���ֵ�ǳɹ���ȡ�����������ݵĸ���
		 ���ֻ�гɹ���ȡ������������ ����ֵ��Ϊ2*/
		printf("%f\n", (n - m) / (n * m));
	}
	return 0;
}