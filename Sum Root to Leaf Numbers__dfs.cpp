/*
Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

1
/ \
2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.




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
	void dfs(TreeNode *root, vector<int>&path_sum , vector<int>&path_rec){
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL)
		{
			int temp = 0;
			path_rec.push_back(root->val);
			int len = path_rec.size();
			for (int i = 0; i < len; i++){
				temp += path_rec[i] * pow(10, len - i-1);
			}
			path_sum.push_back(temp);
			path_rec.pop_back();
			return;
		}
		path_rec.push_back(root->val);
		dfs(root->left, path_sum, path_rec);
		dfs(root->right, path_sum, path_rec);
		path_rec.pop_back();
	}
	int sumNumbers(TreeNode *root) {
		if (root == NULL)
			return 0;
		vector<int> s_temp;
		vector<int> r_temp;
		dfs(root, s_temp,r_temp);
		int sum = 0;
		for (size_t i = 0; i < s_temp.size(); i++)
		{
				sum += s_temp[i];
		}
		return sum;
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

	Root.left = &temp0;
	Root.right = &temp1;
	Root.left->left = &temp2;
	Root.left->right = &temp3;
	//Root.right->left = &temp4;
	//Root.left->left->left = &temp6;
	//Root.left->left->right = &temp6;
	//Root.right->right->right = &temp7;

	Solution mySolu;
	
	cout << mySolu.sumNumbers(&Root) << endl;

	
}