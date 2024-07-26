#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

void deblank(char* arr) {
    char s1[50];
    char* p1 = arr;
    char* p2 = s1;
    int spaceFlag = 0; // 用于标记是否已经复制过一个空格

    // 复制非空格字符到数组 s1，保留第一个空格
    while (*p1 != '\0') {
        if (*p1 != ' ') {
            *p2++ = *p1;
            spaceFlag = 0; // 如果遇到非空格字符，重置 spaceFlag
        }
        else {
            if (!spaceFlag) { // 只有第一个空格被复制
                *p2++ = *p1;
                spaceFlag = 1; // 设置 spaceFlag，表示已经复制过一个空格
            }
        }
        p1++;
    }
    *p2 = '\0'; // 添加字符串结尾

    // 将 s1 中的内容复制回原始数组 arr
    strcpy(arr, s1);
}

int main() {
	char arr[] = "A  B   C   DE  F";
	deblank(arr);
	printf("%s", arr);
	return 0;
}