#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode 
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}Tree;

Tree* CreatTree(char* a, int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    Tree* newtreenode = (Tree*)malloc(sizeof(Tree));
    newtreenode->val = a[(*pi)++];
    newtreenode->left = CreatTree(a, pi);
    newtreenode->right = CreatTree(a, pi);
    return newtreenode;
}

void Inorder(Tree* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    printf("%c ", root->val);
    Inorder(root->right);
}

int main() {
    char arr[100];
    scanf("%s", arr);
    int i=0;
    Tree* root = CreatTree(arr, &i);
    Inorder(root);
    return 0;
}