#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>


void Swap(char* arr1, char* arr2, int widh) {
	int i = 0;
	for (;i < widh;i++) {
		char t = *arr1;
		*arr1 = *arr2;
		*arr2 = t;
		arr1++;
		arr2++;
	}
}

void bubble_sort(void *arr,int sz,int widh,int(*cmp)(const void *e1,const void *e2)) {
	for (int i = 0;i < sz-1;i++) {
		for (int j = 0;j < sz - 1 - i;j++) {
			if (cmp((char*)arr+j*widh,(char *)arr+(j+1)*widh)>0) {
				//交换
				Swap((char*)arr + j * widh, (char*)arr + (j + 1) * widh, widh);

			}
		}
	}


}
//void qsort(void* base, //base指向待排序数组中的第一个元素的指针
//	size_t num, // base指向数组中的元素个数
//	size_t size,//base指向的数组中元素的大小，单位是字节
//	int (*compar)(const void*, const void*));//函数指针 比较函数 

int cmp_int(const void* e1, const void* e2) {
	return (*(int*)e2 - *(int*)e1);
}

void test1() {

	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0;i < sz;i++) {
		printf("%d ", arr[i]);
	}

}

struct Stu
{
	char name[20];
	int age;
};

int cmp_stu_by_name(const void* e1, const void* e2) {

	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int cmp_stu_by_age(const void* e1, const void* e2) {

	return (((struct Stu*)e1)->age - ((struct Stu*)e2)->age);
}

void test2() {
	//用qsort 排序结构体
	struct Stu s[3];
	for (int i = 0;i < 3;i++) {
		scanf("%s", &s[i].name);
		scanf("%d", &s[i].age);
	}
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	for (int i = 0;i < 3;i++) {
		printf("%s", s[i].name);
		printf("%d\n", s[i].age);
	}
}


void test3() {

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0;i < sz;i++) {
		printf("%d ", arr[i]);
	}

}

void test4() {
	struct Stu s[3];
	for (int i = 0;i < 3;i++) {
		scanf("%s", &s[i].name);
		scanf("%d", &s[i].age);
	}
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	for (int i = 0;i < 3;i++) {
		printf("%s", s[i].name);
		printf("%d\n", s[i].age);
	}
}

int main() {
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}