#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//�����鼮 ���Ӽ�������10��������ƺͶ��۲�����ṹ�����У����в��Ҷ�����ߺ���͵�������ƺͶ��۲����
struct book {
	char name[31];
	double price;
};

//�����������ṹָ�� �ֱ�ָ��books�Ľṹ���� �ҳ�prince�����ֵ����Сֵ �ֱ����
struct book *max(int n, struct book *pa);
struct book *min(int n, struct book *pb);
void print(const struct book *pc, const struct book *pd);

int main(void) {
	int n;
	scanf("%d", &n);
	struct book books[n];
	for (int i = 0; i < n; i++) {
		getchar();
		gets(books[i].name);
		scanf("%lf", &books[i].price);
	}
	struct book *pa = max(n, books);
	struct book *pb = min(n, books);
	print(pa, pb);
	return 0;
}

struct book *max(int n, struct book *pa) {//�ҳ��۸�������
	struct book *p = pa;
	for (int i = 0; i < n; i++) {
		if (p->price < pa[i].price) {
			p = &pa[i];
		}
	}
	return p;
}

struct book *min(int n, struct book *pa) {
	struct book *p = pa;
	for (int i = 0; i < n; i++) {
		if (p->price > pa[i].price) {
			p = &pa[i];
		}
	}
	return p;
}

void print(const struct book *pc, const struct book *pd) {
	printf("%.2lf,%s\n", pc->price, pc->name);
	printf("%.2lf,%s\n", pd->price, pd->name);

}