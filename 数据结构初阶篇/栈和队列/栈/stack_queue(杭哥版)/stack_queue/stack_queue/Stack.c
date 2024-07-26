#include"Stack.h"

void STInit(ST* ps) {
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (!ps->a) {
		perror("malloc fail");
		exit(1);
	}
	ps->capaticy = 4;
	//ps->top = -1;//top为栈顶元素
	ps->top = 0;//此时top为栈顶元素的下一个位置;
}

void STDestroy(ST* ps) {
	assert(ps);
	if (ps->a) {
		free(ps->a);
		ps->a = NULL;
	}
	ps->capaticy = ps->top = 0;
}

void STPush(ST* ps, STDataType x) {
	assert(ps);
	if (ps->capaticy == ps->top) {

		STDataType* temp = (STDataType*)realloc(ps->a, (ps->capaticy * 2) * sizeof(STDataType));
		if (!temp) {
			perror("ralloc fail");
			exit(1);
		}
		ps->a = temp;
		ps->capaticy *= 2;
	}
	ps->a[ps->top++] = x;
	
}

void STPop(ST* ps) {
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}

int  STSize(ST* ps) {
	assert(ps);
	return ps->top;
}

bool STEmpty(ST* ps) {
	assert(ps);
	return ps->top== 0;
}

STDataType STTop(ST* ps) {
	assert(ps);
	assert(!STEmpty(ps));
	return ps->a[ps->top - 1];
}