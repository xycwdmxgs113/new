#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

// ��ת�ַ�����
void reverse(char* pa,char *pb) {
	while (pa < pb) {
		char t = *pa;
		*pa = *pb;
		*pb = t;
		pa++, pb--;
	}

}

void reverse_world(char *arr) {
	char* pa = arr;
	int len = strlen(arr);
	char* pb = &arr[len-1];
	
	reverse(pa, pb);
	
	pa = arr;
	pb = pa;
	while(*pb!='\0'){
		while (*pa != ' ' && *pa != '\0') { //Ѱ�ҵ����յ�
			pa++; 
		}
		
		reverse(pb, pa-1);//��ת����  -1��Ϊ��ȥ���ո� ��ȷ�ķ�ת
		if (*pa == ' ') {
			pa++; //��һԽ���ո�
			
		}
		pb = pa; //��������¸���pb��
	}

}
int main() {

	char arr[] = "hello world";
	reverse_world(arr);
	printf("%s", arr);

	return 0;
}