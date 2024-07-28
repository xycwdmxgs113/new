#include"MergeSort.h"


int main()
{

	int a[] = { 9,8,7,6,5,5,4,3,1,2 ,8,4,3,4,3,5};
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a,sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

	return 0;
}