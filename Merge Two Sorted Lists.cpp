/*

Merge Two Sorted Lists


Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists

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
	ListNode* cmp(ListNode* a, ListNode* b){
		return a->val < b->val ? a : b;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head,*p;
		if (l1 == NULL&&l2 == NULL)return NULL;
		if (l1 == NULL || l2 == NULL)return l1 == NULL ? l2 : l1;
		if (l1->val < l2->val){
			p=head = l1;
			l1 = l1->next;
		}
		else{
			p=head = l2;
			l2 = l2->next;
		}
		
		while (l1 != NULL&&l2 != NULL){
			if (l1->val < l2->val)
			{
				p->next = l1;
				p = p->next;
				l1 = l1->next;
			}
			else{
				p->next = l2;
				p = p->next;
				l2 = l2->next;
			}
		}
		if (l1 == NULL){
			p->next = l2;
		}
		else
			p->next = l1;

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
	ListNode* Head1 = new ListNode(2);
	ListNode* Node1 = new ListNode(4);
	ListNode* Node2 = new ListNode(6);
	ListNode* Node3 = new ListNode(8);
	ListNode* Node4 = new ListNode(10);
	
	ListNode* Head2 = new ListNode(1);
	ListNode* Node5 = new ListNode(3);
	ListNode* Node6 = new ListNode(5);
	ListNode* Node7 = new ListNode(7);
	ListNode* Node8 = new ListNode(9);

	ListAdd(Head1, ListAdd(Node1, ListAdd(Node2, ListAdd(Node3, Node4))));
	ListAdd(Head2, ListAdd(Node5, ListAdd(Node6, ListAdd(Node7, Node8))));
	PrintList(Head1);
	PrintList(Head2);
	Head1 = mySolu.mergeTwoLists(Head1,Head2);
	PrintList(Head1);


}