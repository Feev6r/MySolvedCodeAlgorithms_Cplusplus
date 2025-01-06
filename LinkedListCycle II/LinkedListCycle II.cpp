#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//hash map - solution (so bad)
ListNode* detectCycle(ListNode* head) {

	unordered_map< ListNode*, bool> mp;

	while (head)
	{
		if (mp[head]) return head;
		mp[head] = true;

		head = head->next;
	}
	return nullptr;
}


//Floyd's cycle detection - solution
ListNode* detectCycle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}


int main()
{
    std::cout << "Hello World!\n";
}
