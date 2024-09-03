#pragma once
#include<iostream>
using namespace std;


void swap(int &x,int& y)
{
	int t = x;
	x = y;
	y = t;
}

//²åÈëÅÅĞò
void insert_sort(int *arr,int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i;
		while (end-1>=0)
		{
			if(arr[end-1]>arr[end])
			{
				swap(arr[end - 1], arr[end]);
			}
			end--;
		}
	}		
}

void bubble_sort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <n-i-1 ; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void select_sort(int *arr,int n)
{
	int begin = 0;
	int end = n;
	while (begin<end)
	{
		int max, min;
		max = min = begin;
		for (int i = begin; i < end; i++)
		{
			if (arr[i] > arr[max])
				max = i;
			if (arr[i] < arr[min])
				min = i;
		}
		if (begin==max)
		{
			swap(arr[begin], arr[end-1]);
			swap(arr[begin], arr[min]);
		}
		else
		{
			swap(arr[begin], arr[min]);
			swap(arr[end-1], arr[max]);
		}

		begin++, end--;

	}

}

void AdjustDown(int *arr,int parent,int n)
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child+1<n&&arr[child+1]>arr[child])
		{
			child++;
		}

		if (arr[parent]<arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void Heap_sort(int* arr, int n)
{
	for (int i =(n-2/2); i >=0; i--)
	{
		AdjustDown(arr,i,n);
	}

	while (n>0)
	{
		swap(arr[0], arr[n-1]);
		n--;
		AdjustDown(arr, 0, n);
	}
}



int hoare(int *arr,int begin,int end)
{

	int key = begin;
	while (begin<end)
	{
		while (begin<end && arr[end]>arr[key])
			end--;
		while (begin < end && arr[begin] < arr[key])
			begin++;
		if (begin<end)
		{
			swap(arr[begin], arr[end]);
		}
	}
	swap(arr[key], arr[begin]);
	return begin;

}

int hole(int* arr, int begin, int end)
{
	int key = arr[begin];
	int hole = begin;
	while (begin < end)
	{
		while (begin<end && arr[end]>key)
			end--;
		arr[hole] = arr[end];
		hole = end;

		while (begin < end && arr[begin] < key)
			begin++;
		arr[hole] = arr[begin];
		hole = begin;
	}
	arr[hole] = key;
	return hole;

}

int dpointer(int* arr, int begin, int end)
{
	int prev = begin;
	int next = begin + 1;
	int key = begin;
	while (next<=end)
	{
		if(arr[next]<arr[key] && ++prev != next)
		{
			swap(arr[prev], arr[next]);
		}
		++next;
	}
	swap(arr[key], arr[prev]);
	return prev;
}

void quck_sort(int* arr, int begin,int end)
{
	if (begin >= end)
	{
		return;
	}
	int key = dpointer(arr, begin, end);
	quck_sort(arr, begin, key - 1);
	quck_sort(arr, key+1, end);
}

void merge(int *arr,int begin,int end,int *temp)
{
	if (begin>=end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	merge(arr, begin, mid, temp);
	merge(arr, mid+1,end, temp);
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	
	int i = begin;
	while (begin1<=end1&&begin2<=end2)
	{
		if(arr[begin1]<arr[begin2])
		{
			temp[i++] = arr[begin1++];
		}
		else
		{
			temp[i++] = arr[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		temp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = arr[begin2++];
	}
	memcpy(arr+begin, temp+begin,sizeof(int)*(end2-begin+1));
}

void merge_sort(int* arr, int n)
{
	int* temp = new int[n];
	merge(arr, 0, n - 1, temp);

}




