/*

Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !(head->next))return head;
		ListNode* p, *q;
		ListNode* count = head;
		int len = 0;
		while (count->next != NULL) len++;
		k = k%len;
		p = q = head;
		for (int i = 0; i < k; i++)q = q->next;
		if (!q){
			return head;
		}
		while ( q->next){
			p = p->next;
			q = q->next;
		}
		q->next = head;
		head = p->next;
		p->next = NULL;
		return head;
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
	ListNode* Node1 = new ListNode(2);
	ListNode* Node2 = new ListNode(3);
	ListNode* Node3 = new ListNode(4);
	ListNode* Node4 = new ListNode(5);
	ListNode* Node9 = new ListNode(6);
	
	ListNode* Head2 = new ListNode(1);
	ListNode* Node5 = new ListNode(3);
	ListNode* Node6 = new ListNode(5);
	ListNode* Node7 = new ListNode(7);
	ListNode* Node8 = new ListNode(9);
	
	mySolu.ListAdd(Head1, mySolu.ListAdd(Node1, mySolu.ListAdd(Node2, mySolu.ListAdd(Node3, mySolu.ListAdd(Node4, Node9)))));
	//ListAdd(Head2, ListAdd(Node5, ListAdd(Node6, ListAdd(Node7, Node8))));
	PrintList(Head1);
	//PrintList(Head2);
	Head1 = mySolu.rotateRight(Head1,2);
	PrintList(Head1);


}