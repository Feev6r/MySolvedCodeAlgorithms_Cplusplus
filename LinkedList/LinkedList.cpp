#include <iostream>

class ListNode {
public:
	int Value;
	ListNode* Next;
};

void printList(ListNode* n) {

	while (n != NULL)
	{
		std::cout << n->Value << std::endl;
		n = n->Next;		
	}

}


int main()
{
	//Nodes
	ListNode* head = new ListNode();
	ListNode* second = new ListNode();
	ListNode* third = new ListNode();

	//Values
	head->Value = 1;
	second->Value = 2;
	third->Value = 3;

	//Point
	head->Next = second;
	second->Next = third;
	third->Next = NULL;

	printList(head);
}


