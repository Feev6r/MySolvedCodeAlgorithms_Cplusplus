#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};


ListNode* swapPairs(ListNode* head) {

	ListNode dummy(0, head);
	ListNode* prev = &dummy, *cur = head;

	while (cur && cur->next) {

		ListNode* npn = cur->next->next;
		ListNode* second = cur->next;

		second->next = cur;
		cur->next = npn;
		prev->next = second;

		prev = cur;
		cur = npn;
	}

	return dummy.next;
}


//BEST: ONLY CHECK THIS
ListNode* swapPairs(ListNode* head) {
	
	if (!head || !head->next) return head;

	ListNode* dummy = new ListNode();
	ListNode* prev = dummy;
	ListNode* curr = head;

	while (curr && curr->next)
	{
		prev->next = curr->next;
		curr->next = prev->next->next;
		prev->next->next = curr;

		prev = curr;
		curr = curr->next;
	}

	return dummy->next;
}


int main()
{
    std::cout << "Hello World!\n";
}

