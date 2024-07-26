#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



#define MAX 10

//最大字符位移。将最大字符找出并且位移到首地址
int main(void) {
	/*
	定义了变量 max（用于保存最大字符）、
	字符数组 str（用于存储输入的字符串）、指针 p 和 q（分别指向字符串 str 的起始位置）。
	*/
	char max, str[80], *p = str, *q = str;
	gets(s);
	max = *(p++);
//max = *(p++);：将指针 p 指向的第一个字符的值赋给 max，然后将 p 指针后移一个位置。
	while (*p != '\0') {
		/*
		如果*p比max的字符大则更新max字符
		同时将最大字符的地址赋值给q；
		*/
		if (max < *p) {
			max = *p;
			q = p;
		}
		p++;
	}
	p = q; //重新更新p的地址 将原本指向最后一个字符的地址更新为指向最大字符的地址
	while (p > str[0]) {
		*p = *(p - 1); //这段代码是将将当前指针 p 指向的元素更新为前一个位置的元素
		//注意地址减1等于往前推！！！而不是往后推
		//例如  knowledge 最大的是w
		//所以将w的地址减1得到前面一个元素的地址（o） 然后w元素改为o 以此类推
		p--;
	}
	*p = max; //讲首地址字符改为最大字符 变完成了最大字符位移
	puts(p);
	return 0;
}
