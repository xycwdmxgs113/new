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
	dict.InsertR("string", "字符串");
	dict.InsertR("tree", "树");
	dict.InsertR("left", "左边、剩余");
	dict.InsertR("right", "右边");
	dict.InsertR("sort", "排序");
	string str;
	while (cin >> str)
	{
		key_val::SBTreeNode<string, string>* ret = dict.FindR(str);
		if (ret == nullptr)
		{
			cout << "单词拼写错误，词库中没有这个单词:" << str << endl;
		}
		else
		{
			cout << str << "中文翻译:" << ret->_val<< endl;
		}
	}
}

void test05()
{
	// 统计水果出现的次数
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
   "苹果", "香蕉", "苹果", "香蕉" };
	key_val::SBTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// 先查找水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		// 2、在，则查找到的节点中水果对应的次数++
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