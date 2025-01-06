#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


//my messy solution hehe bla bla
ListNode* reverseKGroup(ListNode* head, int k) {

	if (!head->next) return head;

	ListNode* cur = head;
	int n = 0;

	while (cur) {
		n++;
		cur = cur->next;
	}
	
	int a = n / k;


	cur = head;
	ListNode* tail = new ListNode();
	ListNode* start = tail;

	for (int i = 0; i < a; i++)
	{
		ListNode* prev = nullptr;
		ListNode* first = cur;

		for (int i = 0; i < k; i++)
		{
			ListNode* temp = cur->next;
			cur->next = prev;

			prev = cur;
			cur = temp;
		}

		tail->next = prev;
		tail = first;
	}

	tail->next = cur;

	return start->next;
}


//ANOTHER SOLUTION - recursive solution
ListNode* reverseKGroup(ListNode* head, int k) {

	ListNode* curr = head;
	ListNode* prev = NULL;
	ListNode* next = NULL;
	int count = 0;

	// Count nodes in the current group
	ListNode* check = head;
	for (int i = 0; i < k; ++i) {

		if (!check) return head; // Not enough nodes to reverse
		check = check->next;
	}

	// Reverse k nodes
	while (curr != NULL && count < k) {

		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;

		count++;
	}

	// Recursively call for the remaining list
	if (next != NULL) {
		head->next = reverseKGroup(next, k);
	}

	// Return the new head of the reversed group
	return prev;
}

int main()
{
    std::cout << "Hello World!\n";
}
