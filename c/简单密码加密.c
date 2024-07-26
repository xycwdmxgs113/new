#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>



#define MAXLINE 80
#define M 26

int main () {
	int i, offset;
	char str[MAXLINE];
	i = 0;
	printf("Enter a string");
	while ((str[i] = getchar()) != '\n') {
		i++;
	}
	str[i] = '\0';

	printf("Enter offset:");
	scanf("%d", &offset);

	if (offset >= M) {
		offset = offset % M; //位移效果相当于取余数
	}

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if ((str[i] - 'A' + offset) < M) {
				str[i] = str[i] + offset;

			} else {
				str[i] = ((str[i] - 'A' + offset) % M + 'A');
				/*
				str[i] 表示字符串中第 i 个字符，其中 i 是字符串中的索引（位置）。
				M 是一个常数，表示字符的取值范围。在这个例子中，假设 M 代表 ASCII 码中可打印字符的个数，即 94（从空格到 '~'）。
				offset 是一个整数，s表示偏移量。它可以是任意值，用于控制加密或解密操作的规则。
				现在我们来看一个例子，假设我们有一个字符串 "Hello, world!"，并且我们希望对它进行加密操作。我们选择 M = 94 和 offset = 3。

				我们首先取出字符串中的第一个字符 "H"，并将其转换为 ASCII 码。ASCII 码中 "H" 的值是 72。
				然后，我们执行操作 str[i] = str[i] - (M - offset)。对于第一个字符来说，操作为 str[0] = 72 - (94 - 3)。
				计算结果为 str[0] = -19。
				然后，我们将结果转换回字符形式。在 ASCII 码中，-19 对应的字符是不可打印字符。
				我们继续对字符串中的下一个字符执行相同的操作，直到处理完所有字符。
				*/
			}
		}	else if (str[i] >= 'a' && str[i] <= 'z') {
			if ((str[i] - 'a' + offset) < M) {
				str[i] = str[i] + offset;
			} else {
				str[i] = (str[i] - 'a' + offset) % M + 'a';
			}
		}
	}
	printf("%s", str);
	return 0;
}
/*
首先，在 if (offset >= M) 的条件语句中，判断偏移量 offset 是否超过了字符集大小 M。如果超过了，就使用取余操作 offset = offset % M 来将偏移量限制在字符集范围内，以实现循环移位的效果。

接下来，通过一个循环遍历字符串中的每个字符。对于每个字符，首先判断它是否为大写字母（str[i] >= 'A' && str[i] <= 'Z'）。如果是大写字母，则执行下面的逻辑。

首先，计算字符 str[i] 相对于大写字母'A'的偏移量，即 (str[i] - 'A')。然后，将该偏移量加上之前获取到的偏移量 offset。如果得到的偏移量仍然小于字符集大小 M，则说明在字符集范围内，直接将其加到字符 str[i] 上，以得到移位后的字符。

如果得到的偏移量大于等于字符集大小 M，则需要进行调整。此时，将字符 str[i] 减去字符集大小 M，再加上偏移量 offset，以实现循环右移的效果。

对于小写字母（str[i] >= 'a' && str[i] <= 'z'）也是类似的操作，只是字符的范围不同。

最后，对于非字母字符，直接进行循环右移即可。这是因为非字母字符的 ASCII 码值超出了大写字母和小写字母的范围，所以不需要进行调整。

通过这样的操作，整个字符串中的每个字符都会根据给定的偏移量进行循环右移，从而实现字符串的移位操作。
*/

