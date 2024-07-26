#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
//char * my_strcpy(char* arr2,const char* arr1)
//{
//	assert(arr1&&arr2);
//	char* temp = arr2;
//	while (*arr2++ = *arr1++);
//
//	*arr2 = '\0';
//	return temp;
//}
//
//char* my_strncat(char* arr1, char* arr2,int n) {
//	char* ret = arr1;
//	assert(arr1 && arr2);
//	while (*arr1)
//		arr1++;
//	while (n > 0) {
//		*arr1++ = *arr2++;
//		n--;
//	}
//	//*arr1 = '\0';
//	return ret;
//}
//
//int my_strcmp(const char* str1, const char* str2) {
//	assert(str1 && str2);
//	while (*str1 == *str2) {
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//
//int main() {
//	char arr1[20] = "abcdez";
//	char arr2[20] = "abc";
//	my_strncat(arr1, arr2,6);
//	printf("%s", arr1);
//
//	int len = my_strcmp(arr1, arr2);
//	//printf("%d\n", len);
//	return 0;
//}

char* my_strstr(const char* str1, const char* str2) {
	assert(str1 && str2);
	const char* s1 = str1;
	const char * s2 = str2;
	const char* p = str1;
	while (*p) {
		s1 = p;
		s2 = str2;
		while (*s1!='\0'&& *s2 != '\0'&& * s1 == *s2) {
			s1++;
			s2++;
		}
		if (*s2 == '\0') {
			return p;
		}
		p++;
	}
	return NULL;
}

int main() {
	char enmail[] = "@2204438535.com";
	char sub[] = "204438535";
	char* ret = my_strstr(enmail, sub);
	if (ret == NULL)
		printf("²»´æÔÚ");
	else
		printf("%s",ret);


	return 0;
}