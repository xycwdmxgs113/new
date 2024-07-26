#include"Tree.h"
#include"Queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi]=='#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);

	return root;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (!(*root))
	{
		return;
	}
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free((*root));
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (!root)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (!root)
	{
		return;
	}
	
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (!root)
	{
		return;
	}

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (!root)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (!root) {
		return 0;
	}

	if (!root->_right&& !root->_left)
	{
		return 1;
	}
	return  BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (!root)
		return 0;
	if (k==1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k-1) + BinaryTreeLevelKSize(root->_right, k-1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (!root)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left)
	{
		return left;
	}
	BTNode* right= BinaryTreeFind(root->_right, x);
	if (right)
		return right;

	return NULL;
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QInit(&q);
	QPush(&q, root);
	while (!QEmpty(&q))
	{
		BTNode* Front = QFront(&q);
		if (!Front)
		{
			break;
		}
		printf("%c", Front->_data);
		QPop(&q);
		QPush(&q, Front->_left);
		QPush(&q, Front->_right);
	}
	QDestroy(&q);
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QInit(&q);
	QPush(&q, root);
	while (!QEmpty(&q))
	{
		BTNode* Front = QFront(&q);
		QPop(&q);
		if (!Front)
		{
			break;
		}
		else
		{
			QPush(&q, Front->_left);
			QPush(&q, Front->_right);
		}

	}

	while (!QEmpty(&q))
	{
		BTNode* Front = QFront(&q);
		if (Front)
		{
			QDestroy(&q);
			return -1;
		}
		QPop(&q);
	}
	QDestroy(&q);
	return 0;
}