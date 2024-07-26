#include"Heap.h"





//int main()
//{
//	HP hp;
//	HeapInit(&hp);
//	HeapPush(&hp, 21);
//	HeapPush(&hp, 18);
//	HeapPush(&hp, 1);
//	HeapPush(&hp, 32);
//	HeapPush(&hp, 9);
//	
//
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	HeapDestroy(&hp);
//
//	return 0;
//}

//void HeapSort(int* a, int size)
//{
//	//向下调整--建堆
//	for (int i =(size-1)/2 ; i>=0 ; --i)
//	{
//		AdjustDown(a, i, size);
//	}
//
//	int sz = size;
//	while (sz--)
//	{
//		Swap(&a[0], &a[sz]);
//		AdjustDown(a, 0, sz);
//	}
//
//}
//
//int main() {
//	int a[10] = { 2,1,5,7,6,8,0,9,4,3 };
//	HeapSort(a, 10);
//
//	return 0;
//}

//关于topk问题

void CreatNode()
{
	srand(time(0));
	int n = 10000;
	FILE* ptr = fopen("data.txt", "w");
	assert(ptr);
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 10000;
		fprintf(ptr, "%d\n", x);
	}
	fclose(ptr);
}

void PrintTopK(FILE*ptr,int k)
{
	int* topk = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
	{
		fscanf(ptr, "%d", &topk[i]);
	}

	//先建前Topk个小堆
	for (int i = (k-2)/2; i >=0 ; --i)
	{
		AdjustDown(topk, i, k);
	}
 	int val = 0;
	int ret = fscanf(ptr, "%d", &val);
	while (ret!=EOF)
	{
		//如果比堆顶大就代替堆顶数据进堆
		if(val>topk[0])
		{
			topk[0] = val;
			AdjustDown(topk, 0, k);
		}
		ret = fscanf(ptr, "%d", &val);
	}
	
	for (int i = 0; i <k ; i++)
	{
		printf("%d ", topk[i]);
	}
}

int main()
{
	//CreatNode();
	FILE* ptr = fopen("data.txt", "r");
	PrintTopK(ptr, 10);
	fclose(ptr);

}