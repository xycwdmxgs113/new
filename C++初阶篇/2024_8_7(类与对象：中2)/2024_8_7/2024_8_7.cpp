#include"2024_8_7.h"
// 构造函数
Data ::Data(int year, int month, int day)
{
	if (month < 0 || month>12 || day >Data::GetMonthDay(year,month) || day < 1)
	{
		cout << "非法日期" << endl;
		exit(1);
	}
	_year = year;
	_month = month;
	_day = day;
}

//拷贝构造
Data::Data(const Data& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//赋值拷贝
Data& Data::operator=(const Data& d)
{
	if (this!= &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

bool Data::operator<(const Data& d)
{
	if (_year < d._year)
		return true;
	else if (_year == d._year && _month < d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day < d._day)
		return true;
	
	return false;
}

bool Data::operator==(const Data& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Data::operator<=(const Data& d)
{
	return  *this < d || *this == d;
}

bool Data::operator>(const Data& d)
{
	return !(*this <= d);
}

bool Data::operator>=(const Data& d)
{
	return *this == d|| *this > d ;
}

bool  Data ::operator!=(const Data& d)
{
	return !(*this == d);
}

Data& Data::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day>GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year,_month);
		_month++;
		if (_month==13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Data Data::operator+(int day)
{
	Data temp(*this);
	temp += day;
	return temp;
}

//默认前置++ 返回++后的值
Data& Data::operator++()
{
	(*this)+=1;
	return *this;
}

//默认后置++,返回++前的值
Data Data::operator++(int)
{
	//拷贝构造
	Data temp(*this);
	(*this) += 1;
	return temp;
}

Data& Data::operator--()
{
	*this -= 1;
	return *this;
}

Data Data::operator--(int)
{
	Data temp = *this;
	*this -= 1;
	return temp;
}

Data& Data:: operator-=(int day)
{
	if (day<0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day<=0)
	{		
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}


Data Data:: operator-(int day)
{
	Data temp = *this;
	temp -= day;
	return temp;
}

//d1-d2
int Data::operator-(const Data& d)
{
	Data max = *this;
	Data min = d;
	int flag = 1;
	if (max<min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int cnt = 0;
	while (min!=max)
	{
		++min;
		cnt++;
	}

	return cnt*flag;
}

ostream& operator<<(ostream& out, const Data& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Data &d)
{
	int year, month, day;
	in >> year >> month >> day;
	if (month<0||month>12||day>d.GetMonthDay(year,month)|| day <1)
	{
		cout << "非法日期" << endl;
		exit(1);
	}
	d._year = year, d._month = month, d._day = day;
	return in;
}