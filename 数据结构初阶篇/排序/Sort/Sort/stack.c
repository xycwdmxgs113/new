#include"stack.h"
void STInit(ST* ps) {
	assert(ps);
	ps->data = (STDataType*)malloc(sizeof(STDataType)*4);
	ps->capaticy = 4;
	ps->top = 0;
}

bool STEmpty(ST* ps) {
	assert(ps);
	return ps->top == 0;
}

void STDestroy(ST* ps) {
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = ps->capaticy = 0;
}

void STPush(ST* ps, STDataType x) {
	assert(ps);
	if (ps->capaticy == ps->top) {
		STDataType* temp = (STDataType*)realloc(ps->data, (2 * ps->capaticy) * sizeof(STDataType));
		if (!temp) {
			perror("realloc fail");
			exit(1);
		}
		ps->data = temp;
		ps->capaticy *= 2;
	}
	ps->data[ps->top++] = x;
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

STDataType STTop(ST* ps) {
	assert(ps);
	return ps->data[ps->top-1];
}