/*

Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7

return its level order traversal as:

[
[3],
[9,20],
[15,7]
]

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int>>result;
		std::queue<pair<TreeNode*,int>> visited, unvisited;
		if (root == NULL)
			return result;
		unvisited.push(make_pair(root,0));
		//vector<int>temp;
		//temp.push_back(root->val);
		//result.push_back(temp);
		while (!unvisited.empty()){
			vector<int>temp;
			pair<TreeNode*,int> current = unvisited.front();
			
			int level = current.second;
			if (result.size() <= level)
				result.push_back(vector<int>());
			result[level].push_back(current.first->val);

			if (current.first->left != NULL){
				unvisited.push(make_pair(current.first->left,current.second+1));
			}
			if (current.first->right != NULL){
				unvisited.push(make_pair(current.first->right,current.second+1));
			}
			visited.push(current);
			unvisited.pop();
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

	vector<vector<int>> res;
	//vector<int>temp{ 1, 2, 3 };
	//temp[3] = 5;
	//res.push_back(temp);
	//res.push_back(temp);
	//res.push_back(temp);
	res = mySolu.levelOrder(&Root);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}