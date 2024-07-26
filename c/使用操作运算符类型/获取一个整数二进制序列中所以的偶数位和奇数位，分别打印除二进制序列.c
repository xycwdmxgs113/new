#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//获取一个整数二进制序列中所以的偶数位和奇数位，分别打印除二进制序列
//10的二级制为
//00000000 00000000 00000000 00001010
int main() {
	int i = 0;
	int num = 0;
	scanf("%d", &num);

	//取偶数位
	for (i = 30; i >= 0; i -= 2) {
		printf("%d ", ((num >> i) & 1));
	}
	printf("\n");
	//取奇数位
	for (i = 31; i >= 0; i -= 2) {
		printf("%d ", ((num >> i) & 1));
	}
	return 0;
}

/*
让我们通过一个具体的例子来演示如何使用位操作 ((num >> i) & 1) 来获取整数的特定位上的值。

假设我们有一个整数 num = 42，它的二进制表示是 101010。现在，我们将用代码来获取这个整数的每一位的值。

首先，让我们用 i = 5 来获取整数 num 的第 5 位（从右往左数，从 0 开始）的值：

int num = 42;
int i = 5;
int bit_value = (num >> i) & 1;
printf("Bit at position %d: %d\n", i, bit_value);
现在让我们看一下运算过程：

将 num = 42 的二进制表示向右移动 5 位： 101010 右移 5 位得到 000000。
将移位后的结果与 1 进行位与操作：000000 & 000001 = 000000。
因此，第 5 位的值为 0。
现在让我们再尝试获取第 3 位的值，即 i = 3：

i = 3;
bit_value = (num >> i) & 1;
printf("Bit at position %d: %d\n", i, bit_value);
运算过程如下：

将 num = 42 的二进制表示向右移动 3 位： 101010 右移 3 位得到 000101。
将移位后的结果与 1 进行位与操作：000101 & 000001 = 000001。
因此，第 3 位的值为 1。
*/