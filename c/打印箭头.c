#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>


int main() {
    int n;
    while ((scanf("%d", &n) == 1)) {
        //��ӡ��n��
        for (int i = 0;i < n;i++) {
            //��ӡ�ո�
            for (int j = 0;j < n - i;j++) {
                printf("  ");
            }
            for (int j = 0;j <=i;j++) {
                printf("*");
            }
            printf("\n");
        }
        //��ӡ��n��
        for (int i = 0;i < n+1;i++) {
            //��ӡ�ո�
            for (int j = 0;j <i;j++) {
                printf("  ");
            }
            for (int j = 0;j <n+1-i;j++) {
                printf("*");
            }
            printf("\n");
        }

    }

    return 0;
}