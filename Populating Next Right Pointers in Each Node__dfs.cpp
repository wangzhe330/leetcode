/*
Populating Next Right Pointers in Each Node

Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

1
/  \
2    3
/ \  / \
4  5  6  7

After calling your function, the tree should look like:

1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL

*/

#include<iostream>
#include <vector>
using namespace std;


//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};


class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)return;
		static int count = 0;
		if (count == 0)
		{
			root->next = NULL;
			count = 1;
		}
		if (root == NULL)return;
		if (root->left != NULL && root->right != NULL){
			root->left->next = root->right;
			if (root->next == NULL)
				root->right->next = NULL;
			else
				root->right->next = root->next->left;
			connect(root->left);
			connect(root->right);
		}
	}
};

void main()
{
	TreeNode Root(0);
	TreeNode temp0(7);
	TreeNode temp1(3);
	TreeNode temp2(1);
	TreeNode temp3(3);
	TreeNode temp4(-2);
	TreeNode temp5(7);
	TreeNode temp6(-1);
	TreeNode temp7(1);

	TreeNode Root2(1);
	TreeNode temp8(7);
	TreeNode temp9(3);

	//Root2.left = &temp8;
	//Root2.right = &temp9;

	//Root.left = &temp0;
	//Root.right = &temp1;
	//Root.left->left = &temp2;
	//Root.left->right = &temp3;
	//Root.right->left = &temp4;
	//Root.left->left->left = &temp6;
	//Root.left->left->right = &temp6;
	//Root.right->right->right = &temp7;

	Solution mySolu;
	
	//cout << mySolu.isSameTree(&Root,&Root2) << endl;
	/*
	if (mySolu.isSameTree(&Root, &Root2))
		cout << "yse " << endl;
	else
		cout << "no " << endl;
		*/
	TreeLinkNode Root3(0);
	TreeLinkNode Root3_1(1);
	TreeLinkNode Root3_2(2);
	Root3.left = &Root3_1;
	Root3.right = &Root3_2;


	mySolu.connect(&Root3);
	cout << "ok" << endl;
}