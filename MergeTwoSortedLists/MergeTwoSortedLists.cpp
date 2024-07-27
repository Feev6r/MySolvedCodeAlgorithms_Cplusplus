#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node* next) : val(x), next(next) {}
};


Node* mergeTwoLists(Node* list1, Node* list2) {

	Node* dummy = new Node(0);
	Node* tail = dummy;

	while (list1 != nullptr && list2 != nullptr)
	{
		if (list1 < list2) {
			tail->next = list1;



		}
		else {

			tail->next = list2;
			list2 = list2->next;
			tail = tail->next;
		}

		tail->next = list1 ? list1 : list2;
	}

	return dummy->next;


}

Node* mergeTwoLists(Node* list1, Node* list2) {
	Node* dummy = new Node();
	Node* cur = dummy;

	while (list1 && list2) {

		if (list1->val > list2->val) {
			cur->next = list2;
			list2 = list2->next;
		}
		else {
			cur->next = list1;
			list1 = list1->next;
		}

		cur = cur->next;
	}

	cur->next = list1 ? list1 : list2;

	return dummy->next;
}


int main()
{
    std::cout << "Hello World!\n";
}
