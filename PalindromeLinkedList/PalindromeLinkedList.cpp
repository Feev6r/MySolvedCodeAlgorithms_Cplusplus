#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};



bool isPalindrome(ListNode* head) {

	ListNode* mid = head;
	ListNode* cur = head;

	while (cur && cur->next)
	{
		cur = cur->next->next;
		mid = mid->next;
	}

	ListNode* prev = nullptr;
	cur = mid;

	while (cur != nullptr) {
		ListNode* temp = cur->next;
		cur->next = prev;

		prev = cur;
		cur = temp;
	}

	//return prev;

	while (prev)
	{
		if (prev->val != head->val) {
			return false;
		}

		prev = prev->next;
		head = head->next;
	}

	return true;
}


int main()
{
	ListNode* dummy = new ListNode();
	ListNode* cur = dummy;

	for (int i = 0; i < 10; i++)
	{
		cur->next = new ListNode(i);
		cur = cur->next;
	}

	//ListNode* midlist = mid(dummy->next);


	//while (midlist)
	//{
	//	cout << midlist->val;
	//	midlist = midlist->next;
	//}
}
