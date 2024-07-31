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
		//外层循环控制打印行数，len为输入的字符和‘A'的差加一
		for ( j = 0; j < len - i; j++)
			printf(" ");
		/*
			打印空格数，空格数为总字符数-打印的字符数
			总行数=空格数+字符数
		*/
		for (ch = 'A'; j < len; j++)
			printf("%c", ch++);
		/*在打印正序字符时，需要通过ch做递增操作，
		  起始值j在空格处已经通过循环做了初始化 ，因此只需要打印剩余字符数
		*/
		for (j = 1, ch -= 2; j < i; ch--, j++)
			printf("%c", ch);
		printf("\n");
	}
	return 0;
}