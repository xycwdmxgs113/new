#include"Sort.h"

void PrintArray(int* a, int n)
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

// 插入排序 升序
void InsertSort(int* a, int n)
{
	int end;
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		end = i;
		temp = a[i + 1];
		while (end>=0)
		{
			if(a[end]>temp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap=n;
	int end;
	int temp;
	while (gap>1)
	{
		gap /=3+1;
		for (int i = 0; i < n-gap; i++)
		{
			end = i;
			temp = a[i + gap];
			while (end>=0)
			{
				if (a[end] > temp)
				{
					a[end + gap] = a[end];
					end-=gap;
				}
				else
				{
					break;
				}
			}
				a[end + gap] = temp;
		}
	}
}

// 选择排序
void SelectSort(int* a, int n)
{
	int begin=0 , end=n-1 ;
	int max, min;
	while (begin<end)
	{
		max = min = begin;
		for (int i = begin; i <=end; i++)
		{
			if (a[i] > a[max])
				max = i;
			if (a[i]<a[min])
			{
				min = i;
			}
		}
		if (begin==max)
		{
			max = min;
		}
		Swap(&a[begin], &a[min]);
		Swap(&a[end], &a[max]);
		begin++, end--;
	}
}

// 堆排序 升序建大堆
void AdjustDwon(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child+1<n&&a[child + 1] > a[child])
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


void HeapSort(int* a, int n)
{
	//先建堆,再排序
	for ( int i = (n-2)/2;  i >= 0;--i)//向下调整建堆
	{
		AdjustDwon(a, n, i);
	}

	int size = n;
	while (size--)
	{
		Swap(&a[0], &a[size]);
		AdjustDwon(a, size, 0);
	}
}

//三数选中
int MidNumber(int *a,int left,int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
		{
			return left;
		}
	}
	else //a[left] < a[mid]
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left > a[right]])
			return left;
		else
		{
			return right;
		}
	}
}

//hero排序
int QuickSort1(int* a, int left, int right)
{
	int mid = MidNumber(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = left;

	//先找右，再找左，左找大，右找小
	while (left<right)
	{
		if (left < right && a[right] >= a[key])
			--right;
		if (left < right && a[left] <= a[key])
			++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	return left;
}

//挖坑法
int QuickSort2(int* a, int left, int right)
{
	int mid = MidNumber(a, left, right);
	Swap(&a[left], &a[mid]);
	int hole = left;
	int key = a[left];

	while (left < right)
	{
		if (left < right && a[right] >= key)
			--right;
		a[hole] = a[right];
		hole = right;
		if (left < right && a[left] <= key)
			++left;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

//前后指针法
int QuickSort3(int* a, int left, int right)
{
	int mid = MidNumber(a, left, right);
	Swap(&a[left], &a[mid]);
	int prev, cur;
	prev = left;
	cur = left + 1;
	int key = left;
	//cur 找小
	while (cur<=right)
	{
		if (a[cur] < a[key] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		cur++;
	}
	Swap(&a[key], &a[prev]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if ((left + right + 1) < 10)
	{
		InsertSort(a + left, left + right + 1);
	}
	else {
		int key = QuickSort3(a, left, right);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
}