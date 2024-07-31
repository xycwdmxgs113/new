#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

int main() {
	float n, m;
	while (scanf("%f%f", &n, &m) == 2) {
		/*scanf()函数的返回值是成功读取浮点类型数据的个数
		 因此只有成功读取两个浮点数据 返回值才为2*/
		printf("%f\n", (n - m) / (n * m));
	}
	return 0;
}