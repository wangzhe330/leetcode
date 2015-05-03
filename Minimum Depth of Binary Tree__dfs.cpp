/*
Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
	void dfs(TreeNode *root,vector<int>&rec,int s){
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL)
		{
			rec.push_back(s);
			return;
		}
		s++;
		dfs(root->left, rec, s);
		dfs(root->right, rec, s);
		s--;
	}
	int minDepth(TreeNode *root) {
		if (root == NULL)
			return 0;
		vector<int> s_temp ;
		int count_temp = 1;
		dfs(root, s_temp,count_temp);
		int min = s_temp[0];
		for (size_t i = 1; i < s_temp.size(); i++)
		{
			if (s_temp[i] < min)
				min = s_temp[i];
		}
		return min;
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
	//Root.left->left = &temp2;
	//Root.left->right = &temp3;
	//Root.right->left = &temp4;
	//Root.left->left->left = &temp6;
	//Root.left->left->right = &temp6;
	//Root.right->right->right = &temp7;

	Solution mySolu;
	
	int min = mySolu.minDepth(&Root);

	cout << "min = " << min << endl;
}