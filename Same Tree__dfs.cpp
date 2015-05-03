/*

Same Tree


Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL)return false;
		if (p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else return false;
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
	if (mySolu.isSameTree(&Root, &Root2))
		cout << "yse " << endl;
	else
		cout << "no " << endl;
	
}