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
//	//��ֵ����(�и��Ƭ)
//	p = s;//����ת��
//	 
//	Person &p1 = s;
//	p1._name = "���ܴ�ѩ";
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
//	string name = "����";
//	int num = 11;
//};
//
////����/�ض���:����͸�����ͬ����Ա,����ĳ�Ա���ظ���ĳ�Ա
//class Student:public Person
//{
//public:
//	void print()
//	{
//		cout << "����:" << name<<endl;
//
//		//���þͽ�ԭ��
//		cout << "����:" << num <<endl;
//		cout << "����:" << Person::num <<endl;
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
//	Student(int id=1, const char* name = "�ֱ�")
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
//		//���ں����̬��ԭ�����������ĺ�������
//		//���⴦��ͳһ�����destructor
//
//		//Person::~Person(); Ϊ�˱�֤�����������
//		// ��ʾ���ø����������޷���֤���Ӻ󸸵�˳��
//		//��������ĳ�Ա�������������Ա������
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
//	Student s3(2, "����ľ");
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







