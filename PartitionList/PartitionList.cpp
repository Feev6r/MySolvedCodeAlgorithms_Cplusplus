#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};


ListNode* partition(ListNode* head, int x) {

	ListNode* start = new ListNode();
	ListNode* pt1 = start;

	ListNode* start2 = new ListNode();
	ListNode* pt2 = start2;

	while (head)
	{
		while (head && head->val < x)
		{
			pt1->next = head;
			head = head->next;

			pt1 = pt1->next;
		}
		while (head && head->val >= x) {
			pt2->next = head;
			head = head->next;

			pt2 = pt2->next;
		}
	}

	pt1->next = nullptr;
	pt2->next = nullptr;

	pt1->next = start2->next;
	return start->next;

}

int main()
{
	std::cout << "Hello World!\n";
}

