#include"Tree.h"
#include"Queue.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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

// ����������
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

// ������ǰ����� 
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
// �������������
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
// �������������
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

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (!root)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
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

// ��������k��ڵ����
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

// ����������ֵΪx�Ľڵ�
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

// �������
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

// �ж϶������Ƿ�����ȫ������
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