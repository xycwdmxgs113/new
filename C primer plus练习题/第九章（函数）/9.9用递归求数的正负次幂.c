#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

double my_power(double n, int p) {
	if (n == 0 && p == 0)
		return 1;
	if (n == 0)
		return 0;
	if (p == 0)
		return 1;

	if (p > 0) {
		return n * my_power(n, p - 1);
	} else

		return 1.0 / (n * my_power(n, -p - 1));

}

int main() {
	double a;
	int b;
	scanf("%lf %d", &a, &b);
	double k = my_power(a, b);
	printf("%lf", k);

	return 0;
}
*/*
假设我们要计算 2 的 3 次幂，即 my_power(2, 3)。

首先，函数将检查特殊情况，因为 p 大于 0，不是特殊情况的一部分。所以我们进入 if (p > 0) 分支。

在这个分支中，我们将底数 n（即 2）乘以 my_power(n, p - 1) 的结果。也就是计算 2 * my_power(2, 2)。

现在，我们需要计算 my_power(2, 2)。同样地，因为 p 仍然大于 0，我们继续进入 if (p > 0) 分支。

我们将底数 n（即 2）乘以 my_power(n, p - 1) 的结果。也就是计算 2 * my_power(2, 1)。

现在，我们需要计算 my_power(2, 1)。因为 p 仍然大于 0，我们继续进入 if (p > 0) 分支。

我们将底数 n（即 2）乘以 my_power(n, p - 1) 的结果。也就是计算 2 * my_power(2, 0)。

现在，我们需要计算 my_power(2, 0)。根据基本情况，任何数的 0 次幂都为 1，所以返回 1。

现在，返回到上一级调用，即计算 my_power(2, 1) 的地方。此时，结果为 2 * 1 = 2。

再次返回到上一级调用，即计算 my_power(2, 2) 的地方。此时，结果为 2 * 2 = 4。

再次返回到最初的调用，即计算 my_power(2, 3) 的地方。此时，结果为 2 * 4 = 8。

最终，函数返回 8，这就是 2 的 3 次幂的结果。*/