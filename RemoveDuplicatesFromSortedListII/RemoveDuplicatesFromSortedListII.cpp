#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* deleteDuplicates(ListNode* head) {

	ListNode* dummy = new ListNode(0, head);
	ListNode* left = dummy;
	ListNode* right = head;

	while (right&& right->next)
	{
		if (right->val == right->next->val) {
			right->next = right->next->next;
			left->next = right->next;

		}
		else {
			right = right->next;
			if (left->next != right) left = left->next;

		}
	}

	return dummy->next;
}


ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* left = dummy;
    ListNode* right = head;

    while (right) {

        if (right->next && right->val == right->next->val) {
            // Store the duplicate value
            int duplicate = right->val;

            // Delete all nodes with this value
            while (right && right->val == duplicate) {
                ListNode* temp = right;
                right = right->next;
                delete temp; // Free memory for the skipped node
            }

            // Link left to the first non-duplicate node
            left->next = right;
        }
        else {
            // Move left forward only if no duplicate was found
            left = left->next;
            right = right->next;
        }
    }

    return dummy->next;
}

int main()
{
    std::cout << "Hello World!\n";
}
