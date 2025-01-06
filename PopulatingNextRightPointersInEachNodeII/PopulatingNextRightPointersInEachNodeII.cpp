#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

//iterative solution
Node* connect(Node* root) {
    if (!root) return nullptr;


    Node* levelStart = root;

    while (levelStart != nullptr) {
        Node* curr = levelStart;
        Node* dummy = new Node(); 
        Node* prev = dummy;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                prev->next = curr->left;
                prev = prev->next;
            }

            if (curr->right != nullptr) {
                prev->next = curr->right;
                prev = prev->next;
            }

            curr = curr->next;
        }

        levelStart = dummy->next; 
        delete dummy; 
    }

    return root;
}


//recursive solution
Node* connect(Node* root) {
    if (!root) return nullptr;


    if (root->left) {

        if (root->right) {
            root->left->next = root->right;
        }
        else {
            root->left->next = findNextNode(root->next);
        }
    }

    if (root->right) {
        root->right->next = findNextNode(root->next);
    }

    connect(root->right);
    connect(root->left);

    return root;
}

Node* findNextNode(Node* node) {
    while (node) {

        if (node->left) {
            return node->left;
        }
        if (node->right) {
            return node->right;
        }
        node = node->next;
    }
    return nullptr;
}

int main()
{
    std::cout << "Hello World!\n";
}
