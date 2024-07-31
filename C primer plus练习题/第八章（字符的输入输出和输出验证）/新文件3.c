#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>

//一个菜单函数 输出菜单选项
void menu(void) {
	printf("Enter the opteration of your choice:\n");
	printf("a.add(加)\t s.subtract(减)\n m.multiply(乘)\t d.divide(除)\n q.quit(退出)\n");
}

//以下函数是用来处理需要用户输入数字而却输入其他字符的情况
float metter(void) {
	float a;
	char ch;
	//利用scanf函数的返回值进行循环的判断条件
	//如果返回值不是1那么就可以得出用户输入的不是一个正确的数字
	//直到输入的是一个正确的数值则退出循环
	while (scanf("%f", &a) != 1) {
		/
		while ((ch = getchar()) != '\n')//内置一个while循环来将用户输入的字符进行输出并告知这是不正确的
			putchar(ch);
		printf(" is not an number\n");
		printf("please enter a number,such as 2.5,-1.78e8,or 3:");
	}
	return a;
}

int main() {
	char ch;
	float x, y;
	do {
		menu();
		scanf("%c", &ch);
		switch (ch) {
			case 'a':
				printf("Enter first number:");
				x = metter();
				printf("Enter second number:");
				y = metter();
				printf("%f+%f=%f\n", x, y, x + y);
				break;
			case 's':
				printf("Enter first number:");
				x = metter();
				printf("Enter second number:");
				y = metter();
				printf("%f-%f=%f\n", x, y, x - y);
				break;
			case 'm':
				printf("Enter first number:");
				x = metter();
				printf("Enter second number:");
				y = metter();
				printf("%f*%f=%f\n", x, y, x * y);
				break;
			case 'd':
				printf("Enter first number:");
				x = metter();
				printf("Enter second number:");
				y = metter();
				if (y == 0) {
					do {
						printf("Enter a number other than 0:");
						scanf("%f", &y);
					} while (y == 0);
				}
				printf("%f/%f=%f\n", x, y, x / y);
				break;
			default:
				break;
		}

	} while (ch != 'q');
	return 0;
}