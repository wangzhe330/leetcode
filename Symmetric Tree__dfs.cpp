/*
Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3

But the following is not:

1
/ \
2   2
\   \
3    3

*/

#include<iostream>
using namespace std;


//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool dfs(TreeNode *a, TreeNode *b)
	{
		if (!a && !b) return true;	//都为空
		if (!a || !b) return false;	//有一个不为空	

		if (a->val != b->val)
			return false;
		return dfs(a->left, b->right) && dfs(a->right, b->left);
	}
	bool isSymmetric(TreeNode *root) {
		if (!root)
			return true;
		return (dfs(root->left, root->right));
	}
};

void main()
{
	TreeNode Root(1);
	TreeNode temp0(2);
	TreeNode temp1(2);
	TreeNode temp2(3);
	TreeNode temp3(5);
	TreeNode temp4(4);
	TreeNode temp5(3);

	Root.left = &temp0;
	Root.right = &temp1;
	Root.left->left = &temp2;
	Root.left->right = &temp3;
	Root.right->left = &temp4;
	Root.right->right = &temp5;

	Solution mySolu;
	if (mySolu.isSymmetric(&Root))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

}