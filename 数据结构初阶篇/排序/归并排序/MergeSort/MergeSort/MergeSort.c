#include"MergeSort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


//归并排序
//递归版本
void _MergeSort1(int *a, int begin,int end, int *temp)
{
	if (begin>=end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	_MergeSort1(a,begin,mid,temp);
	_MergeSort1(a,mid+1,end,temp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin1;
	while (begin1<=end1&&begin2<=end2)
	{
		if (a[begin1] < a[begin2])
			temp[index++] = a[begin1++];
		else
			temp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		temp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		temp[index++] = a[begin2++];
	}

	for (int i = begin; i <= end2; i++)
	{
		a[i] = temp[i];
	}

}

//循环版本	
void _MergeSort2(int* a,int n, int* temp)
{
	int gap = 1;
	while (gap<n)
	{
		for (int i = 0; i <n; i+=2*gap)
		{
			//左区间
			int begin1 = i, end1 =i+gap-1 ;

			//右区间
			int begin2 =i+gap, end2 =i+ 2*gap-1;
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2>=n)
			{
				end2 = n - 1;
			}
			printf("[%d,%d] [%d ,%d]\n", begin1, end1, begin2, end2);

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					temp[j++] = a[begin1++];
				}
				else
				{
					temp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				temp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				temp[j++] = a[begin2++];
			}
			memcpy(a + i, temp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
}

void MergeSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int* temp = (int*)malloc(sizeof(int) * n);
	_MergeSort2(a,n,  temp);
	free(temp);
}