#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};


//My Solution
ListNode* oddEvenList(ListNode* head) {


	ListNode* dummyOdd = new ListNode();
	ListNode* dummyEven = new ListNode();

	ListNode* odd = dummyOdd;
	ListNode* even = dummyEven;

	int i = 0;
	while (head)
	{

		if (i % 2 == 0)
		{
			even->next = new ListNode(head->val);
			even = even->next;
		}
		else {
			odd->next = new ListNode(head->val);
			odd = odd->next;
		}

		i++;
		head = head->next;
	}

	even->next = dummyOdd->next;
	return dummyEven->next;
	delete dummyEven;
	delete dummyOdd;
}


int main()
{
    std::cout << "Hello World!\n";
}
