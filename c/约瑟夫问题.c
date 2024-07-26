#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAXN 20

void CountOff( int n, int m, int out[] ) {
	int finger = 0; //�������㿪ʼ
	int cnt = 1;		//ͳ��������һ��ʼ
	int i;
	for (i = 0; i < n; i++)
		out[i] = 0; //��ʼ���˳��˵�����Ϊ0��

	while (cnt <= n) { //���˳�����ֻʣ�����һ���˵�ʱ���˳�ѭ��
		for (i = 0; i < n; i++) { //ÿһ��ѭ�������Կ�����һ����Ϸ����ÿһ���˳���ͽ�����һ��
			if (out[i] == 0) { //ѭ����������out�����Ԫ��Ϊ0���ʾ��ǰ�˻�û���˳�
				finger++;//ָ����һ����
			}
			if (finger == m) {//��ָ�Ĵ�������m
				out[i] = cnt;//������Ա�ı�ű��Ϊ cnt������ out[i] ��ֵ��Ϊ cnt����ʾ����Ա�Ѿ�����,�´�ѭ���ͻ�������ǰ��
				cnt++;// �߳���ǰ����
				finger = 0;//��ʼ���¼���
			}
		}
	}
}

int main() {
	int out[MAXN], n, m;
	int i;

	scanf("%d %d", &n, &m);
	CountOff( n, m, out );
	for ( i = 0; i < n; i++ )
		printf("%d ", out[i]);
	printf("\n");
	return 0;
}

