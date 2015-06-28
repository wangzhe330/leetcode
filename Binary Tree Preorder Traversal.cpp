/*

Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

1
\
2
/
3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<stack>
using namespace std;

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
用迭代的方式实现二叉树的前序遍历
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> rec;
		TreeNode* p = root;
		if (root == NULL)
			return result;
		stack<TreeNode*> s;
		while (p){
			result.push_back(p->val);
			if (p->right)
				rec.push(p->right);
			if (p->left)
				rec.push(p->left);
			if (rec.empty())
				break;
			p = rec.top();
			rec.pop();
		}
		return result;
	}
};


void main()
{
	Solution mySolu;
	TreeNode Root(1);
	TreeNode temp0(2);
	TreeNode temp1(3);
	TreeNode temp2(4);
	TreeNode temp3(5);
	TreeNode temp4(6);
	TreeNode temp5(7);
	TreeNode temp6(8);
	TreeNode temp7(9);

	Root.left = &temp0;
	Root.right = &temp1;
	//temp0.left = NULL;
	//temp0.right = NULL;
	temp1.left = &temp2;
	temp1.right = &temp3;
	//Root.left = &temp0;
	//Root.right = &temp1;

	//vector<vector<int>> res;
	//vector<int>temp{ 1, 2, 3 };
	//temp[3] = 5;
	//res.push_back(temp);
	//res.push_back(temp);
	//res.push_back(temp);
	//res = mySolu.zigzagLevelOrder(&Root);
	vector<int>res;
	res = mySolu.preorderTraversal(&Root);
	for (int i = 0; i < res.size(); i++){

		cout << res[i] << " ";
	}
	cout << endl;
}