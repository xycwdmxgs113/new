#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAXN 20


//本题要求编写程序，读入5个字符串，按由小到大的顺序输出。
int main() {
	char a[5][80];//创建5个一维数组大小为80的二维字符串数组
	char *p[5];//创建长度为5的指针数组
	//指针数组：指针数组是数组 数组的每一个元素都是指针
	for (int i = 0; i < 5; i++) {
		scanf("%s", a[i]);//输入字符串
		p[i] = a[i];//获取每个字符串的首地址
	}
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (strcmp(p[i], p[j]) > 0) {//通过strcmp函数比较的两个字符串的地址
				char *t = p[i];//创建char类型指针t 存放p[i]的地址
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
