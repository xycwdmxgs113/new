#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

typedef struct year {
	char year_name[10];
	char year_names[4];
	int day;
	int month_day;
}year;


int Daysum(year* p1, char p2[],int num) {
	int i;
	int flag = -1;
	for (i = 0;i < num;i++) {
		if (strcmp(p1[i].year_names, p2) == 0)
		{
			flag = i;
			break;
		}
	}
	if (flag==-1) {
		return -1;
	}
	int sum = 0;
	for (int k = 0;k <=flag;k++) {
		sum += p1[k].day;
	}
	return sum;
}

int main() {
	year arr1[12] = {
		{"January", "Jan", 31, 1},
		{"February", "Feb", 28, 2},
		{"March", "Mar", 31, 3},
		{"April", "Apr", 30, 4},
		{"May", "May", 31, 5},
		{"June", "Jun", 30, 6},
		{"July", "Jul", 31, 7},
		{"August", "Aug", 31, 8},
		{"September", "Sep", 30, 9},
		{"October", "Oct", 31, 10},
		{"November", "Nov", 30, 11},
		{"December", "Dec", 31, 12}
	};
	char arr2[10];
	scanf("%s", arr2);
	int sum=Daysum(arr1,arr2,12);
	printf("%d", sum);


	return 0;
}