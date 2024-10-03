#include"SearchBinaryTree.h"

using namespace key;
void test01()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	SBT<int> sb;
	for(auto &e:a)
		sb.insert(e);

	sb.Inorder();
	
	sb.Erase(7);
	sb.Inorder();

	sb.Erase(14);
	sb.Inorder();

	sb.Erase(3);
	sb.Inorder();

	sb.Erase(8);
	sb.Inorder();
}

void test02()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	SBT<int> sb;
	for (auto& e : a)
		sb.InsertR(e);
	sb.Inorder();

	sb.EraseR(7);
	sb.Inorder();

	sb.EraseR(14);
	sb.Inorder();

	sb.EraseR(3);
	sb.Inorder();

	sb.EraseR(8);
	sb.Inorder();
}

void test03()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	int b[] = { 71,342,5436,67,67,435,312 };
	SBT<int> sb1;
	for (auto& e : a)
		sb1.InsertR(e);

	SBT<int> sb3;
	for (auto& e : b)
		sb3.InsertR(e);

	SBT<int> sb2 = sb1;
	sb2.Inorder();

	sb1 = sb3;
	sb1.Inorder();
}

void test04()
{
	key_val::SBT<string, string> sb;
	sb.InsertR("string", "×Ö·û´®");
	sb.InsertR("tree", "Ê÷");
	sb.InsertR("left", "×ó±ß¡¢Ê£Óà");
	sb.InsertR("right", "ÓÒ±ß");
	sb.InsertR("sort", "ÅÅÐò");

	string s;
	while (cin>>s)
	{
		auto ret = sb.FindR(s);
		if (ret)
		{
			cout << ret->_val << endl;
		}
		else
		{
			cout << "ÎÞÊÕÈë´Ëµ¥´Ê" << endl;
		}
	}
}

int main()
{
	test04();



	return 0;
}