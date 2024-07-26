#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void game() {
	printf("欢迎来到猜数字游戏\n");
	printf("请在三十秒内猜到数字，如果猜不到电脑将关机\n");
	printf("嘻嘻^_^\n");
	//system("shutdown -s -t 20");
	int len = rand() % 100 + 1;
	printf("随机数已生成，请开始游戏\n");
	int n;
	scanf("%d", &n);
	while (1) {
		if (len > n)
			printf("猜小啦\n");
		else if (len < n)
			printf("猜大啦\n");
		else {
			printf("猜中啦\n");
			system("shutdown -a");
			break;
		}
		scanf("%d", &n);
	}
}

void menu() {
	printf("******1:开始*******\n");
	printf("******0:结束*******\n");
}

int main() {
	int k;
	srand((unsigned int)time(NULL));
	do {
		menu();
		scanf("%d", &k);
		switch (k) {
			case 1:
				game();
				break;
			case 0:
				break;
			default :
				break;
		}

	} while (k != 0);
	printf("加纳");
	return 0;
}