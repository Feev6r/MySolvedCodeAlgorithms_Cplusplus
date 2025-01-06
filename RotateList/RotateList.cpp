#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* rotateRight(ListNode* head, int k) {

	if (!head || !head->next) return head;

	ListNode* curr = head;
	int n = 1;

	while (curr->next)
	{
		curr = curr->next;
		n++;
	}

	curr->next = head;
	k = k % n;
	k = n - k;

	while (k-- > 0) {
		curr = curr->next;
	}
	
	head = curr->next;
	curr->next = nullptr;

	return head;
}


int main()
{
    std::cout << "Hello World!\n";
}
