#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>


int  critic(void ) {
	int num;
	printf("NO luck,my friend.Try again.\n");
	scanf("%d", &num);
	return num;
}
int main() {
	int num;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &num);
	while (num != 56) 
		 num = critic();
		 printf("You must have looked it up!\n");

	return 0;
}