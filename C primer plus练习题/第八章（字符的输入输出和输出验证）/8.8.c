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

void menu(void) {
	printf("Enter the opteration of your choice:\n");
	printf("a.add(¼Ó)\t s.subtract(¼õ)\n m.multiply(³Ë)\t d.divide(³ý)\n q.quit(ÍË³ö)\n");
}

float metter(void) {
	float a;
	char ch;
	while (scanf("%f", &a) != 1) {
		while ((ch = getchar()) != '\n')
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