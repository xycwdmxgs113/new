#include"CountSort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//¼ÆÊýÅÅÐò
void CountSort(int* a, int n)
{
	int max=0, min=0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[max])
			max = i;
		if (a[i] < a[min])
			min = i;
	}
	int range = a[max] - a[min];
	int* CountA = (int*)malloc(sizeof(int) * (range + 1));
	if (!CountA)
	{
		perror("malloc fail");
		exit(1);
	}
	memset(CountA, 0, sizeof(int) * (range + 1));

	for (int i = 0; i <n; i++)
	{
		CountA[a[i]-a[min]]++;
	}

	int j = 0;

	for ( int i = 0; i < range; i++)
	{
		while (CountA[i]--)
		{
			a[j++] =i +a[ min];
		}
	}

}