#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>



int isRotation(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2) {
		return 0;
	}
	strncat(s1, s1, len1);
	char *ret=strstr(s1, s2);
	if (ret != NULL)
		return 1;
	else
		return 0;
}

int main() {
	char s1[20];
	gets(s1);
	/*
	AABCDAABCD
	��s1׷�������Լ� ��ô���s1�ַ����Ͱ��������з�ת��s2���ַ���
	����ֻ��Ҫȥ����s1����û��s2 ����Ч�ʾʹ�����
	*/

	char s2[20];
	gets(s2);
	int ret= isRotation(s1, s2);
	printf("%d", ret);
	return 0;
}