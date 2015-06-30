/*
Balanced Binary Tree 

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b)
{
    return a>b?a:b;
}
 
int dfs(struct TreeNode* root)
{
    if(root==NULL)
        return 0;
    return max(dfs(root->left),dfs(root->right))+1;
}
 
bool isBalanced(struct TreeNode* root) {
    if(root==NULL)
        return true;
    if( ( dfs(root->left) > (dfs(root->right)+1) ) || (dfs(root->left)<(dfs(root->right)-1)))
        return false;
    else 
        return (isBalanced(root->left)&&isBalanced(root->right));
}