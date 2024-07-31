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
#include <stdio.h>

#define SINGLE 26677.5
#define HOUSEHOLD 3585
#define MARRIED 4462.5
#define DIVORCE 2231.25

void menu() {
	printf("****1:single*******\n");
	printf("****2:Household****\n");
	printf("****3:married******\n");
	printf("****4:divorce******\n");
	printf("****5:OVER\n");
}

int main() {
	int n;
	int money;

	while (1) {
		printf("Please choose an option:\n");
		menu();
		scanf("%d", &n);

		switch (n) {
			case 1:
				printf("How much have you deposited?\n");
				scanf("%d", &money);
				if (money <= 17850) {
					money -= SINGLE;
				} else {
					money -= ((money - 17850) * 0.28 + SINGLE);
				}
				printf("The balance is:%d\n", money);
				break;
			case 2:
				printf("How much have you deposited?\n");
				scanf("%d", &money);
				if (money <= 23900) {
					money -= HOUSEHOLD;
				} else {
					money -= ((money - 23900) * 0.28 + HOUSEHOLD);
				}
				printf("The balance is:%d\n", money);
				break;
			case 3:
				printf("How much have you deposited?\n");
				scanf("%d", &money);
				if (money <= 29750) {
					money -= MARRIED;
				} else {
					money -= ((money - 29750) * 0.28 + MARRIED);
				}
				printf("The balance is:%d\n", money);
				break;
			case 4:
				printf("How much have you deposited?\n");
				scanf("%d", &money);
				if (money <= 14875) {
					money -= DIVORCE;
				} else {
					money -= ((money - 14875) * 0.28 + DIVORCE);
				}
				printf("The balance is:%d\n", money);
				break;
			case 5:
				printf("Exiting...\n");
				return 0;
			default:
				printf("Invalid option\n");
				break;
		}
	}

	return 0;
}