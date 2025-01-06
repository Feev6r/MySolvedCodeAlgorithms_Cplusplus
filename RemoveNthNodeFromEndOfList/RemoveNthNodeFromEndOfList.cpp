#include <iostream>


using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//Example
struct s {
	int v1;
	int v2;

	s() : v1(0), v2(1) {}
	s(int x) : v1(x), v2(1) {}
	s(int x, int y) : v1(x), v2(y) {}
};

//My Solution (at least i was be able to learn even if the code is a little messy)
ListNode* removeNthFromEnd(ListNode* head, int n) {

	int i = 0;

	ListNode* temp = head;

	while (temp != NULL) {
		i++;
		temp = temp->next;
	}

	if (n == i) return head->next;

	temp = head;
	i = i - n;

	while (i > 1)
	{
		i--;
		temp = temp->next;
	}

	if (temp->next == NULL)	return head = NULL;

	temp->next = temp->next->next;
	return head;

}


//Clean Solution
ListNode* removeNthFromEnd2(ListNode* head, int n) {
	ListNode* res = new ListNode(0, head);
	ListNode* dummy = res;

	for (int i = 0; i < n; i++) {
		head = head->next;
	}

	while (head != nullptr) {
		head = head->next;
		dummy = dummy->next;
	}

	dummy->next = dummy->next->next;

	return res->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* fast = head, *slow = head;

	for (int i = 0; i < n; i++) fast = fast->next;

	if (!fast) return head->next;

	while (fast->next) fast = fast->next, slow = slow->next;

	slow->next = slow->next->next;
	return head;
}

int main()
{
	ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
}

