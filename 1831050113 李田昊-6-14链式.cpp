#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef char BTDataType;

typedef struct BTNode
{
	BTDataType _data;
	BTNode* _left;
	BTNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == ' ')
	{
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, pi);
	(*pi)++;
	root->_right = BinaryTreeCreate(a, pi);

	return root;

}
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}
int BinaryTreeNonLeafSize(BTNode *root) // 计算非叶子节点的数量
{
	//int count = 0;
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 0;
	}
	 
	return BinaryTreeNonLeafSize(root->_left)
		+ BinaryTreeNonLeafSize(root->_right)+ 1;//这里+1是因为树节点没有算进去


}
int main()
{
	BTNode BTree;
	char*str = "ABC  DE G  F   ";
	BTNode*  root = NULL;
		int i = 0;
		root = BinaryTreeCreate(str, &i);
	printf("树的非叶子节点的个数\n");
	printf("%d\n", BinaryTreeNonLeafSize(root));
	system("pause");
}

