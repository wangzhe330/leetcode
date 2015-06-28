/*
Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> rec;
		TreeNode* p = root;
		if (root == NULL)
			return result;
		do{
		    while(p!=NULL){
		        rec.push(p);
		        p = p->left;
		    }
		    if(!rec.empty()){
		        p = rec.top();
		        rec.pop();
		        result.push_back(p->val);
		        p=p->right;
		    }
		}while(p!=NULL || !rec.empty());
		return result;
    }
};