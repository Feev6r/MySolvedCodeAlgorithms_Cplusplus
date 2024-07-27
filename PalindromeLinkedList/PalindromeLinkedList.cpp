#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node* next) : val(x), next(next) {}
};



bool isPalindrome(Node* head) {

	Node* mid = head;
	Node* cur = head;

	while (cur && cur->next)
	{
		cur = cur->next->next;
		mid = mid->next;
	}

	Node* prev = nullptr;
	cur = mid;

	while (cur != nullptr) {
		Node* temp = cur->next;
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
	Node* dummy = new Node();
	Node* cur = dummy;

	for (int i = 0; i < 10; i++)
	{
		cur->next = new Node(i);
		cur = cur->next;
	}

	//ListNode* midlist = mid(dummy->next);


	//while (midlist)
	//{
	//	cout << midlist->val;
	//	midlist = midlist->next;
	//}
}
