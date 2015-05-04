/*

Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	ListNode* ListAdd(ListNode* head, ListNode* node);

	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)return NULL;
		if (head->next == NULL)return head;
		ListNode* newhead;
		ListNode* prev = head;
		ListNode* temp = head->next->next;
		newhead = head->next;
		head->next->next = head;
		head->next = temp;
		prev = newhead->next;
		ListNode* p = prev->next;
		while (p && (p->next)){
			
			ListNode* temp = p->next->next;
			prev->next = p->next;
			p->next->next = p;
			p->next = temp;

			
			prev = prev->next->next;
			p = prev->next;
		}
		return newhead;

	}
};

ListNode* Solution::ListAdd(ListNode* head, ListNode* node){
	if (head == NULL){
		head = node;
		return head;
	}
	ListNode* p = head;
	while (p->next != NULL){
		p = p->next;
	}
	p->next = node;
	return head;
}

void PrintList(ListNode* head){
	ListNode* p = head;
	if (head == NULL) return;
	while (p != NULL){
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void main()
{
	Solution mySolu;
	ListNode* Head1 = new ListNode(1);
	ListNode* Node1 = new ListNode(4);
	ListNode* Node2 = new ListNode(3);
	ListNode* Node3 = new ListNode(2);
	ListNode* Node4 = new ListNode(5);
	ListNode* Node9 = new ListNode(2);
	
	ListNode* Head2 = new ListNode(1);
	ListNode* Node5 = new ListNode(3);
	ListNode* Node6 = new ListNode(5);
	ListNode* Node7 = new ListNode(7);
	ListNode* Node8 = new ListNode(9);
	
	mySolu.ListAdd(Head1, mySolu.ListAdd(Node1, mySolu.ListAdd(Node2, mySolu.ListAdd(Node3, mySolu.ListAdd(Node4, Node9)))));
	//ListAdd(Head2, ListAdd(Node5, ListAdd(Node6, ListAdd(Node7, Node8))));
	PrintList(Head1);
	//PrintList(Head2);
	Head1 = mySolu.swapPairs(Head1);
	PrintList(Head1);


}