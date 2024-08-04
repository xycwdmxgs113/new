#include"Fun.h"
using namespace std;

//int main()
//{
//	Stack st;
//	st.STInit();
//	st.STPush(1);
//	st.STPush(2);
//	st.STPush(3);
//	st.STPush(4);
//	st.Destroy();
//	return 0;
//}

//class A
//{
//public:
//	void printA()
//	{
//		cout << _a << endl;
//	}
////private:
//	char _a;
//
//};
//
//int main()
//{
//	A a1;
//	A a2;
//	A a3;
//	cout << sizeof(a1) << endl;
//	cout << sizeof(A) << endl;
//	
//	a1._a = 'c';
//	a1.printA();
//}

class A1{};

class A2
{
public:
	void printA(){}
};

int main()
{
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;

}


////class Data
////{
////public:
////	void Init(int year,int month,int data)
////	{
////		_year = year;
////		_month = month;
////		_data = data;
////	}
////	
////	void Print()
////	{
////		cout <<  _year << "-" << _month << "-" << _data << endl;
////	}
////
////private:
////	int _year;
////	int _month;
////	int _data;
////};
////
////int main()
////{
////	Data d1, d2;
////	d1.Init(2022, 11, 11);
////	d2.Init(2022, 12, 12);
////	d1.Print();
////	d2.Print();
////	
////
////}
//
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print(); 
//
//}

