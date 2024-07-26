#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>



int main() {
	int m, n;
	scanf("%d%d", &m, &n);//m为偏移量 n为数字元素个数
	int a[n][n] ;
	int b[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = (j + m)  % n;//// 计算出每个元素的目标位置(及需要位移的位置);
			a[i][t] = b[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
首先，在 main 函数中声明了两个变量 m 和 n，并通过 scanf 函数从用户输入中获取这两个值。m 表示偏移量，n 表示二维数组的大小。

然后，定义了两个二维数组 a 和 b，它们都具有 n 行 n 列的大小。数组 a 用于存储用户输入的元素，数组 b 是 a 的副本用于保存原始数据。

接下来，使用嵌套的循环结构，依次读取用户输入的每个元素，并将其赋值给数组 a 中对应的位置。

然后，通过两个嵌套的循环，将数组 a 中的元素复制到数组 b 中。

接下来，再次使用两个嵌套的循环，进行循环右移操作。通过 (j + m) % n 计算出每个元素的目标位置，并将数组 b 中对应位置的元素赋值给数组 a 的目标位置。

最后，使用两个嵌套的循环，遍历数组 a 并打印出其中的元素。每行打印完毕后，使用 printf("\n") 打印一个换行符。

整个程序的作用是将用户输入的二维数组按照给定的偏移量进行循环右移，并打印出移位后的结果。
*/