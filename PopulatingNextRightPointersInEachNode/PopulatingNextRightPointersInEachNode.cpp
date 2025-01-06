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

//My Solution :D
Node* connect(Node* root) {

    if (!root) return nullptr;

    if (root->left && root->right) {
        root->left->next = root->right;

        if (root->next) {
            root->right->next = root->next->left;
        }
    }

    connect(root->left);
    connect(root->right);
    return root;
}

//iterative solution
Node* connect(Node* root) {

    Node* prev = root, * curr;

    while (prev) {
        curr = prev;

        while (curr && curr->left) {
            //connects the left subtree of same level with right subtree of that same level 
            curr->left->next = curr->right;
            //connect the rightmost node of a level to the leftmost node of the next level.
            if (curr->next) curr->right->next = curr->next->left;
            curr = curr->next;
        }
        prev = prev->left;
    }
    return root;
}

int main()
{
    std::cout << "Hello World!\n";
}
