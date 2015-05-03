/*

Clone Graph

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

1
/ \
/   \
0 --- 2
/ \
\_/


*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<stack>
#include <unordered_map>
using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>hash;
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)return node;	
		//unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it = hash.find(node);
		if (hash.find(node) == hash.end()){
			UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
			hash[node] = newNode;
			for (int i = 0; i < node->neighbors.size(); i++){
				hash[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
			}
		}
		return hash[node];

		/*
	for (int i = 0; i < node->neighbors.size(); i++){
			if (node->neighbors[i] == node)
				return &re;
			re.neighbors.push_back(node->neighbors[i]);
		}

		return &re;*/
	}
};


void main()
{
	Solution mySolu;
	UndirectedGraphNode root(0);
	UndirectedGraphNode temp1(1);
	UndirectedGraphNode temp2(2);
	UndirectedGraphNode temp3(3);
	/*root.neighbors.push_back(&temp1);
	root.neighbors.push_back(&temp2);
	temp1.neighbors.push_back(&temp2);
	temp2.neighbors.push_back(&temp2);
	*/
	UndirectedGraphNode *result =  mySolu.cloneGraph(&root);
	cout << "root's label = " << result->label<< endl;
}