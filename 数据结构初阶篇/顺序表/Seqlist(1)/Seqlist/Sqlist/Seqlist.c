#include"Seqlist.h"
void SLint(SL *ps) {
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SLDestroy(SL* ps) {
	if (ps->arr != NULL) {
		free(ps->arr);	
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
	 
}

void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		//申请空间
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType*tmp = (SLDataType)realloc(ps->arr, newCapacity * sizeof(SLDataType));//要申请多大空间
		if (!tmp) {
			perror("realloc error");
			exit(1);//直接退出程序不在运行
		}
		//空间申请成功
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}


void SLPrint(const SL* ps) {
	for (int i = 0;i < ps->size;i++) {
		printf("%d ", ps->arr[i]);
	}
	putchar('\n');
}

//尾插
void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	//判断空间是否够用
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;

}

void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size;i>0;i--) {
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;

}

void SLPopBack(SL* ps) {
	assert(ps);
	assert(ps->size);
	//顺序表不为空
	ps->arr[ps->size - 1] = -1;
	--ps->size;
}
void SLPopFront(SL* ps) {
	assert(ps);
	assert(ps->size);
	for (int i = 0;i < ps->size - 1;i++) {
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}

void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int  i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i <ps->size-1 ; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

int SLFind(SL* ps, SLDataType x) {
	SL* pcur = ps;
	for (int i = 0;i < ps->size;i++) {
		if (pcur->arr[i]==x)
		{
			return i;
		}
	}	
	return -1;
}