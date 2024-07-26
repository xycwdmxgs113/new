#include"Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = (HeapDataType*)malloc(sizeof(HeapDataType) * 4);
	assert(php->a);
	php->capaticy = 4;
	php->size = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);
	if (php->a)
	{
		free(php->a);
	}
	php->capaticy = php->size = 0;
}

void Swap(HeapDataType*x,HeapDataType*y)
{
	HeapDataType temp = *x;
	*x = *y;
	*y = temp;
}

void AdjustUp(HeapDataType*a,int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if(a[parent]>a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//小堆
void HeapPush(HP* php, HeapDataType x)
{
	assert(php);
	if(php->size==php->capaticy)
	{
		HeapDataType* temp = (HeapDataType*)realloc(php->a, sizeof(HeapDataType) * (php->capaticy * 2));
		assert(temp);
		php->a = temp;
		php->capaticy *= 2;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size-1);
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

void AdjustDown(HeapDataType*a,int parent,int size)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child<size)
	{
		//找左右孩子中最小的
		if (child+1<size&&a[child + 1] < a[child])
			++child;
		if (a[child]<a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;
	AdjustDown(php->a, 0, php->size);
}

HeapDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}