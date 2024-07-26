#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//查找书籍 ：从键盘输入10本书的名称和定价并存入结构数组中，从中查找定价最高和最低的书的名称和定价并输出
struct book {
	char name[31];
	double price;
};

//定义两个个结构指针 分别指向books的结构数组 找出prince的最大值与最小值 分别输出
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

struct book *max(int n, struct book *pa) {//找出价格最大的书
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