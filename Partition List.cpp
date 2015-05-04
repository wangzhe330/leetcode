/*

Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
	ListNode* partition(ListNode* head, int x) {
		ListNode* small=NULL;
		ListNode* equalORbig=NULL;
		while (head != NULL){
			ListNode* temp = head->next;
			head->next = NULL;
			if (head->val < x)
				small = ListAdd(small,head);
			else
				equalORbig = ListAdd(equalORbig,head);
			head = temp;
		}
		return ListAdd(small, equalORbig);
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
	Head1 = mySolu.partition(Head1,3);
	PrintList(Head1);


}