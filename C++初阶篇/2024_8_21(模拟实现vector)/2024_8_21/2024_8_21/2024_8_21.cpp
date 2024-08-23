#include"2024_8_21.h"
using namespace cat;

void test01()
{
	cat::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);

	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v.Size(); i++)
	{
		v[i]++;
	}



	for (auto i : v)
	{
		cout << i << " ";
	}

}
void test02()
{
	cat::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	cat::vector<int>::iterator it = v.begin()+2;
	v.insert(it, 3);


	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test03()
{
	cat::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(5);
	for (auto i : v1)
	{
		cout << i << " ";
	}
	cout << endl;
	cat::vector<int> v2 = v1;

	for (auto i : v2)
	{
		cout << i << " ";
	}

}

void test04()
{
	cat::vector<int> v;
	v.resize(10, 1);
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	cat::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);

	v = v2;
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test05()
{
	vector<string> v;
	v.push_back("111111111111111111111111");
	v.push_back("222222222222222233333222");
	v.push_back("3333333333333333333333333");
	v.push_back("444444444444444444444444444");
	v.push_back("55555555555555555555555555");
	for (auto &i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	vector<string> v2;
	v2 = v;
}

void test06()
{
	string str = "hello world";
	vector<char>v3(str.begin(), str.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	int arr[] = { 16,2,77,29 };
	vector<int>v4(arr, arr + 4);
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>v5(10u,1);
}


int main()
{
	 test05();


	return 0;
}