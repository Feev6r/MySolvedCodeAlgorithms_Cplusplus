#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//with stack
void reorderList(ListNode* head) {

	if (!head->next) return;

	stack<ListNode*> st;
	ListNode* dummy = new ListNode();
	dummy->next = head;

	while (head) {

		st.push(head);
		head = head->next;
	}

	head = dummy->next;

	while (head && head != st.top())
	{
		ListNode* temp = head->next;
		head->next = st.top();
		head->next->next = temp != head->next->next ? temp : nullptr;

		head = temp;
		st.pop();
	}

	head->next = nullptr;
}

//Without stack Memory O(1) 
void reorderList(ListNode* head) {
	
	if (!head->next) return;

	ListNode* left = head;
	ListNode* right = head;

	while (right && right->next) {

		right = right->next->next;
		if (right) {
			left = left->next; 
		}
	}

	right = left->next;
	left->next = nullptr;
	left = head;

	ListNode* prev = nullptr;

	while (right) {
		ListNode* temp = right->next;

		right->next = prev;
		prev = right;

		right = temp;
	}

	right = prev;
	while (left && right)
	{
		ListNode* tempL = left->next;
		ListNode* tempR = right->next;

		left->next = right;
		left->next->next = tempL;

		left = tempL;
		right = tempR;
	}

	if (left) left->next = nullptr;
}

int main()
{
	std::cout << "Hello World!\n";
}

