#include<iostream>
using namespace std;

//class Person 
//{
//public:
//	virtual void BuyTicket()const { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person
//{
//public:
//	 void BuyTicket()const  { cout << "买票-半价" << endl; }
//};
//
//void func(const Person &p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//
//	func(Student());
//	func(Student());
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////

//析构函数+virtual
//class Person
//{
//public:
//	 virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	 {
//		 cout << "~Student()" << endl; 
//		 delete[] _array;
//	 }
//
//private:
//	int *_array=new int[10];
//};
//
//
//int main()
//{
//	Person* p = new Person;
//	delete p;
//
//	p = new Student;
//	delete p;//delete分两个步骤，1.p->destructor() 调用析构函数 2.operator delete(p)
//
//	return 0;
//}


//class Base
//{
//public:
//	virtual void func()
//	{
//		cout << "func" << endl;
//	}
//private:
//	char _val;
//};
//
//int main()
//{ 
//	cout << sizeof(Base);
//	Base b;
//	return 0;
//}


//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	virtual void Fun1()
//	{
//		cout << "Person::Fun1()" << endl;
//	}
//	virtual void Fun2()
//	{
//		cout << "Person::Fun2()" << endl;
//	}
//protected:
//	int _a=0;
//};
//
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	virtual void Fun3()
//	{
//		cout << "Student::Fun3()" << endl;
//	}
//protected:
//	int _b=1;
//};
//
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//void test()
//{
//	Person p1;
//	Student st1;
//}

//int main()
//{
//	Person p;
//	Student st;
//
//	test();
//
//	p = st;
//	Person* p1 = &st;
//	Person& p2 = st;
//	return 0;
//}

//int main()
//{
//	Person p;
//	Student st;
//
//	int a;
//	printf("栈区:%p\n", &a);
//
//	static int b;
//	printf("静态区:%p\n", &b);
//
//	int* c = new int;
//	printf("堆区:%p\n", c);
//
//	const char* d = "hello world";
//	printf("常量区:%p\n", d);
//
//	printf("虚函数表p:%p\n", *((int*)&p));
//	printf("虚函数表st:%p\n", *((int*)&st));
//
//	return 0;
//}

//
//int main()
//{
//	Person p;
//	Student st;
//
//	int val = *((int*)&p);
//	PrintVFT((Func_PTR*)val);
//	cout << endl;
//	val = *((int*)&st);
//	PrintVFT((Func_PTR*)val);
//
//	return 0;
//}
//////////////////////////////////////////////////////////////////////

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private: int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void (*Func_PTR)();

void PrintVFT(Func_PTR table[])
{
	for (size_t i = 0; table[i] != nullptr; i++)
	{
		printf("[%d]:=%p->", i, table[i]);
		Func_PTR t = table[i];
		t();
		
	}
}

//int main()
//{
//	Derive d;
//
//	int val=*((int*)&d);
//
//	Base2* b2 = &d;
//	int val1 = *((int*)b2);
//
//	PrintVFT((Func_PTR*)val);
//	cout << endl;
//	PrintVFT((Func_PTR*)val1);
//
//
//
//	return 0;
//}

int main()
{
	Derive d;
	Base1& b1 = d;
	Base2& b2 = d;
	b1.func1();
	b2.func1();

	return 0;
}