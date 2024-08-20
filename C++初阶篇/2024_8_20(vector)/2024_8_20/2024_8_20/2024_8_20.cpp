#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator vi = v.begin();
	while (vi!=v.end())
	{
		cout << (*vi);
		vi++;
	}
	cout << endl;

	for (auto e:v)
	{
		cout << e;
	}
	cout << endl;
}

void test02()
{
	vector<int> v1(10, 1);
	vector<string> v2(10, "+++");
	for (auto a:v1)
	{
		cout << a<<" ";
	}
	cout << endl;

	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	string str = "hello world";
	vector<char>v3(str.begin(), str.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	int arr[] = { 16,2,77,29 };
	vector<int>v4(arr, arr + 4);
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	//Ä¬ÈÏÉýÐò
	sort(v4.begin(), v4.end());
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	//greater ½µÐò

	sort(v4.begin(), v4.end(),greater<int>());
	for (auto e : v4)
	{
		cout << e << " ";
	}

}

void test03()
{
	vector<int> v;
	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;


}

void test04()
{
	int arr[] = { 16,2,77,29 };
	vector<int>v1(arr, arr + 4);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	


	v1.insert(v1.begin(), 999);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v1.begin(), v1.end(), 2);
	if (pos!=v1.end())
	{
		v1.erase(pos);
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test05()
{
	int n;
	cin >> n;
	vector<vector<int>> vv;
	vv.resize(n);

	for (size_t i = 0; i < vv.size(); i++)
	{
		vv[i].resize(i + 1,0);
		vv[i][0] = vv[i][i] = 1;
	}
	 
	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			if(vv[i][j]==0)
			{
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
		}
	}

	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t k = 0; k < (n - i - 1); k++)
		{
			cout << " ";
		}
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			cout<< vv[i][j] << "  ";
		}
		cout << endl;
	}

}

int main()
{
	string s = "hello world";
	string::reverse_iterator it = s.rbegin();
	while (it!=s.rend())
	{
		cout << (*it) << " ";
		it++;
	}


	return 0;
}