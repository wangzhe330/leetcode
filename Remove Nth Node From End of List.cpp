/*

Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.



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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p, *q;
		p = q = head;
		for (int i = 0; i < n; i++)
		{
			q = q->next;
		}
		if (q == NULL){
			return  p->next;
		}
		while (q->next != NULL){
			p = p->next;
			q = q->next;
		}
		ListNode* temp = p->next;
		p->next = temp->next;
		delete(temp);
		return head;
	}
};

ListNode* ListAdd(ListNode* head, ListNode* node){
	if (head == NULL)return NULL;
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
	ListNode* Head = new ListNode(1);
	ListNode* Node1 = new ListNode(2);
	ListNode* Node2 = new ListNode(3);
	ListNode* Node3 = new ListNode(4);
	ListNode* Node4 = new ListNode(5);
	
	ListAdd(Head, ListAdd(Node1, ListAdd(Node2, ListAdd(Node3, Node4))));
	PrintList(Head);
	mySolu.removeNthFromEnd(Head,2);
	PrintList(Head);


}