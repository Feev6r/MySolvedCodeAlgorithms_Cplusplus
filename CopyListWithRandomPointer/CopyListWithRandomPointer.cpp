#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


//My solution - hash map solution
Node* copyRandomList(Node* head) {

    unordered_map<Node*, Node*> mp;

    Node* dummy = new Node(0);
    Node* copyHead = dummy;

    while (head)
    {
        copyHead->next = new Node(head->val);
        copyHead->next->random = head->random;

        mp[head] = copyHead->next;

        copyHead = copyHead->next;
        head = head->next;
    }

    copyHead = dummy->next;
      
    while (copyHead)
    {
        copyHead->random = mp[copyHead->random];
        copyHead = copyHead->next;
    }

    return dummy->next;
}

//hash map - solution
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    unordered_map<Node*, Node*> old_to_new;

    Node* curr = head;
    while (curr) {
        old_to_new[curr] = new Node(curr->val);
        curr = curr->next;
    }

    curr = head;
    while (curr) {
        old_to_new[curr]->next = old_to_new[curr->next];
        old_to_new[curr]->random = old_to_new[curr->random];
        curr = curr->next;
    }

    return old_to_new[head];
}


//Interweaving Nodes - solution
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    //interweaving nodes
    Node* curr = head;
    while (curr) {
        Node* new_node = new Node(curr->val);
        new_node->next = curr->next;
        curr->next = new_node;
        curr = new_node->next;
    }

    //connect the Randoms
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    //connect again the corresponding nodes 
    Node* old_head = head;
    Node* new_head = head->next;
    Node* curr_old = old_head;
    Node* curr_new = new_head;

    while (curr_old) {
        curr_old->next = curr_old->next->next;
        curr_new->next = curr_new->next ? curr_new->next->next : nullptr;
        curr_old = curr_old->next;
        curr_new = curr_new->next;
    }

    return new_head;
}

int main()
{
    
}

