#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include <stdio.h>

//鞍点就是 在行的最大值中的列的最小值
int main() {
	int n, i, j, k;
	int max, flag; // max用于记录行中的最大元素的位置，flag用于标记是否为特殊位置
	scanf("%d", &n);
	int a[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	for (i = 0; i < n; i++) {
		max = 0; // 初始化最大元素位置为0
		for (j = 0; j < n; j++) {
			if (a[i][j] >= a[i][max]) // 找到当前行的最大元素位置
				max = j;
		}

		flag = 1; // 假设当前位置是特殊位置
		for (k = 0; k < n; k++) {
			if (a[i][max] > a[k][max]) {
				flag = 0; // 如果存在比当前位置元素小的元素，则将flag设为0
				break;
			}
		}

		if (flag == 1) { // flag为1表示当前位置是特殊位置
			printf("%d %d\n", i, max);
			break;
		}
	}

	if (flag == 0) // flag为0表示不存在特殊位置
		printf("NONE\n");

	return 0;
}