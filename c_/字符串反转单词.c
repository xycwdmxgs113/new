#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

// 反转字符函数
void reverse(char* pa,char *pb) {
	while (pa < pb) {
		char t = *pa;
		*pa = *pb;
		*pb = t;
		pa++, pb--;
	}

}

void reverse_world(char *arr) {
	char* pa = arr;
	int len = strlen(arr);
	char* pb = &arr[len-1];
	
	reverse(pa, pb);
	
	pa = arr;
	pb = pa;
	while(*pb!='\0'){
		while (*pa != ' ' && *pa != '\0') { //寻找单词终点
			pa++; 
		}
		
		reverse(pb, pa-1);//反转单词  -1是为了去掉空格 正确的反转
		if (*pa == ' ') {
			pa++; //加一越过空格
			
		}
		pb = pa; //将起点重新赋给pb；
	}

}
int main() {

	char arr[] = "hello world";
	reverse_world(arr);
	printf("%s", arr);

	return 0;
}