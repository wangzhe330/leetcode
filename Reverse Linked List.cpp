/*

Reverse Linked List


Reverse a singly linked list.

click to show more hints.
Hint:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

#include<iostream>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
		if (!head || !head->next)return head;
		while (head != NULL){
			ListNode* temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}
		return prev;
	}
};

void PrintList(ListNode* head){
	if (!head)return;
	while (head != NULL){
		cout << head->val;
		head = head->next;
		cout << "->";
	}
	cout << "NULL";
	cout << endl;
}


void main()
{
	ListNode* node0 = new ListNode(0);
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	node0->next = node1;
	node1->next = node2;
	node2->next = NULL;
	PrintList(node0);
	Solution mySolu;
	
	PrintList(mySolu.reverseList(node0));
}