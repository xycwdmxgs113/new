#include"2024_8_26.h"



//void test01()
//{
//	list<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e:v)
//	{
//		cout << e<<" ";
//	}
//	cout << endl;
//
//	auto e = v.begin();
//	for (size_t i = 0; i < 2; i++)
//	{
//		++e;
//	}
//
//	v.insert(e, 100);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	e = find(v.begin(), v.end(), 100);
//	v.insert(e, 200);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//}
//
//void test02()
//{
//	list<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	
//	sort(v.begin(), v.end());
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	v.sort();
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}

using namespace std;

void test01()
{
	mabo::list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	li.push_back(4);

	mabo::list<int>::iterator it = li.begin();
	while (it!=li.end())
	{
		cout << (*it) << " ";
		++it;
	}
	cout << endl;


	for (auto e:li)
	{
		cout << e << " ";
	}
	cout << endl;
}
using namespace mabo;
void test02()
{
	
	list<A> li;
	li.push_back(A(1, 2));
	li.push_back(A(3, 4));
	mabo::list<A>::iterator it = li.begin();
	while (it != li.end())
	{
		cout <<it->_a1 << " "<< it->_a2<<endl;
		++it;
	}
	cout << endl;

}

void test03()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(5);
	lt.push_front(6);
	lt.push_front(7);
	lt.push_front(8);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.clear();
	list<int> lt1;
	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt = lt1;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}



void test04()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> lt1 = lt;
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test05()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int> lt1;
	lt1.push_back(5);
	lt1.push_back(6);
	lt1.push_back(7);
	lt1.push_back(8);

	lt = lt1;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test06()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::reverse_iterator it = lt.rbegin();
	while (it != lt.rend())
	{
		cout << *it << " ";
		++it;
	}


}

int main()
{
	test06();



	return 0;
}