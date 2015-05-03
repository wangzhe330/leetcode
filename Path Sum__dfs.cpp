/*
Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

class Solution_old {
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

class Solution {
public:
	bool dfs(TreeNode *a, int s , int sum)
	{
		if (!a) return false;
		if (a->val + s == sum)
		{
			if (!a->left&&!a->right) return true;
			else
			{
				s += a->val;
				return dfs(a->left, s, sum) || dfs(a->right, s, sum);
			}
		}
		else{
			if (!a->left&&!a->right) return false;
			else{
				s += a->val;
				return dfs(a->left, s, sum) || dfs(a->right, s, sum);
			}
		}
	}
	bool hasPathSum(TreeNode *root, int sum) {
		if (!root) return false;
		int sum_temp = 0;
		return dfs(root, sum_temp, sum);
	}
};

void main()
{
	TreeNode Root(1);
	TreeNode temp0(-2);
	TreeNode temp1(-3);
	TreeNode temp2(1);
	TreeNode temp3(3);
	TreeNode temp4(-2);
	TreeNode temp5(7);
	TreeNode temp6(-1);
	TreeNode temp7(1);

	Root.left = &temp0;
	Root.right = &temp1;
	Root.left->left = &temp2;
	Root.left->right = &temp3;
	Root.right->left = &temp4;
	Root.left->left->left = &temp6;
	//Root.left->left->right = &temp6;
	//Root.right->right->right = &temp7;

	Solution mySolu;
	if (mySolu.hasPathSum(&Root,3))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

}