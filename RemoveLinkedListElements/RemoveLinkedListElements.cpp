#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {

	ListNode* curr = new ListNode();
	curr->next = head;
	ListNode* dummy = curr;

	while (curr)
	{
		while (curr && curr->next && curr->next->val == val)
		{
			ListNode* temp = curr->next;
			curr->next = curr->next->next;					
			delete temp;
		}
		
		curr = curr->next;
	}

	return dummy->next;
}

int main()
{
    std::cout << "Hello World!\n";
}

