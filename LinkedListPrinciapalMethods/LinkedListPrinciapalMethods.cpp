#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class ListNode {
public:
    int value;
    ListNode* Next;

};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* n) {
    while (n != NULL)
    {
        cout << n->val << endl;
        n = n->next;
    }
}


void insertAtTheFront(ListNode** head, int newValue) {

    ListNode* newNode = new ListNode();
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


void insertAtTheEnd(ListNode** head, int newValue) {

    ListNode* newNode = new ListNode();
    newNode->val = newValue;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    ListNode* last = *head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;

}

void insertAfter(ListNode* previous, int newValue) {

    if (previous == NULL) return;

    ListNode* newNode = new ListNode();
    newNode->val = newValue;


    newNode->next = previous->next;
    previous->next = newNode;
}


void listCreator() {

    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;

    for (int i = 0; i < 10; i++)
    {
        cur->next = new ListNode(i);
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
    ListNode* head = new ListNode();
    ListNode* second = new ListNode();
    ListNode* third = new ListNode();

    head->val = 1;
    second->val = 2;
    third->val = 3;

    head->next = second;
    second->next = third;
    third->next = nullptr;


    insertAtTheEnd(&head, 4);
}
