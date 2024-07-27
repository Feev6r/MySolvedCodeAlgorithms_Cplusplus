#include <iostream>

//Definition for singly-linked list.
struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(NULL) {}
};

//bad solution
void deleteNode(Node* node) {

    Node* temp = node;
    Node* prev = node;
    
    while (temp->next != NULL) {

        temp->val = temp->next->val;
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
}

//normal solution
void deleteNode(Node* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}


int main()
{
	std::cout << "Hello World!\n";
}

