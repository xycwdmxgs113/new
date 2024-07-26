#include"Queue.h"

void test01() {
	Queue q;
	QInit(&q);
	QPush(&q, 1);
	QPush(&q, 2);
	QPush(&q, 3);
	QPush(&q, 4);
	QPush(&q, 5);
	while (!QEmpty(&q))
	{
		printf("%d->", QFront(&q));
		QPop(&q);
	}
	printf("\n");
	QDestroy(&q);
}

 
int main() {
	test01();


	return 0;
}