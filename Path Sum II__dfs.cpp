/*
Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1

return

[
[5,4,11,2],
[5,8,4,5]
]

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


class Solution {
public:
	void dfs(TreeNode *root, int s, int sum , vector<vector<int>> &result , vector<int>& rec_now)
	{
		if (root == NULL ) return ;
		if (root->val + s == sum && root->left == NULL && root->right == NULL)
		{
			rec_now.push_back(root->val);
			result.push_back(rec_now);
			rec_now.pop_back();
			return;
		}
		s += root->val;
		rec_now.push_back(root->val);
		dfs(root->left, s, sum, result, rec_now);
		dfs(root->right, s, sum, result, rec_now);
		rec_now.pop_back();
	}

	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > ans;
		vector<int> v_temp;
		if (!root) return ans;
		int sum_temp = 0;
		dfs(root, sum_temp, sum,ans,v_temp);
		return ans;
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
	vector<vector<int>> re;
	re = mySolu.pathSum(&Root, 2);
	
	for (size_t i = 0; i < re.size(); i++)
	{
		for (size_t j = 0; j < re[i].size(); j++)
		{
			cout << re[i][j] << ' ';
		}
		cout << endl;
	}
}