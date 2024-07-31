#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

char * mystrnpy(char* a, char* b, int n) {
    int len = strlen(b);
    char* pa = a, * pb = b;
    if (n < len) {
        int cnt = 0;
        while (cnt < n) {
            *pa++ = *pb++;
            cnt++;
        }
        *pa = '\0';
    }
    else {
        while (*pb != '0') {
            *pa++ = *pb++;
        }
    }
    return pa;
}

int main() {
    char a[100];
    char b[100];
    int n;
    gets(b);
    scanf("%d", &n);
    mystrnpy(a, b, n);
    printf("%s", a);
    return 0;
}