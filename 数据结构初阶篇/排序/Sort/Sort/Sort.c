#include"Sort.h"
#include"stack.h"

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

// �������� ����
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

// ϣ������
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

// ѡ������
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

// ð������
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if (a[j]>a[j+1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}

}

// ������ ���򽨴��
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
	//�Ƚ���,������
	for ( int i = (n-2)/2;  i >= 0;--i)//���µ�������
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

//����ѡ��
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

// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	int mid = MidNumber(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	left++;
	while (left<=right)
	{
		//����С�����Ҵ�������������
		while (left <= right && a[right] > a[keyi])
			--right;
		while (left <= right && a[left] < a[keyi])
			++left;
		if (left<=right)
		{
			Swap(&a[left++], &a[right--]);
		}
	}
	Swap(&a[keyi], &a[right]);
	return right;
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = MidNumber(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = a[left];
	int hole = left;
	while (left<right)
	{
		while (left<right && a[right]>=keyi)
			--right;
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= keyi)
			++left;
			a[hole] = a[left];
			hole = left;
	}
	a[hole] = keyi;
	return hole;
}


// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int prev, cur;
	prev = left, cur = left + 1;
	int mid = MidNumber(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi =left;
	while (cur<=right)
	{
		//cur�ұ�keyiС��ֵ
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left>=right)
	{
		return;
	}
	if ((right-left+1)>10)
	{
		int key = PartSort3(a, left, right);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
	else
	{
		InsertSort(a, (right - left + 1));
	}

}

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st,left);
	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);
		int keyi = PartSort3(a, begin, end);
		
		//���������䣬����������
		if (keyi+1<end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}
		if (begin<keyi-1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}

}
