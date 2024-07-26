#include"QuickSort.h"

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

void BubbleSort(int* a, int n)
{

	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i < n-j; i++)
		{
			if (a[i] < a[i - 1])
			{
				Swap(&a[i], &a[i - 1]);
			}
		}
	}
}

int  GiteMid(int* a, int left, int right)//三数取中
{
	int mid = (left + right) / 2;
	if (a[left]<a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else //a[left]>a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])  //left>mid   right>mid
			return left;
		else
		{
			return right;
		}
	}
}

//hero方法
int QuickSort1(int* a, int left, int right)
{

	int begin = left;
	int end = right;
	int mid = GiteMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = left;

	while (left < right)
	{
		//先走右，再走左  ,左找大，右找小
		while (left < right && a[right] >= a[key])
			--right;
		while (left < right && a[left] <= a[key])
			++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	return left;
}

//挖坑法
int QuickSort2(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int mid = GiteMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//先走右，再走左  ,左找大，右找小
		while (left < right && a[right] >= key)
			--right;
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
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

	int mid = GiteMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int keyi = left;
	int prev=left, cur=left+1;
	while (cur<=right)//cur找小
	{
		if(a[cur]<a[keyi]&&++prev!=cur)
			Swap(&a[cur], &a[prev]);
			++cur;
	}
	Swap(&a[keyi],& a[prev]);
	return prev;
}


void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if ((left + right - 1) < 10)
	{
		InsertSort(a + left, left + right + 1);
	}
	else {
		int keyi = QuickSort2(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}

// 插入排序 升序
void InsertSort(int* a, int n)
{
	int end;
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		end = i;
		temp = a[i + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
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