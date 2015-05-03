/*

Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

1            <---
/   \
2     3         <---
\     \
5     4       <---

You should return [1, 3, 4].
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

class Solution {
public:
	vector<int> rightSideView(TreeNode *root) {
		queue<pair<TreeNode*, int>> visited, unvisited;
		int level;
		vector<stack<int>>rec;
		vector<int>result;
		if (!root) return result;
		unvisited.push(make_pair(root, 0));
		while (!unvisited.empty()){

			pair<TreeNode*,int> current= unvisited.front();
			level = current.second;
			if (rec.size() <= level)
				rec.push_back(stack<int>());
			rec[level].push(current.first->val);

			if (current.first->left != NULL)
				unvisited.push(make_pair(current.first->left, level + 1));
			if (current.first->right != NULL)
				unvisited.push(make_pair(current.first->right, level + 1));

			visited.push(unvisited.front());
			unvisited.pop();
		}
		for (int i = 0; i < rec.size(); i++){
			result.push_back(rec[i].top());
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
	Root.left->left = &temp2;
	Root.left->right = &temp3;
	Root.right->left = &temp4;
	Root.right->right = &temp5;
	vector<int> res;
	//vector<int>temp{ 1, 2, 3 };
	//temp[3] = 5;
	//res.push_back(temp);
	//res.push_back(temp);
	//res.push_back(temp);
	res = mySolu.rightSideView(&Root);
	
	for (int j = 0; j < res.size(); j++){
		cout << res[j] << " ";
	}
	cout << endl;
	
}