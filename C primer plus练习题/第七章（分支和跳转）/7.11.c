#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio.h>

#define A 2.05
#define B 1.15
#define C 1.09

void menu() {
	printf("a:洋蓟 每磅2.05\n");
	printf("b:甜菜 每磅1.15\n");
	printf("c:胡萝卜 每磅1.09\n");
	printf("q:exit\n");
}

int main() {
	double sum = 0.0;
	double num = 0.0;
	double cnt = 0.0;
	float x, y, z;
	char ch;
	double zk = 0.0;

	menu();
	while ((ch = getchar()) != 'q') {
		switch (ch) {
			case 'a':
				printf("请输入需要购买洋蓟的磅数\n");
				scanf("%f", &x);
				num += x * A;
				if (x <= 5) {
					sum += x * A + 6.5;
					cnt += 6.5;
				} else if (x > 5 && x <= 20) {
					sum += x * A + 14;
					cnt += 14;
				} else {
					int k = x - 20;
					cnt += 14 + k * 0.5;
					sum += x * A + 14 + (k * 0.5);
				}
				break;
			case 'b':
				printf("请输入需要购买甜菜的磅数\n");
				scanf("%f", &y);
				num += y * B;
				if (y <= 5) {
					sum += y * B + 6.5;
					cnt += 6.5;
				} else if (y > 5 && y <= 20) {
					sum += y * B + 14;
					cnt += 14;
				} else {
					int k = y - 20;
					cnt += 14 + k * 0.5;
					sum += y * B + 14 + (k * 0.5);
				}
				break;
			case 'c':
				printf("请输入需要购买胡萝卜的磅数\n");
				scanf("%f", &z);
				num += z * C;
				if (z <= 5) {
					sum += z * C + 6.5;
					cnt += 6.5;
				} else if (z > 5 && z <= 20) {
					sum += z * C + 14;
					cnt += 14;
				} else {
					int k = z - 20;
					cnt += 14 + k * 0.5;
					sum += z * C + 14 + (k * 0.5);
				}
				break;
			default:
				break;
		}
	}

	if (num >= 100) {
		zk = num * 0.05;
	}
	printf("总费用为%.2f元 打折%.2f元 运输包装费用为%.2f元 所有费用为%.2f元", num, zk, cnt, sum - zk);

	return 0;
}