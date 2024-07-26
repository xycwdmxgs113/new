#include"Heap.h"

//打印数组
void PrintfArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//直接选择排序
void SelectSort(int* a, int n)
{
	int left=0;
	int right=n-1;
	int max=0, min=0;
	while (left<right)
	{
		max = left, min = left;
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i]>a[max])
			{
				max = i;
			}
		}
		if (left == max)
		{
			max = min;
		}
		Swap(&a[left], &a[min]);
		Swap(&a[right], &a[max]);
		left++;right--;
	}
}

void AdjustDown(int *a,int parent,int n)
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		if (a[child]>a[parent])
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

//堆排序
void HeapSort(int* a, int n)
{
	//向下调整建堆;
	for (int i = (n-2)/2; i >= 0; --i)
	{
		AdjustDown(a, i, n);
	}
	//堆排序
	while (n--)
	{
		Swap(&a[0], &a[n]);
		AdjustDown(a, 0, n);
	}
}