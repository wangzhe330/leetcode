/*

Binary Tree Zigzag Level Order Traversal


Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7

return its zigzag level order traversal as:

[
[3],
[20,9],
[15,7]
]

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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>>result;
		vector<stack<int>>rec;
		
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
			if (rec.size() <= level)
				rec.push_back(stack<int>());
			rec[level].push(current.first->val);

			if (current.first->left != NULL){
				unvisited.push(make_pair(current.first->left,current.second+1));
			}
			if (current.first->right != NULL){
				unvisited.push(make_pair(current.first->right,current.second+1));
			}
			visited.push(current);
			unvisited.pop();
		}
		for (int i = 0; i < rec.size(); i++){
			vector<int>temp;
			vector<int>temp_re;
			while (!rec[i].empty()){
				temp.push_back(rec[i].top());
				rec[i].pop();
			}
			if (i % 2 == 0){
				vector<int>temp_re(temp);
				int len = temp.size();
				for (int j = 0; j < len; j++){
					temp_re[j] = temp[len - j-1];
				}
				result.push_back(temp_re);
				temp_re.clear();
				temp.clear();
			}
			else{
				result.push_back(temp);
				temp.clear();

			}
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

	//Root.left = &temp0;
	//Root.right = &temp1;

	vector<vector<int>> res;
	//vector<int>temp{ 1, 2, 3 };
	//temp[3] = 5;
	//res.push_back(temp);
	//res.push_back(temp);
	//res.push_back(temp);
	res = mySolu.zigzagLevelOrder(&Root);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}