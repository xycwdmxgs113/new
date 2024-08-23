#include"2024_8_23.h"

void test01()
{
	fj::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.resize(10,7);

	for (auto i :v)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test02()
{
	fj::vector<string> v;
	v.push_back("11111111");
	v.push_back("22222222");
	v.push_back("33333333");
	v.push_back("44444444");
	v.push_back("55555555");
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	fj::vector<string> v1 = v;
	for (auto i : v1)
	{
		cout << i << " ";
	}
	cout << endl;

	fj::vector<string> v2;
	v2.push_back("aaaaa");
	for (auto i : v2)
	{
		cout << i << " ";
	}
	cout << endl;
	v2 = v1;
	for (auto i : v2)
	{
		cout << i << " ";
	}
	cout << endl;
}



void test03()
{
	fj::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);


	fj::vector<int>::iterator it = v.end()-2;
	v.insert(it, 100);
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	fj::vector<int>::iterator it1 = v.begin();
	v.erase(it1);
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	test03();



	return 0;
}

