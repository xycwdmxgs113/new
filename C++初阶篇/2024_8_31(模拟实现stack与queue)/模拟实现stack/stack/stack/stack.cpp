using namespace std;
#include"stack.h"

void test01()
{
	manbo::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	cout << st.size() << endl;

	while (!st.empty())
	{
		cout << (st.top()) << " ";
		st.pop();
	}
	cout << endl;


	manbo::stack<int, list<int>> lt;
	lt.push(1);
	lt.push(2);
	lt.push(3);
	lt.push(4);

	cout <<endl<< lt.size() << endl;

	while (!lt.empty())
	{
		cout << (lt.top()) << " ";
		lt.pop();
	}
}



int main()
{
	test01();
	return 0;
}