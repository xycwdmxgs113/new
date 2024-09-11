#include<iostream>
#include<vector>
using namespace std;

//template<class Container>
//void print( Container &v)
//{
//	typename Container::iterator it = v.begin();
//	while (it!=v.end())
//	{
//		cout << (*it) << " ";
//		it++;
//	}
//	cout << endl;
//}

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	print(v);
//
//
//	return 0;
//}


template<class T>
bool Less(T x,T y)
{
	return x < y;
}

//函数模板特化

bool Less(int *x,int *y)
{
	return *x < *y;
}

template<class T>
bool Less(T* x, T* y)
{
	return *x < *y;
}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>
class Data<int ,double>
{
public:
	Data() { cout << "Data<int ,double>" << endl; }
};

//偏特化
template<class T>
class Data<T, double>
{
public:
	Data() { cout << "Data<T, double>" << endl; }
};

//偏特化
template<class T1,class T2>
class Data<T1*,T2*>
{
public:
	Data() { cout << "Data<T1*,T2*>" << endl; }
};

int main()
{
	Data<int, int> d1;
	Data<int, double> d2;
	Data<int*, double> d3;
	Data<int*, double*> d4;



	return 0;
}