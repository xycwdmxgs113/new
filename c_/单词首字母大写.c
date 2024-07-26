#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {
	char ch, p = ' ';
	while ((ch = getchar()) != '\n') {
		if ((ch >= 'a' && ch <= 'z') && p == ' ') {
			ch = ch - 'a' + 'A';
		}
		/*
		if (ch>='a'&&ch<='z'&&prev==' ') ch=ch-'a'+'A';:
		这行代码使用了条件语句 if。
		它首先检查当前字符 ch 是否是小写字母（即 ASCII 码在 'a' 和 'z' 之间）
		同时上一个字符 p 是否为空格
		如果条件满足，即当前字符是单词的第一个字母且前面有空格，那么执行大写转换：将当前字符减去小写字母 'a' 的 ASCII 码
		然后加上大写字母 'A' 的 ASCII 码，从而将小写字母转换为大写字母。
		*/
		printf("%c", ch);
		p = ch;
	}


	return 0;
}