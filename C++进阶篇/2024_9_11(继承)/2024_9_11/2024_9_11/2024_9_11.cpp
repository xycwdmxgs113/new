#include<iostream>
#include<string>
using namespace std;
//
//class Person
//{
//public:
//	Person(const char * name="Peter",int age=18)
//		:_name(name)
//		,_age(age)
//	{
//		cout << "Person" << endl;
//	}
//
//	Person(const Person &a )
//		:_name(a._name)
//		,_age(a._age)
//	{}
//
//	Person&operator=(const Person & a)
//	{
//		_name=a._name;
//		_age=a._age;
//		return *this;
//	}
//	string _name;
//	int _age;
//};
//
//class Student:public Person
//{
//protected:
//	int _stuid;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	//赋值兼容(切割，切片)
//	p = s;//向上转换
//	 
//	Person &p1 = s;
//	p1._name = "菠萝吹雪";
//
//
//	return 0;
//}









//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person:fun" << endl;
//	}
//
//protected:
//	string name = "张三";
//	int num = 11;
//};
//
////隐藏/重定义:子类和父类有同名成员,子类的成员隐藏父类的成员
//class Student:public Person
//{
//public:
//	void print()
//	{
//		cout << "姓名:" << name<<endl;
//
//		//采用就近原则
//		cout << "年龄:" << num <<endl;
//		cout << "年龄:" << Person::num <<endl;
//	}
//
//	void fun()
//	{
//		cout << "Student:fun" << endl;
//	}
//
//protected:
//	int num = 99;
//};
//
//int main()
//{
//
//
//	Student s;
//	s.print();
//	s.fun();
//	s.Person::fun();
//	return 0;
//}









//class Person
//{
//public:
//	Person(const char* name = "Peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person&operator =(const Person& p)
//	{
//		cout << "Person&operator =(const Person& p)" << endl;
//		if(this!=&p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//protected:
//	string _name;
//};
//
//class Student:public Person
//{
//public:
//	Student(int id=1, const char* name = "林北")
//		:_id(0)
//		,Person(name)
//	{}
//
//	Student(const Student& s)
//		:_id(s._id)
//		, Person(s)
//	{}
//
//	Student&operator=(const  Student& s)
//	{
//		if(this!=&s)
//		{
//			_id = s._id;
//			Person:: operator=(s);
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		//由于后面多态的原因，析构函数的函数名被
//		//特殊处理，统一处理乘destructor
//
//		//Person::~Person(); 为了保证后定义的先析构
//		// 显示调用父类析构，无法保证先子后父的顺序
//		//所以子类的成员先析构，父类成员后析构
//	}
//
//protected:
//	int _id;
//};
//
//int main()
//{
//	Student s1;
//	Student s2(s1);
//	Student s3(2, "塞林木");
//	s1 = s3;
//	
//
//	return 0;
//}








//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name="111";
//};
//
//class Student :public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum;
//};
//
//void Display(const Person&p,const Student &s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}







//
//class Person
//{
//public:
//	string _name = "111";
//	int _age;
//};
//
//class Student:virtual public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher :virtual public Person
//{
//protected:
//	int _id;
//};
//
//class Ass:public Student,public Teacher
//{
//protected:
//	string _maj;
//};
//
//int main()
//{
//	Ass a;
//	a.Student::_age = 18;
//	a.Teacher::_age = 20;
//	a._age = 99;
//	return 0;
//}


class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C :virtual public A
{
public:
	int _c;
};

class D :public B, public C
{
public:
	int _d;
};

//int main()
//{
//	D d1;
//	d1.B::_a = 1;
//	d1.C::_a = 2;
//	d1._b = 3;
//	d1._c = 4;
//	d1._d = 5;
//
//	D d2;
//
//	return 0;
//}

int main()
{
	D d;
	d._a = 1;

	B b;
	b._a = 2;
	b._b = 3;

	B* ptr = &b;
	ptr->_a++;

	ptr = &d;
	ptr->_a++;

	return 0;
}







