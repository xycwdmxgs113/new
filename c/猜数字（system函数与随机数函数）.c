#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void game() {
	printf("��ӭ������������Ϸ\n");
	printf("������ʮ���ڲµ����֣�����²������Խ��ػ�\n");
	printf("����^_^\n");
	//system("shutdown -s -t 20");
	int len = rand() % 100 + 1;
	printf("����������ɣ��뿪ʼ��Ϸ\n");
	int n;
	scanf("%d", &n);
	while (1) {
		if (len > n)
			printf("��С��\n");
		else if (len < n)
			printf("�´���\n");
		else {
			printf("������\n");
			system("shutdown -a");
			break;
		}
		scanf("%d", &n);
	}
}

void menu() {
	printf("******1:��ʼ*******\n");
	printf("******0:����*******\n");
}

int main() {
	int k;
	srand((unsigned int)time(NULL));
	do {
		menu();
		scanf("%d", &k);
		switch (k) {
			case 1:
				game();
				break;
			case 0:
				break;
			default :
				break;
		}

	} while (k != 0);
	printf("����");
	return 0;
}