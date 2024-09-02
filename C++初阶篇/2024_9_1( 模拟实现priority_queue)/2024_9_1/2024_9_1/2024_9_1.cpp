#include"2024_9_1.h"
using namespace manbo;


void test01()
{
	int arr[] = { 1,2,3,4,5,6 };
	priority_queue<int> q1(arr, arr + 6);
	q1.push(7);

	while (!q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}

}

int main()
{
	test01();


	return 0;
}