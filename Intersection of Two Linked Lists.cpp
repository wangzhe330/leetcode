/*

Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J            
B:     b1 ¡ú b2 ¡ú b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

Credits:
Special thanks to @stellari for adding this problem and creating all test cases.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

//#define INT_MAX 2147483647 
//#define INT_MIN -2147483648



//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = 0, lenB = 0;
		struct ListNode *pA = headA;
		struct ListNode *pB = headB;
		while (pA){
			lenA++;
			pA = pA->next;
		}
		while (pB){
			lenB++;
			pB = pB->next;
		}
		pA = headA;
		pB = headB;
		if (lenA >= lenB){
			for (int i = 0; i < lenA - lenB; i++){
				pA = pA->next;
			}
		}
		if (lenA<lenB){
			for (int i = 0; i < lenB - lenA; i++){
				pB = pB->next;
			}
		}
		while (pA){
			if (pA == pB){
				return pA;
			}
			pA = pA->next;
			pB = pB->next;
		}
		return NULL;
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

	//ListAdd(Head1, ListAdd(Node1, ListAdd(Node2, ListAdd(Node3, Node4))));
	//ListAdd(Head2, ListAdd(Node5, ListAdd(Node6, ListAdd(Node3, Node8))));
	//PrintList(Head1);
	//PrintList(Head2);
	//ListNode* result = mySolu.getIntersectionNode(Head1, Head2);
	ListNode* result = mySolu.getIntersectionNode(Node1, NULL);
	cout << result->val << endl;

}