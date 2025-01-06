#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

//My solution:
ListNode* deleteDuplicates(ListNode* head) {

	if (!head || !head->next) return head;

	ListNode* curr = head;
	ListNode* right = head;

	while (curr && curr->next) {

		right = curr->next;

		if (curr->val == right->val) {

			curr->next = right->next;
			right = right->next;
		}
		else {
			curr = right;
		}
	}
	
	return head;

}


//Less code, less memmory, the best one i guess
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* res = head;

	while (head && head->next) {

		if (head->val == head->next->val) {
			head->next = head->next->next;
		}
		else {
			head = head->next;
		}
	}

	return res;
}

int main()
{
    std::cout << "Hello World!\n";
}
