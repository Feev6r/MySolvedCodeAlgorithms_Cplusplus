#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    struct Node {

        int val, min;
        Node* next;
        Node(int _val, int _min, Node* _next = NULL) {
            val = _val;
            min = _min;
            next = _next;
        }

    }
    *head;
    
    void push(int val) {
        if (!head) {
            head = new Node(val, val);
        }
        else {
            head = new Node(val, min(val, head->min), head);
        }
    }

    void pop() {
        if (!head) return;
        head = head->next;
    }

    int top() {
        if (!head) return -1;
        return head->val;
    }

    int getMin() {
        if (!head) return -1;
        return head->min;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}