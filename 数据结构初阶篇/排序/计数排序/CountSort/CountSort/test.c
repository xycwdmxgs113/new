#include"CountSort.h"



int main()
{
	int a[] = { -9,-8,1,5,3,9,4,1,2,-5,6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	CountSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));





	return 0;
}