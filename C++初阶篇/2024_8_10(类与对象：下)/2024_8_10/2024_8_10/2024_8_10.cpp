#include<iostream>
using namespace std;

//
//class C
//{
//public:
//	C(int a=10)
//	:_a(a)
//	{}
//
//
//private:
//	int _a;
//
//};
//
//class A
//{
//public:
//	A(int n, int ret)
//		:_ret(ret),
//		_n(1)
//	{
//		cout << _ret << endl << _n << endl;
//	}
//
//
//private:
//	C c;
//	const int _n ;
//	int& _ret;
//};
//
//
//int main()
//{
//	A d(1, 1);
//	//隐式类型转换，由int转换成C类
//	C d1 = 2;
//	const C& d2 = 2;
//
//
//	return 0;
//}
class A
{
public:
	A() 
	{
		++_scout;
	};

	A(const A& a) 
	{
		++_scout;
	}

	~A()
	{
		--_scout;
	}

	static int GetCount()
	{
		return _scout;
	}
	int _a1 = 1;
	int _a2 = 1;
	static int _scout;
};

//类外进行声明	
int A::_scout=0;

A aa0;

void Func()
{
	static A aa2;
}


int main()
{
	cout << __LINE__ << ":" << A::GetCount() << endl;

	A aa1;
	Func();
	cout << __LINE__ << ":" << A::GetCount() << endl;
	
	Func();
	cout << __LINE__ << ":" << A::GetCount() << endl;
	
	return 0;
}
