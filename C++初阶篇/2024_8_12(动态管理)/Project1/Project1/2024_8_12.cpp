#include<iostream>
using namespace std;

//class  A
//{
//public:
//	 A(int a)
//		 :_a(a)
//	 {
//		 cout << "A():" << this << endl;
//	 }
//
//	 A(const A& d)
//		 :_a(d._a)
//	 {}
//
//	 ~A()
//	 {
//		 cout << "~A():" << this << endl;
//	 }
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = new A(1);
//
//	delete p1;
//
//
//	return 0;
//}

//int main()
//{
//	char* p1 = new char[1024 * 1024 * 1024];
//	cout << p1 << endl;
//
//}


class Stack
{
public:
	Stack(int capaticy = 4, int top = 0)
		:_arr(new int[capaticy])
		, _top(top)
		,_capaticy(capaticy)
	{
		cout << "Stack" << endl;
	}

	~Stack()
	{
		cout << "~Stack" << endl;
		delete[] _arr;
		_top = _capaticy = 0;
	}

private:
	int* _arr;
	int _top;
	int _capaticy;
};

int main()
{
	Stack* st = new Stack;
	delete st;

	return 0;
}
