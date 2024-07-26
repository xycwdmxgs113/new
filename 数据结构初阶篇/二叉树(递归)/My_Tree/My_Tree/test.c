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
	printf("%s\n", Find == NULL ? "没找到" : "找到了");
	 Find = BinaryTreeFind(root, 'Z');
	printf("%s\n", Find == NULL ? "没找到" : "找到了");

	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("%s\n", BinaryTreeComplete(root)==0?"是完全二叉树":"不是完全二叉树");



	BinaryTreeDestory(&root);
}

int main()
{
	test01();

	return	0;
}
