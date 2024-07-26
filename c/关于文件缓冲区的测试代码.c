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
		printf("睡眠十秒-已经写入数据，打开text.txt文件，发现文件没有内容\n");
		Sleep(10000);
		fflush(pf);
		printf("再次睡眠10秒，打开text.txt文件，发现文件有内容\n");
		Sleep(10000);
		fclose(pf);
		pf = NULL;

	return 0;
}