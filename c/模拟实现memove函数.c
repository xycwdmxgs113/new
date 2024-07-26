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
#include<errno.h>

//void *my_memcpy(void* dest, const void* src, size_t num) {
//	assert(dest && src);
//	void* ret = dest;
//	while (num--) {
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
void* my_memmove(void* dest, const void* src, size_t num) {

	assert(dest && src);
		void* ret = dest;
	if (dest < src) {
		//前向后

		while (num--) {
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		
		}
	}
	else {
		//后向前
		while (num--) {
			*((char*)dest + num) = *((char*)src + num);

		}

	}
	return ret;
}
int main() {
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1, arr1+2,20);
	for(int i=0;i<10;i++)
	printf("%d ", arr1[i]);
	return 0;
}