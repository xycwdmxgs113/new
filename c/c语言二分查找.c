#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>

// 二分查找只适用于有序数
int main() {
	int flag = 0; //定义一个开关函数 如果没找到则为0
	int a[] = {1, 2, 3, 4, 5, 6, 6, 6, 6};
	int begin = 0; //定义数组头下标值
	int end = sizeof(a) / sizeof(a[0]) - 1;//定义数组尾下标值
	int find, middle;//定义中间值与要查找的数值
	printf("请输入要查找的数");
	scanf("%d", &find);
	while (begin <= end) {
		middle = (begin + end) / 2; //中间值
		if (find > a[middle]) {//当要找的数值比中间值大的时候
			begin = middle + 1;	//再次定义数组头下标值;
		} else if (find < a[middle]) {//反之
			end = middle - 1;//再次定义数组尾下标值;
		} else {
			printf("找到了下标为%d\n", middle);
			flag = 1;
			int t = middle - 1;
			/*
			以下两个while循环是保证找到值后 去查找这个find值的左右两边有没有相同值
			如果有则继续输入下标 然后再次进入循环去查找 直到没用为止
			*/
			while (t >= 0 && a[t] == find) { //t大于0 和t<=end 是为了保证数值不出现下标越界的情况
				printf("找到了下标为%d\n", t--);
			}
			t = middle + 1;
			while (t <= end && a[t] == find) {
				printf("找到了下标为%d\n", t++);
			}
			break;
		}
	}
	if (flag == 0) {
		printf("没找到");
	}

	return 0;
}
