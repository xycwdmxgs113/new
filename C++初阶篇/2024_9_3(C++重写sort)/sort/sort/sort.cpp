#include"sort.h"


void test01()
{
	int arr[] = { 5,3,4,7,1,8,9,6,2 };
	insert_sort(arr, sizeof(arr)/sizeof(arr[0]));

	for (auto &e:arr )
	{
		cout << e << " ";
	}

}

void test02()
{
	int arr[] = { 5,3,4,7,1,8,9,6,2 };
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

	for (auto& e : arr)
	{
		cout << e << " ";
	}

}

void test03()
{
	int arr[] = { 5,3,4,7,1,8,9,6,2 };
	select_sort(arr, sizeof(arr) / sizeof(arr[0]));

	for (auto& e : arr)
	{
		cout << e << " ";
	}
}

void test04()
{
	int arr[] = { 5,3,4,7,1,8,9,6,2 };
	Heap_sort(arr, sizeof(arr) / sizeof(arr[0]));

	for (auto& e : arr)
	{
		cout << e << " ";
	}
}

void test05()
{
	int arr[] = { 5,3,4,7,1,8,9,6,2 };
	quck_sort(arr, 0,sizeof(arr) / sizeof(arr[0])-1);

	for (auto& e : arr)
	{
		cout << e << " ";
	}
}

void test06()
{
	int arr[] = { 5,3,4,7,1,8,9,6,2 };
	merge_sort(arr, sizeof(arr) / sizeof(arr[0]));

	for (auto& e : arr)
	{
		cout << e << " ";
	}
}


int main()
{
	test06();

	return 0;
}