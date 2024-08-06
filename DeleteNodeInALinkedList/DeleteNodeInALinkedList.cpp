#include <iostream>

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//bad solution
void deleteNode(ListNode* node) {

    ListNode* temp = node;
    ListNode* prev = node;
    
    while (temp->next != NULL) {

        temp->val = temp->next->val;
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
}

//normal solution
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}


int main()
{
	std::cout << "Hello World!\n";
}

