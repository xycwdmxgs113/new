#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAXN 10

//����ѭ������
/*
����Ϊ6 2
1 2 3 4 5 6

���Ϊ5 6 1 2 3 4
*/
void ArrayShift( int a[], int n, int m ) {
	int b[n];
	int i;
	for (i = 0; i < n; i++)
		b[i] = a[i];
	for (int i = 0; i < n; i++) {
		a[(m + i) % n] = b[i];
//ע�ⲻ�ܽ�	a[(m + i) % n] = b[i]�ĳ�a[i] = b[(m+i)%n]
		/*
		��ʹ�� a[(m+i)%n] = b[i] ʱ��

		����д������˼�ǣ�����ʱ���� b[] �еĵ� i ��Ԫ�ظ��Ƶ�ԭ���� a[] ���±�Ϊ (m+i)%n ��λ�á�
		����������ȷ��ÿ��Ԫ�ض�����ȷ���ƶ�����Ӧ��λ�ã�ʵ������������ѭ���ƶ� m ��λ�õĹ��ܡ�
		���ĳ� a[i] = b[(m+i)%n] ʱ��

		����д������˼�ǣ�����ʱ���� b[] �еĵ� (m+i)%n ��Ԫ�ظ��Ƶ�ԭ���� a[] ���±�Ϊ i ��λ�á�
		�����ᵼ��Ԫ�����ƶ������д�λ�������޷���ȷʵ����������ѭ���ƶ���Ч����
		*/
	}
}

int main() {
	int a[MAXN], n, m;
	int i;

	scanf("%d %d", &n, &m);
	for ( i = 0; i < n; i++ )
		scanf("%d", &a[i]);

	ArrayShift(a, n, m);

	for ( i = 0; i < n; i++ ) {
		if (i != 0)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");

	return 0;
}
