#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//ͨѶ¼����
/*
����n�����ѵ���Ϣ���������������ա��绰���룬����Ҫ���д����
��������Ӵ�С��˳���������ͨѶ¼����Ŀ��֤�����˵����վ�����ͬ��

�����ʽ:
�����һ�и���������n��<10����
���n�У�ÿ�а��ա����� ���� �绰���롱�ĸ�ʽ����һλ���ѵ���Ϣ
���С��������ǳ��Ȳ�����10��Ӣ����ĸ��ɵ��ַ���
�����ա���yyyymmdd��ʽ�����ڣ����绰���롱�ǲ�����17λ�����ּ�+��-��ɵ��ַ�����


*/
struct birthday {
	unsigned long int x;
};

struct Contacts {
	char name[11];
	struct birthday birth;
	char number[18];
};

int main() {
	int n;
	scanf("%d", &n);
	struct Contacts *number = (struct Contacts *)malloc(n * sizeof(struct Contacts));
	struct Contacts t;


	for (int i = 0; i < n; i++) {
		scanf("%s", number[i].name);
		scanf("%ld", &number[i].birth.x);
		scanf("%s", number[i].number);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (number[j].birth.x > number[j + 1].birth.x) {
				struct Contacts temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s %ld %s", number[i].name, number[i].birth.x, number[i].number);
		printf("\n");
	}
	return 0;
}