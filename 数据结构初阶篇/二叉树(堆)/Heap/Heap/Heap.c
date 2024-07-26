#include"Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (!php->a) {
		printf("malloc fail");
		exit(1);
	}
	php->capaticy = 4;
	php->size = 0;
}

void HeapInitArray(HP* php, int* a, int n)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (!php->a) {
		printf("malloc fail");
		exit(1);
	}
	php->capaticy = n;
	php->size = 0;
	for (int  i = (n-2)/2; i >=0 ; --i)
	{
		AdjustDown(php->a, n, i);
	}
		
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//除了child这个位置，前面的数据构成堆
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] <a[child]) //父亲小于孩子
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

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if(php->size==php->capaticy)
	{
		HPDataType* tmp = realloc(php->a, sizeof(HPDataType) * (php->capaticy * 2));
		if (!tmp) {
			printf("realloc fail");
			exit(1);
		}
		php->a = tmp;
		php->capaticy *= 2;
		tmp = NULL;
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}

void HeapDestory(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capaticy = php->size = 0;
}

//左右子树都是大堆/小
void AdjustDown(HPDataType*a,int size, int parent)
{
	int child = parent * 2 + 1;//找孩子 
	while (child<size)
	{
		//找左右孩子中的老大
		if (child + 1 < size && a[child + 1] < a[child]) 
		{
			child++;
		}
		if (a[child] < a[parent])
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
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);// 向下查找

}

HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

//int HeapSize(HP* php)
//{
//	assert(php);
//	return php->size;
//}


