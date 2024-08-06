#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

	ListNode* dummy = new ListNode(0);
	ListNode* tail = dummy;

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode* dummy = new ListNode();
	ListNode* cur = dummy;

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
