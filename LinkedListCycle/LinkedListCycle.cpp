#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


bool hasCycle(ListNode* head) {
 
	ListNode* slow = head;
	ListNode* fast = head;

	while (slow && fast)
	{
		slow = slow->next->next;
		fast = fast->next;

		if (fast == slow) {
			return true;
		}
	}

	return false;
}


int main()
{
    std::cout << "Hello World!\n";
}
