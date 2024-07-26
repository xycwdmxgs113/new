#include"Tree.h"

void test01()
{
	BTDataType arr[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(arr, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("BinaryTreeSize:%d\n",BinaryTreeSize(root));
	printf("BinaryTreeLeafSize:(BTNode* root):%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root,3));
	BTNode* Find = BinaryTreeFind(root, 'G');
	printf("%s\n", Find == NULL ? "û�ҵ�" : "�ҵ���");
	 Find = BinaryTreeFind(root, 'Z');
	printf("%s\n", Find == NULL ? "û�ҵ�" : "�ҵ���");

	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("%s\n", BinaryTreeComplete(root)==0?"����ȫ������":"������ȫ������");



	BinaryTreeDestory(&root);
}

int main()
{
	test01();

	return	0;
}
