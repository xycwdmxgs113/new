using namespace std;
#include"queue.h"

void test01()
{
	manbo::queue<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	cout << st.size() << endl;

	while (!st.empty())
	{
		cout << (st.front()) << " ";
		st.pop();
	}

}



int main()
{
	test01();
	return 0;
}