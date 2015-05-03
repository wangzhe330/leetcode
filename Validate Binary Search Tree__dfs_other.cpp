/*
Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


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
	bool isValidBST(TreeNode* root) {
		TreeNode* prev = NULL;
		return validate(root, prev);
	}
	bool validate(TreeNode* node, TreeNode* &prev) {
		if (node == NULL) return true;
		if (!validate(node->left, prev)) return false;
		if (prev != NULL && prev->val >= node->val) return false;
		prev = node;
		return validate(node->right, prev);
	}
};
void main()
{
	TreeNode Root(0);
	TreeNode temp0(-1);
	TreeNode temp1(3);
	TreeNode temp2(1);
	TreeNode temp3(3);
	TreeNode temp4(-2);
	TreeNode temp5(7);
	TreeNode temp6(-1);
	TreeNode temp7(1);

	//Root.left = &temp0;
	Root.right = &temp1;
	//Root.left->left = &temp2;
	//Root.left->right = &temp3;
	//Root.right->left = &temp4;
	//Root.left->left->left = &temp6;
	//Root.left->left->right = &temp6;
	//Root.right->right->right = &temp7;

	Solution mySolu;
	
	if (mySolu.isValidBST(&Root))
		cout << "yes " << endl;
	else
		cout << "no  " << endl;

	
}