#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


//输出回型矩阵
int main() {
	int N;
	scanf("%d", &N);
	int n = 0;
	int cnt = 1;
	//设计起始坐标与终点坐标
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	int a[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = 0;
		}
	}

	while (1) {
		int j;
		//输入横向值
		x1 = n, y1 = n; //起始坐标为0.0
		x2 = x1, y2 = N - 1 - n; //确定重点坐标
		for (j = y1; j <= y2; j++)
			a[x1][j] = cnt++;

		//输入纵向值
		x1 = n + 1;
		y1 = j - 1;
		x2 = N - n - 1;
		y2 = y1;
		for (j = x1; j <= x2; j++)
			a[j][y1] = cnt++;

		//输入往回走横向值
		x1 = j - 1, y1 -= 1;
		x2 = x1;
		y2 = n;
		for (j = y1; j >= y2; j--)
			a[x1][j] = cnt++;

		//输入往回的纵向值
		x1 -= 1;
		y1 = n;
		x2 = n + 1;
		y2 = y1;
		for (j = x1; j >= x2; j--)
			a[j][y1] = cnt++;
		n++;
		if (cnt > N * N)
			break;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}