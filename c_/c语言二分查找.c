#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>

// ���ֲ���ֻ������������
int main() {
	int flag = 0; //����һ�����غ��� ���û�ҵ���Ϊ0
	int a[] = {1, 2, 3, 4, 5, 6, 6, 6, 6};
	int begin = 0; //��������ͷ�±�ֵ
	int end = sizeof(a) / sizeof(a[0]) - 1;//��������β�±�ֵ
	int find, middle;//�����м�ֵ��Ҫ���ҵ���ֵ
	printf("������Ҫ���ҵ���");
	scanf("%d", &find);
	while (begin <= end) {
		middle = (begin + end) / 2; //�м�ֵ
		if (find > a[middle]) {//��Ҫ�ҵ���ֵ���м�ֵ���ʱ��
			begin = middle + 1;	//�ٴζ�������ͷ�±�ֵ;
		} else if (find < a[middle]) {//��֮
			end = middle - 1;//�ٴζ�������β�±�ֵ;
		} else {
			printf("�ҵ����±�Ϊ%d\n", middle);
			flag = 1;
			int t = middle - 1;
			/*
			��������whileѭ���Ǳ�֤�ҵ�ֵ�� ȥ�������findֵ������������û����ֵͬ
			���������������±� Ȼ���ٴν���ѭ��ȥ���� ֱ��û��Ϊֹ
			*/
			while (t >= 0 && a[t] == find) { //t����0 ��t<=end ��Ϊ�˱�֤��ֵ�������±�Խ������
				printf("�ҵ����±�Ϊ%d\n", t--);
			}
			t = middle + 1;
			while (t <= end && a[t] == find) {
				printf("�ҵ����±�Ϊ%d\n", t++);
			}
			break;
		}
	}
	if (flag == 0) {
		printf("û�ҵ�");
	}

	return 0;
}
