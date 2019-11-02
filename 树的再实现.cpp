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

BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
	if (a[*pi] == ' ')
	{
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a,pi);
	(*pi)++;
	root->_right = BinaryTreeCreate(a,pi);

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
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);


}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
	
}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
int BinaryTreeLeafSize(BTNode* root) // 树的叶子节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode* root, int k) // 第k层的树节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
int BinaryTreeNonLeafSize(BTNode *root) // 计算非叶子节点的数量
{

	if ((root->_left == NULL && root->_right == NULL) || root == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	return BinaryTreeNonLeafSize(root->_left)
		+ BinaryTreeNonLeafSize(root->_right);//这里+1是因为树节点没有算进去


}
void BinaryTreeDestory(BTNode** root) // 后续销毁，不能先销毁根节点
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
}

void test1()
{
	BTNode Btree;
	char*str = "ABC  DE G  F   ";
	//char*str = "ABC DE G  F   ";

	printf("原本的树\n%s\n", str);
	BTNode*  root = NULL;
	int i = 0;
	root = BinaryTreeCreate(str, &i);
	
	//printf("树的先序遍历\n");
	//BinaryTreePrevOrder(root); //树的先序遍历
	//printf("\n");
	//printf("树的中序遍历\n");
	//BinaryTreeInOrder(root);
	//printf("\n");
	//printf("树的后序遍历\n");
	//BinaryTreePostOrder(root);
	//printf("\n");
	//printf("树的节点个数\n");
	//printf("%d\n", BinaryTreeSize(root));
	//printf("树的叶子节点个数\n");
	//printf("%d\n",BinaryTreeLeafSize(root));
	//printf("第5层树的节点个数\n");
	//printf("%d\n", BinaryTreeLevelKSize(root, 5));
	printf("树的非叶子节点的个数\n");
	printf("%d\n", BinaryTreeNonLeafSize(root));
	printf("正确的是：%d\n", BinaryTreeSize(root) - BinaryTreeLeafSize(root));
	BinaryTreeDestory(&root); // 销毁树

}
void test2()
{
	BTNode BTree;
	char*str = "ABC    ";
	printf("原本的树\n%s\n", str);
	BTNode*  root = NULL;
	int i = 0;
	root = BinaryTreeCreate(str, &i);
	printf("树的先序遍历\n");
	BinaryTreePrevOrder(root); //树的先序遍历
	printf("树的非叶子节点的个数\n");
	printf("%d\n", BinaryTreeLeafSize(root));
}
int  main()
{
	test1();
	test2();
	system("pause");
}