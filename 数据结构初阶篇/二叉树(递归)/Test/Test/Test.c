#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if(!node)
	{
		perror("malloc fail");
		exit(1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

BTNode*CreatTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node3->right = node7;
	return node1;
}

//前序遍历
void PreOrder(BTNode*root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//后序遍历
void PustOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}

	PustOrder(root->left);
	PustOrder(root->right);
	printf("%d ", root->data);
}

//求节点个数
int TreeSize(BTNode*root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) 
	+   TreeSize(root->right) 
	+	 1;
}

//求深度
int TreeHeight(BTNode *root)
{
	if (!root)
	{
		return 0;
	}
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1; 
}

int TreeKLeve(BTNode*root,int k)
{
	if (root == NULL) {
		return 0;
	}
	if (k==1)
	{
		return 1;
	}
 	 return TreeKLeve(root->left,k-1)+ TreeKLeve(root->right,k-1);

}

BTNode* TreeFind(BTNode*root,BTDataType x)
{
	if (!root)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}
	BTNode* lret = TreeFind(root->left,x);
	if (lret)
	{
		return lret;
	}
	BTNode *rret = TreeFind(root->right, x);
	if (rret)
	{
		return rret;
	}
	return NULL;
}

int main()
{
	BTNode* root = CreatTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PustOrder(root);
	printf("\n");
	//TreeSize(root);
	printf("Size:%d\n", TreeSize(root));
	printf("Height:%d\n", TreeHeight(root));
	printf("%p\n", TreeFind(root, 5));
	printf("%p\n", TreeFind(root, 50));
	
	return 0;
}