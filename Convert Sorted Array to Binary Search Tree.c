/*
Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef int ElementType;

typedef struct TreeNode* PtrToNode;
typedef PtrToNode		 SearchTree;

struct TreeNode* dfs(int* nums, int numsSize,int begin ,int end)
{
    int mid ;
    if(begin > end )
        return NULL;
    mid = (begin+end)/2;
    SearchTree root = (SearchTree)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = dfs( nums , numsSize , begin , mid-1);
    root->right = dfs(nums, numsSize ,mid+1, end);
}



struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    SearchTree root = NULL ;
    root = dfs(nums,numsSize,0,numsSize-1);
    return root;
    
}
