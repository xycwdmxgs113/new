#pragma once
#include<iostream>
#include<stdbool.h>
using namespace std;

/*
完善Data类
要求:
1.实现两个日期比较的函数 >,<,>=,<=,==
2.实现两个日期的相减函数求相差的天数
3.实现日期的加减天数的函数
*/

class Data
{
private:
	int _year;
	int _month;
	int _day;
public:
	friend istream& operator>>(istream& in, Data &d);
	friend ostream& operator<<(ostream& out, const Data& d);

	// 构造函数
	Data(int year = 2024, int month = 8, int day = 8);

	//拷贝构造
	Data(const Data& d);

	//赋值拷贝
	Data& operator=(const Data& d);

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	bool operator<(const Data& d);

	bool operator<=(const Data& d);

	bool operator>(const Data& d);
	bool operator>=(const Data& d);

	bool operator==(const Data& d);
	bool operator!=(const Data& d);

	Data& operator++();
	Data operator++(int);

	Data& operator--();
	Data operator--(int);


	//日期+=天数
	int GetMonthDay(int year,int month)
	{
		static int arr[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month==2&&(((year%4==0&&year%100!=0)||(year%400==0))))
		{
			return 29;
		}
		else
		{
			return arr[month];
		}
	}

	Data& operator+=(int day);
	Data operator+(int day);

	Data& operator-=(int day);
	Data operator-(int day);

	//计算日期与日期之间的差的天数
	int operator-(const Data& d); 
};





