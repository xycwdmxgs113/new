#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
using std::cout;
using std::endl;

//int main()
//{
	//int a = 10;
	//int c = 20;
	//int& b = a;
	//cout << "b的值为" << b << endl;
	//b = c;
	//cout << "a的值为" << a << " " << "b的值为" << b << " " << "c的值为" << c << endl;
	//cout << "a的地址为" << &a << endl << "b的地址为" << &b << endl << "c的地址为" << &c << endl;
	//cout << "a=" << a << endl << "b=" << b << endl << "c=" << c << endl;
	//cout << "a=" << &a << endl << "b=" << &b << endl << "c=" << &c << endl;

//	return 0;
//}

//
//void Swap(int &x,int &y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//
//}
//
//struct A
//{
//	int a[10000];
//};
//
//
//
//void fun1(A a){}
//
//void fun2(A &a){}
//
//int main()
//{
//	A a;
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; i++)
//	{
//		fun1(a);
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; i++)
//	{
//		fun2(a);
//	}
//	size_t end2 = clock();
//
//	cout << "func1 Time:" << end1 - begin1 << endl;
//	cout << "func2 Time:" << end2 - begin2 << endl;
//
//	return 0;
//}

//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void STInit(ST&st,int n=4)
//{
//	st.a = (STDataType*)malloc(sizeof(int) * n);
//	st.top = 0;
//	st.capacity = n;
//}
//
//void STPush(ST&st,STDataType x)
//{
//	assert(&st);
//	if ((st.capacity==st.top))
//	{
//		printf("扩容\n");
//		int newcapacity = st.capacity == 0 ? 4 : st.capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(st.a, newcapacity *sizeof(STDataType));
//		assert(tmp);
//		st.a = tmp;
//		st.capacity *= newcapacity;
//	}
//	st.a[st.top] = x;
//	st.top++;
//}
//
//int& STTop(ST&st)
//{
//	assert(st.top > 0);
//	return st.a[st.top-1];
//}
//
//
//int main()
//{
//	ST st;
//	STInit(st);
//	STPush(st, 1);
//	STPush(st, 2);
//	STPush(st, 3);
//	cout << STTop(st) << endl;
//	STTop(st)++;
//	cout << STTop(st) << endl;
//}

//int N1(int n)
//{
//	int k = n;
//	return k;
//}
//
//int &N2(int n)
//{
//	int k = n;
//	return k;
//}
//
//int main()
//{
//	int ret1 = N1(10);
//
//	int ret2 = N2(10);
//
//	int &ret3 = N2(10);
//
//	cout << ret1 << " " << ret2 << " "<<ret3 << endl;
//	cout << ret1 << " " << ret2 << " "<<ret3 << endl;
//
//	return 0;
//}

int main()
{

	const int a = 10;
	int& b = a;

	return 0;
}

//inline int Add(int x,int y)
//{
//	int ret = x + y;
//	return ret;
//}


//#define Add1(a,b) (a+b)
//#define Add2(a,b) a+b
//#define Add3(a,b) ((a)+(b))
//
//int main()
//{
//	Add1(1 * 3, 2);
//	Add2(1 * 3, 2);
//	Add3(1 * 3, 2);
//
//	return 0;
//}

//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(nullptr);
//
//	return 0;
//}
