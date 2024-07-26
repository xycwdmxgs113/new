#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



int main() {
	int a = 13;
	a |= (1 << 4);
	//0000 0000 0000 1101 a
	//'|'进行或  有1则1
	//0000 0000 0001 0000 1<<4
	//0000 0000 0001 1101 29
	printf("%d\n", a);//a=29
	a &= (~(1 << 4));
	//0000 0000 0001 0000 1<<4
	//1111 1111 1110 1111 ~(1<<4)

	//0000 0000 0001 1101 a=29
	//1111 1111 1110 1111 ~(1<<4)
	//进行“&”运算
	//0000 0000 0000 1101 a=13
	printf("%d\n", a); //a=13
	return 0;
}