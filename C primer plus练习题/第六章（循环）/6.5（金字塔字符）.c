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
	char ch;
	scanf("%c", &ch);
	int j;
	int len = ch - 'A' + 1;
	for (int i = 1; i <= len; i++) {
		//���ѭ�����ƴ�ӡ������lenΪ������ַ��͡�A'�Ĳ��һ
		for ( j = 0; j < len - i; j++)
			printf(" ");
		/*
			��ӡ�ո������ո���Ϊ���ַ���-��ӡ���ַ���
			������=�ո���+�ַ���
		*/
		for (ch = 'A'; j < len; j++)
			printf("%c", ch++);
		/*�ڴ�ӡ�����ַ�ʱ����Ҫͨ��ch������������
		  ��ʼֵj�ڿո��Ѿ�ͨ��ѭ�����˳�ʼ�� �����ֻ��Ҫ��ӡʣ���ַ���
		*/
		for (j = 1, ch -= 2; j < i; ch--, j++)
			printf("%c", ch);
		printf("\n");
	}
	return 0;
}