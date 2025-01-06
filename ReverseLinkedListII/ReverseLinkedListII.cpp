#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
	
	if (right == left) return head;

	ListNode* l = new ListNode();
	ListNode* r = new ListNode();
	ListNode* connector = new ListNode();
	ListNode* prev = new ListNode();
	ListNode* start = head;


	int i = 0;
	while (++i <= right)
	{
		if (i == left - 1) connector = head;
		if (i == left) l = head;
		if (i == right) r = head;
		head = head->next;
	}

	prev = r->next;
	connector->next = r;

	while (prev != r) {
		ListNode* temp = l->next;
		l->next = prev;

		prev = l;
		l = temp;
	}

	return left == 1 ? r : start;
}


ListNode* reverseBetween(ListNode* head, int left, int right) {

	if (!head || left == right) {
		return head;
	}

	ListNode* dummy = new ListNode(0); // created dummy node
	dummy->next = head;
	ListNode* prev = dummy; // intialising prev pointer on dummy node

	for (int i = 0; i < left - 1; i++) {
		prev = prev->next; // adjusting the prev pointer on it's actual index
	}

	ListNode* curr = prev->next; // curr pointer will be just after prev
	// reversing
	for (int i = 0; i < right - left; i++) {
		ListNode* forw = curr->next; // forw pointer will be after curr
		curr->next = forw->next;
		forw->next = prev->next;
		prev->next = forw;
	}
	return dummy->next;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
	
	ListNode* dummy = new ListNode();
	dummy->next = head;
	ListNode* prev = dummy;

	for (int i = 0; i < left -1; i++)
	{
		prev = prev->next;
	}

	ListNode* curr = prev->next;

	for (int i = 0; i < right - left; i++)
	{
		ListNode* forward = curr->next;
		curr->next = forward->next;
		forward->next = prev->next;
		prev->next = forward;
	}

	return dummy->next;

}


int main()
{
    std::cout << "Hello World!\n";
