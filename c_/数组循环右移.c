#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAXN 10

//数组循环右移
/*
输入为6 2
1 2 3 4 5 6

输出为5 6 1 2 3 4
*/
void ArrayShift( int a[], int n, int m ) {
	int b[n];
	int i;
	for (i = 0; i < n; i++)
		b[i] = a[i];
	for (int i = 0; i < n; i++) {
		a[(m + i) % n] = b[i];
//注意不能将	a[(m + i) % n] = b[i]改成a[i] = b[(m+i)%n]
		/*
		当使用 a[(m+i)%n] = b[i] 时：

		这种写法的意思是，将临时数组 b[] 中的第 i 个元素复制到原数组 a[] 中下标为 (m+i)%n 的位置。
		这样做可以确保每个元素都被正确地移动到相应的位置，实现了数组向右循环移动 m 个位置的功能。
		当改成 a[i] = b[(m+i)%n] 时：

		这种写法的意思是，将临时数组 b[] 中的第 (m+i)%n 个元素复制到原数组 a[] 中下标为 i 的位置。
		这样会导致元素在移动过程中错位，最终无法正确实现数组向右循环移动的效果。
		*/
	}
}

int main() {
	int a[MAXN], n, m;
	int i;

	scanf("%d %d", &n, &m);
	for ( i = 0; i < n; i++ )
		scanf("%d", &a[i]);

	ArrayShift(a, n, m);

	for ( i = 0; i < n; i++ ) {
		if (i != 0)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");

	return 0;
}
