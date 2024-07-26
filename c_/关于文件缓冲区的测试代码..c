#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>c
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
#include<Windows.h>
int main() {
	FILE* pf = fopen("text.txt", "w");
		fputs("abcdef", pf);//先将代码放到缓冲区
		printf("睡眠十秒-已经写入数据，打开text.txt文件，发现文件没有内容\n");
		Sleep(10000);
		printf("刷新缓冲区\n");
		fflush(pf);//刷新缓冲区时，才将缓冲区的数据写到文件中(磁盘)
		printf("再次睡眠10秒，打开text.txt文件，发现文件有内容\n");
		Sleep(10000);
		//文件关闭时也会刷新缓冲区
		fclose(pf);
		pf = NULL;

	return 0;
}