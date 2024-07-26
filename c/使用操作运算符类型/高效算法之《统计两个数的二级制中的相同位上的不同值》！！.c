#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//统计两个数的二进制中的相同位上的不同值
int count_diff_bit(int n, int m) {
	int cnt = 0;
	//'^'异或操作符
	//相同为0 ，相异为1
	int ret = m ^ n;
	/*
	假设我们有两个整数 n = 5 (二进制表示为 101) 和 m = 3 (二进制表示为 011)。

	现在我们对这两个整数进行异或操作：

	  101   (n = 5)
	^ 011   (m = 3)
	-----
	  110   (ret = 6)
	所以，m ^ n 的结果是 6（二进制表示为 110）。这表示在二进制中，n 和 m 中不同的位是1，相同的位是0。

	因此，int ret = m ^ n; 这一步操作的结果就是得到了两个整数二进制表示中不同的位，用一个新的整数来表示。
	*/
//将得到的ret值进制判断值中有几个1就表示 n 与 m 中相同位上有几个不同值
	while (ret != 0) {
		ret = ret & (ret - 1);
		cnt++;
	}
	return cnt;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int c =  count_diff_bit( n, m) ;
	printf("%d", c);
	return 0;
}