#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
	
//void inversion(char arr[]) {
//	char b[100];
//	char *pc = b;
//
//	int len = strlen(arr);
//	char* pa = &arr[len - 1];
//	char* pb = pa;
//	
//	while (pa >= arr) {
//		
//		if (*pa == ' ' || pa == arr) {
//			char* ppa = pa + (pa == arr ? 0 : 1);
//			while (ppa <= pb) {
//				*pc = *ppa;
//				ppa++;
//				pc++;
//			}
//			*(pc) = (pa == arr ? ' ' : *(pa - 1));
//			pb = pa;
//		}
//		pa--;
//	}
//	*pc = '\0';
//	strcpy(arr, b);
//
//}

void reverse(char* pa, char* pb) {
	while (pa < pb) {
		char t = *pa;
		*pa = *pb;
		*pb = t;
		pa++, pb--;
	}
}


int main() {
	char arr[100];
	gets(arr);
	int len = strlen(arr);
	reverse(arr, arr + len-1);
	
	char* start = arr;
	char* end = arr;
	
	while (*start != '\0') {
		while (*end != ' '&&*end!='\0') {

			end++;
		}
		reverse(start, end - 1);
		if(*end!='\0')
		end++;
		start = end;
	}

	printf("%s", arr);

	return 0;
}
