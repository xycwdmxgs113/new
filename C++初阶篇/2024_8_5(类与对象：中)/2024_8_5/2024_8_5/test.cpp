#include<iostream>
#include<assert.h>
using namespace std;

typedef int STDataType;
class Stack
{
public:
	// 成员函数

	//构造函数
	Stack(int capaticy=4)
	{
		std::cout << "Sack" << std::endl;
		_a = (STDataType*)malloc(sizeof(STDataType) * capaticy);
		if (!_a)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = capaticy;
		_top = 0;
	}


	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_top++] = x;
	}
	void Pop()
	{
		assert(_top > 0);
		--_top;
	}
	bool Empty()
	{
		return _top == 0;
	}
	int Top()
	{
		assert(_top > 0);
		return _a[_top - 1];
	}
	
	//拷贝构造函数
	Stack(const Stack& b )
	{
		STDataType* temp = (STDataType*)malloc(sizeof(STDataType) * b._capacity);
		if (!temp)
		{
			cout << "malloc fail" << endl;
			exit(1);
		}
		_a = temp;
		_capacity = b._capacity;
		_top = b._top;
		memcpy(_a, b._a, sizeof(STDataType) * b._capacity);
		temp = nullptr;
	}

	//析构函数
	~Stack()
	{
		std::cout << "~Sack" << std::endl;
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}

private:
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};

//int main()
//{
//	Stack s1;
//
//
//	return 0;
//}


class Data
{
public:
	//默认构造函数
	Data(int year=1,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	拷贝构造函数
	Data(const Data &  d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:

	//内置类型
	
	//C++11支持，这里不是初始化，而是给缺省值，用于给编译器默认的构造函数用
	int _year;
	int _month;
	int _day;

};

class Queue
{
private:
	Stack Push;
	Stack Pop;
};



//Stack& fun()
//{
//	Stack st;
//	return st;
//}
int main()
{
	Stack s1;
	Stack s2(s1);

	return 0;
}