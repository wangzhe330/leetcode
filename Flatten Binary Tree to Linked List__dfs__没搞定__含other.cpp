/*
Flatten Binary Tree to Linked List

Populating Next Right Pointers in Each Node

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2   5
/ \   \
3   4   6

The flattened tree should look like:

1
\
2
\
3
\
4
\
5
\
6

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

//my solution

/*
class Solution {
public:
	TreeNode *dfs(TreeNode *root){
		if (root == NULL)return NULL;
		if (root->left == NULL&&root->right == NULL)return root;

		TreeNode *right_rec = root->right;
		root->right = dfs(root->left);
		TreeNode *p = root;
		while (p->right != NULL)
			p = p->right;
		p->right = right_rec;
		dfs(right_rec);

		return root;
	}
	void flatten(TreeNode *root) {
		root = dfs(root);
	}
};*/


//other solution
class Solution {
public:
	TreeNode *dfs(TreeNode *root){
		if (root == NULL)return NULL;
		if (root->left == NULL&&root->right == NULL)return root;

		TreeNode *right_rec = root->right;
		root->right = dfs(root->left);
		TreeNode *p = root;
		while (p->right != NULL)
			p = p->right;
		p->right = right_rec;
		dfs(right_rec);

		return root;
	}
	void flatten(TreeNode *root) {
		root = dfs(root);
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
	TreeNode temp8(2);
	TreeNode temp9(2);

	//Root2.left = &temp8;
	Root2.right = &temp9;

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
	TreeLinkNode Root3(1);
	TreeLinkNode Root3_1(2);
	TreeLinkNode Root3_2(2);
	Root3.left = &Root3_1;
	//Root3.right = &Root3_2;


	mySolu.flatten(&Root2);
	cout << "ok" << endl;
}