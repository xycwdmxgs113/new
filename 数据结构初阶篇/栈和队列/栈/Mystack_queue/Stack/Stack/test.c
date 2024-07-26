#include"stack.h"


void test01() {
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	while (!STEmpty(&st))
	{
		printf("%d->", STTop(&st));
		STPop(&st);
	}

	 STDestroy(&st);
}

int main() {
	test01();




	return 0;
}
