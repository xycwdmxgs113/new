#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
#include<Windows.h>
int main() {
	FILE* pf = fopen("text.txt", "w");
		fputs("abcdef", pf);
		printf("˯��ʮ��-�Ѿ�д�����ݣ���text.txt�ļ��������ļ�û������\n");
		Sleep(10000);
		fflush(pf);
		printf("�ٴ�˯��10�룬��text.txt�ļ��������ļ�������\n");
		Sleep(10000);
		fclose(pf);
		pf = NULL;

	return 0;
}