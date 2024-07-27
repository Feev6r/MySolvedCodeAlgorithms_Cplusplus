#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Node {
public:
    int value;
    Node* Next;

};

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

void printList(Node* n) {
    while (n != NULL)
    {
        cout << n->val << endl;
        n = n->next;
    }
}


void insertAtTheFront(Node** head, int newValue) {

    Node* newNode = new Node();
    newNode->val = newValue;


    newNode->next = *head;


    *head = newNode;
}


//headptr -> head -> new Node()
// 
// head* == head
// head** == adress
// 
//newNode -> new Node()
//newNode.Next = *head
//*head = newNode


void insertAtTheEnd(Node** head, int newValue) {

    Node* newNode = new Node();
    newNode->val = newValue;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;

}

void insertAfter(Node* previous, int newValue) {

    if (previous == NULL) return;

    Node* newNode = new Node();
    newNode->val = newValue;


    newNode->next = previous->next;
    previous->next = newNode;
}


void listCreator() {

    Node* dummy = new Node();
    Node* cur = dummy;

    for (int i = 0; i < 10; i++)
    {
        cur->next = new Node(i);
        cur = cur->next;
    }

    while (dummy->next)
    {
        cout << dummy->next->val;
        dummy = dummy->next;
    }
}


int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->val = 1;
    second->val = 2;
    third->val = 3;

    head->next = second;
    second->next = third;
    third->next = nullptr;


    insertAtTheEnd(&head, 4);
}
