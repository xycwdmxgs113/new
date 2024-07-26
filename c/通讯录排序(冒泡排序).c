#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//通讯录排序
/*
输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序
按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。

输入格式:
输入第一行给出正整数n（<10）。
随后n行，每行按照“姓名 生日 电话号码”的格式给出一位朋友的信息
其中“姓名”是长度不超过10的英文字母组成的字符串
“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。


*/
struct birthday {
	unsigned long int x;
};

struct Contacts {
	char name[11];
	struct birthday birth;
	char number[18];
};

int main() {
	int n;
	scanf("%d", &n);
	struct Contacts *number = (struct Contacts *)malloc(n * sizeof(struct Contacts));
	struct Contacts t;


	for (int i = 0; i < n; i++) {
		scanf("%s", number[i].name);
		scanf("%ld", &number[i].birth.x);
		scanf("%s", number[i].number);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (number[j].birth.x > number[j + 1].birth.x) {
				struct Contacts temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s %ld %s", number[i].name, number[i].birth.x, number[i].number);
		printf("\n");
	}
	return 0;
}