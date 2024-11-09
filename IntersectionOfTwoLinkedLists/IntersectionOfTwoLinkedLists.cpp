#include <iostream>
#include <unordered_map>


using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

//My humble solution
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

	unordered_map<ListNode*, int> mp;

	while (headA || headB) {

		if (headA == headB) return headA;

		if (mp.count(headA)) {
			return headA;
		}
		if (mp.count(headB)){
			return headB;
		}	
		
		if(headA) mp[headA];
		if(headB) mp[headB];

		headA = headA ? headA->next : nullptr;
		headB =	headB ? headB->next : nullptr;
	}

	return nullptr;
}

//hash table soluton
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	unordered_map<ListNode*, int> m;
	while (headA != NULL) {
		m[headA]++;
		headA = headA->next;
	}
	while (headB != NULL) {
		if (m[headB] > 0) {
			return headB;
		}
		headB = headB->next;
	}
	return NULL;
}


//Two pointers solution
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	ListNode* ptr1 = headA;
	ListNode* ptr2 = headB;

	while (ptr1 != ptr2) {

		if (ptr1 == NULL) {
			ptr1 = headB;
		}
		else {
			ptr1 = ptr1->next;
		}

		if (ptr2 == NULL) {
			ptr2 = headA;
		}
		else {
			ptr2 = ptr2->next;
		}
	}
	return ptr1;
}

int main()
{
    std::cout << "Hello World!\n";
}
