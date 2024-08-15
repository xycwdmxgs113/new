#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

//template<typename T>
//void Print( const T&x,const  T&y)
//{
//	cout << x << "  " << y << endl;
//}
//template<typename T1>
//void Print(const T1&x,const T1&y)
//{
//	cout << x << " " << y << endl;
//}
//template<class T>
//class Stack
//{
//public:
//	Stack(int capaticy = 4);
//
//	~Stack();
//
//	//功能待完善.....
//private:
//	T* _arr;
//	int _top=0;
//	int _capaticy;
//};
//
//template<class T>
// Stack<T>::Stack(int capacity)
//{
//	_arr(new T[capacity]);
//	_capaticy(capacity);
//}
//
// template<class T>
// Stack<T>::~Stack()
//{
//	delete[] _arr;
//	_top = capacity = 0;
//}


//int main()
//{
//	string s1("Hello world");
//
//
//	string::iterator it = s1.begin();
//	while (it!=s1.end())
//	{
//		cout << *it;
//		it++;
//	}
//
//	cout << endl;
//
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	vector<int>::iterator vit = v.begin();
//	while (vit!=v.end())
//	{
//		cout << *vit;
//		vit++;
//	}
//
//	cout << endl;
//
//	
//	return 0;
//}


int main()
{
	string s1 = "https://www.bilibili.com/video/BV1fW421X7gD/?spm_id_from=333.1007.tianma.6-1-19.click";
	//解析网址，分协议   域名  资源
	size_t pos1 = s1.find("://");
	if (pos1==string::npos)
	{
		cout << "No Find";
		exit(1);
	}
	string agreement = s1.substr(0, pos1);
	cout << "协议:" << agreement << endl;

	size_t pos2 = s1.find('/', pos1 + 3);
	if (pos2 == string::npos)
	{
		cout << "No Find";
		exit(1);
	}

	string domain = s1.substr(pos1 + 3, pos2 - (pos1 + 3));
	cout << "域名:" << domain << endl;

	string resource = s1.substr(pos2 + 1);
	cout << "资源:" << resource << endl;
}

//int main()
//{
//    string s1;
//    getline(cin, s1);
//    size_t pos = s1.rfind(' ' );
//    if (pos != string::npos)
//    {
//        int size = s1.size() - (pos + 1);
//        return size;
//    }
//    else
//    {
//        return s1.size();
//    }
//}
