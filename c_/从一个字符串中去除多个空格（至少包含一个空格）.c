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
    int spaceFlag = 0; // ���ڱ���Ƿ��Ѿ����ƹ�һ���ո�

    // ���Ʒǿո��ַ������� s1��������һ���ո�
    while (*p1 != '\0') {
        if (*p1 != ' ') {
            *p2++ = *p1;
            spaceFlag = 0; // ��������ǿո��ַ������� spaceFlag
        }
        else {
            if (!spaceFlag) { // ֻ�е�һ���ո񱻸���
                *p2++ = *p1;
                spaceFlag = 1; // ���� spaceFlag����ʾ�Ѿ����ƹ�һ���ո�
            }
        }
        p1++;
    }
    *p2 = '\0'; // ����ַ�����β

    // �� s1 �е����ݸ��ƻ�ԭʼ���� arr
    strcpy(arr, s1);
}

int main() {
	char arr[] = "A  B   C   DE  F";
	deblank(arr);
	printf("%s", arr);
	return 0;
}