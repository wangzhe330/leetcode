/*
Populating Next Right Pointers in Each Node



Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.

For example,
Given the following binary tree,

1
/  \
2    3
/ \    \
4   5    7

After calling your function, the tree should look like:

1 -> NULL
/  \
2 -> 3 -> NULL
/ \    \
4-> 5 -> 7 -> NULL


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
	TreeLinkNode * Sig(TreeLinkNode * root){	
		if (!root) return NULL;
		if (root->left)return root->left;
		else if (root->right)return root->right;
		else if (!(root->next))return NULL;
		else return Sig(root->next);
	}
	void connect(TreeLinkNode *root) {
		if (root == NULL)return;
		static int count = 0;
		if (count == 0)
		{
			root->next = NULL;
			count = 1;
		}
		if (root == NULL)return;
		if (root->left)
		{
			if (root->right)root->left->next = root->right;
			else
				root->left->next = Sig(root->next);		
		}
		if (root->right){
			root->right->next = Sig(root->next);
		}
		connect(root->left);
		connect(root->right);
	}
	
};

void main()
{
	TreeNode Root(1);
	TreeNode temp0(2);
	TreeNode temp1(2);
	TreeNode temp2(3);
	TreeNode temp3(3);
	TreeNode temp4(4);
	TreeNode temp5(4);
	TreeNode temp6(-1);
	TreeNode temp7(1);

	TreeNode Root2(1);
	TreeNode temp8(7);
	TreeNode temp9(3);

	//Root2.left = &temp8;
	//Root2.right = &temp9;

	Root.left = &temp0;
	Root.right = &temp1;
	Root.left->left = &temp2;
	Root.right->right = &temp3;
	Root.left->left->left = &temp4;
	Root.right->right->right = &temp5;
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