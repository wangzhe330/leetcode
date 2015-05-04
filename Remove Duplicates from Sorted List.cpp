/*

Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* p = head;
		if (head == NULL)return NULL;
		while (p->next != NULL){
			if (p->next->val == p->val){
				ListNode* temp = p->next;
				p->next = temp->next;
				delete(temp);
			}
			else
				p = p->next;
		}
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
	ListNode* Node1 = new ListNode(1);
	ListNode* Node2 = new ListNode(1);
	ListNode* Node3 = new ListNode(4);
	ListNode* Node4 = new ListNode(5);
	
	ListAdd(Head, ListAdd(Node1, ListAdd(Node2, ListAdd(Node3, Node4))));
	PrintList(Head);
	mySolu.deleteDuplicates(Head);
	PrintList(Head);


}