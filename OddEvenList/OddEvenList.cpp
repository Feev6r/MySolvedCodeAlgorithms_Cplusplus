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


ListNode* oddEvenList(ListNode* head) {

	if (!head || !head->next || !head->next->next) return head;

	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* even_start = head->next;

	while (odd->next && even->next) {

		odd->next = even->next; //Connect all odds
		even->next = odd->next->next;  //Connect all evens

		odd = odd->next;
		even = even->next;
	}

	odd->next = even_start;   //Place the first even node after the last odd node.
	return head;

	//brilliant solution! si fernando del futuro, fuck u bitch 
}

int main()
{
    std::cout << "Hello World!\n";
}
