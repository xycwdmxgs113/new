#include"test.h"

using namespace manbo;

void test01()
{
	list<int> li;

	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	li.push_back(4);
	li.push_front(5);
	li.push_front(6);
	li.push_front(7);

	list<int> li1 = li;
	li1.clear();
	li1.push_back(1);
	li1.push_back(2);
	li1.push_back(3);
	li1.push_back(4);
	li = li1;

	for (auto& e : li)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << li.size();



}

void test02()
{
	list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	li.push_back(4);

	list<int>::reverse_iterator it = li.rbegin();
	while(it != li.rend())
	{
		cout << (*it) << " ";
		++it;
	}
	cout << endl;
}

void test03()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	vector<int> ::iterator it= v.begin();

	while (it!=v.end())
	{
		if((*it)%2==0)
		{
			it=v.erase(it);
		}
		else
		{
			it++;
		}
	}

	for (auto &e: v)
	{
		cout << e << " ";
	}

}

void test04()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);

	vector<int> v1 = v;
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v = v2;
	for (auto& e : v)
	{
		cout << e << " ";
	}
}

void test05()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	vector<int> ::reverse_iterator it = v.rbegin();
	while (it!=v.rend())
	{
		cout << (*it) << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	test05();

	return 0;
}