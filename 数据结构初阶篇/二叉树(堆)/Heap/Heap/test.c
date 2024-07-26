#include"Heap.h"


//int main()
//{
//	HP hp;
//	HeapInit(&hp);
//	HeapPush(&hp, 4);
//	HeapPush(&hp, 18);
//	HeapPush(&hp, 42);
//	HeapPush(&hp, 12);
//	HeapPush(&hp, 2);
//	HeapPush(&hp, 3);
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//
// 	return	0;
//}

//������--�����--O��N*logN��
void HeapSort(int* a, int size)
{
	//����--���ϵ���O(N)
	for (int i = 1;i < size;i++) {
		AdjustUp(a, i);
	}
	//��������;O(N*logN)
	while (size--)
	{
		Swap(&a[0], &a[size]);
		AdjustDown(a, size, 0);
	} 
}

void PrintTopk(const char* file, int k)
{
	int* topk = (int*)malloc(sizeof(int) * k);
	assert(topk);
	FILE* fin = fopen(file, "r");

	if (!fin)
	{
		perror("fopen error");
		return;
	}
	//��ȡǰk������
	for (size_t i = 0; i < k; i++)
	{
		fscanf(fin, "%d", &topk[i]);
	}
	//1:����--��a��ǰk��Ԫ�ؽ�С��
	for (int i = (k-2)/2; i >=0; --i)
	{
		AdjustDown(topk, 10, i);
	}

	//2:��ʣ��n-k������������Ѷ�Ԫ�ؽ��������������滻
	int val = 0;
	int ret = fscanf(fin, "%d", &val);
	while (ret!=EOF)
	{
		if (val > topk[0]) {
			topk[0] = val;
			AdjustDown(topk, k,0);
		}
		ret = fscanf(fin, "%d", &val);
	}

}
void CreatDtat()
{
	//������
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");

	if (!fin)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int x = rand() % 10000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

//int main() {
//	int a[10] = { 2,1,5,7,6,8,0,9,4,3 };
//	HeapSort(a, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d",a[i]);
//	}
//	return 0;
//}

int main() {

	//CreatDtat();
	PrintTopk("data.txt",10);
}