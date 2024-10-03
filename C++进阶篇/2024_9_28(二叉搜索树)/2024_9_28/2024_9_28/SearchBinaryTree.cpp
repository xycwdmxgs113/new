#include"SearchBinaryTree.h"

void test01()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::SBTree<int>sb;
	for (auto &e:a )
	{
		sb.Insert(e);
	}

	sb.InOrder();
	
	sb.Erase(7);
	sb.InOrder();

	sb.Erase(14);
	sb.InOrder();

	sb.Erase(3);
	sb.InOrder();

	sb.Erase(8);
	sb.InOrder();
}

void test02()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::SBTree<int>sb;
	for (auto& e : a)
	{
		sb.InsertR(e);
	}

	sb.InOrder();

	sb.EraseR(7);
	sb.InOrder();

	sb.EraseR(14);
	sb.InOrder();

	sb.EraseR(3);
	sb.InOrder();

	sb.Erase(8);
	sb.InOrder();
}

void test03()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::SBTree<int>sb;
	for (auto& e : a)
	{
		sb.InsertR(e);
	}

	key::SBTree<int> sb1 = sb;
	sb1.InOrder();

	int b[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 ,123,435,346,6547,};
	key::SBTree<int> sb2;
	for (auto& e : b)
	{
		sb2.InsertR(e);
	}

	sb = sb2;
	sb.InOrder();
}

void test04()
{
	key_val::SBTree<string, string> dict;
	dict.InsertR("string", "�ַ���");
	dict.InsertR("tree", "��");
	dict.InsertR("left", "��ߡ�ʣ��");
	dict.InsertR("right", "�ұ�");
	dict.InsertR("sort", "����");
	string str;
	while (cin >> str)
	{
		key_val::SBTreeNode<string, string>* ret = dict.FindR(str);
		if (ret == nullptr)
		{
			cout << "����ƴд���󣬴ʿ���û���������:" << str << endl;
		}
		else
		{
			cout << str << "���ķ���:" << ret->_val<< endl;
		}
	}
}

void test05()
{
	// ͳ��ˮ�����ֵĴ���
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
   "ƻ��", "�㽶", "ƻ��", "�㽶" };
	key_val::SBTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// �Ȳ���ˮ���ڲ�����������
		// 1�����ڣ�˵��ˮ����һ�γ��֣������<ˮ��, 1>
		// 2���ڣ�����ҵ��Ľڵ���ˮ����Ӧ�Ĵ���++
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.FindR(str);
		if (ret == NULL)
		{
			countTree.InsertR(str, 1);
		}
		else
		{
			ret->_val++;
		}
	}
	countTree.InOrder();
}

int main()
{
	test05();

	return 0;
}