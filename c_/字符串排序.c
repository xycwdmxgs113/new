#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAXN 20


//����Ҫ���д���򣬶���5���ַ���������С�����˳�������
int main() {
	char a[5][80];//����5��һά�����СΪ80�Ķ�ά�ַ�������
	char *p[5];//��������Ϊ5��ָ������
	//ָ�����飺ָ������������ �����ÿһ��Ԫ�ض���ָ��
	for (int i = 0; i < 5; i++) {
		scanf("%s", a[i]);//�����ַ���
		p[i] = a[i];//��ȡÿ���ַ������׵�ַ
	}
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (strcmp(p[i], p[j]) > 0) {//ͨ��strcmp�����Ƚϵ������ַ����ĵ�ַ
				char *t = p[i];//����char����ָ��t ���p[i]�ĵ�ַ
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	printf("After sorted:\n");
	for (int i = 0; i < 5; i++)
		printf("%s\n", p[i]);

	return 0;
}
