#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>



int main() {
	char arr[100];
	gets(arr);
	int len = strlen(arr);
	int sum1, sum2, sum3, sum4, sum5;
	sum1 = sum2 = sum3 = sum4 = sum5 = 0;
	for (int i = 0;i < len;i++) {
        if (isupper(arr[i])) {
            sum2++;
        }
        if (islower(arr[i])) {
            sum3++;
        }
        if (ispunct(arr[i])) {
            sum4++;
        }
        if (isdigit(arr[i])) {
            sum5++;
        }
	}

    char* pa = arr;
    if (*pa != ' ') {
        sum1++;
    }
    while (*pa != '\0') {
        if (*pa == ' ') {
            if (*(pa - 1) != ' ')
                sum1++;
            pa++;
        }
        pa++;
    }
    
	printf("������%d�� ��д��ĸ��%d ��Сд��ĸ%d�� ��������%d�� ������%d\n", sum1, sum2, sum3, sum4, sum5);


	return 0;
}