#include"Shellsort.h"

void printfArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	int temp;
	int end;
	for (int i = 1; i < n; i++)
	{
		end = i - 1;
		temp = a[i];
		while (end>=0)
		{
			if(temp<a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end+1] = temp;

	}

}

void  ShellSort(int* a, int n)
{
	int end;
	int temp;
	int gap = n;
	while (gap>1)
	{
		gap /= 2;
		for (int i = 0; i < n-gap; i++)
		{
			end = i;
			temp = a[i+gap];
			while (end >= 0)
			{
 				if (temp < a[end])
				{
					a[end +gap] = a[end];
					end-=gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
			printfArray(a, 11);
		}

	}
}