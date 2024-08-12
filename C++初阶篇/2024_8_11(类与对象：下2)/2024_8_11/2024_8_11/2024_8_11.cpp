#include<iostream>
using namespace std;
//class Date
//{
//
//	friend void fun(const Date& d);
//public:
//	Date(int year=2024,int month=8,int day=11)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{}
//
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void fun(const Date &d)
//{
//	cout << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//}
//
//int main()
//{
//	Date d;
//	fun(d);
//
//	return 0;
//}

//class A
//{
//	// 友元声明
//	friend class B;
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//public:
//	void func1(const A& aa)
//	{
//		cout << aa._a1 << "  ";
//		cout << _b1 << endl;
//	}
//	void func2(const A& aa)
//	{
//		cout << aa._a2 << "  ";
//		cout << _b2 << endl;
//	}
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//int main()
//{
//	A aa;
//	B bb;
//	bb.func1(aa);
//	bb.func2(aa);
//	return 0;
//}


//class A
//{
//public:
//	class B
//	{
//	public:
//		void fun(const A&a)
//		{
//			cout << a.h << " " << a.k;
//		};
//
//	private:
//		int b;
//	};
//
//private:
//	int static k;
//	int h=20;
//};
//int A::k = 0;
//
//int main()
//{
//	A a;
//	A::B b;
//	b.fun(a);
//	
//	return 0;
//}

//匿名对象
//class  A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~ A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		cout << "Sum_Solution" << endl;
//		return n;
//	}
//};
//
//int main()
//{
//	A aa(0);//有名对象
//	A(1);//无名对象
//
//	Solution s;
//	s.Sum_Solution(10);
//
//	
//	Solution().Sum_Solution(10);
//	const A& a = A(1); 
//	Solution().Sum_Solution(10);
//
//	return 0;
//}


//编译器的优化
class A
{
public:
	A(int a = 0)
		:_a1(a)
	{
		cout << "A(int a)" << endl;
	}

	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a1 = aa._a1;
		}
		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a1 = 1;
};


void F1(A aa)
{
}
//
//void F2(const A& aa)
//{}

A F3()
{
	A aa;
	return aa;
}

int main()	
{
	A a;
	a = F3();
	return 0;
}