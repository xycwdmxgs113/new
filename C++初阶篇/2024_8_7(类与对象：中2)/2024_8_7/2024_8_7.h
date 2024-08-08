#pragma once
#include<iostream>
#include<stdbool.h>
using namespace std;

/*
����Data��
Ҫ��:
1.ʵ���������ڱȽϵĺ��� >,<,>=,<=,==
2.ʵ���������ڵ������������������
3.ʵ�����ڵļӼ������ĺ���
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

	// ���캯��
	Data(int year = 2024, int month = 8, int day = 8);

	//��������
	Data(const Data& d);

	//��ֵ����
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


	//����+=����
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

	//��������������֮��Ĳ������
	int operator-(const Data& d); 
};





