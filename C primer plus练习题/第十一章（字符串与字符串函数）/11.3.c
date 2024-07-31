#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void move(char* arr) {
    while ((*arr= getchar()) != '\n' && *arr != ' ' && *arr != '\t') {
        arr++;
    }
    *arr = '\0';
}

int main() {
	char arr[100];
	move(arr);
    printf("%s",arr);

	return 0;	
 }