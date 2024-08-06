#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//recursion
TreeNode* invertTree(TreeNode* root) {
    // Base Case
    if (root == NULL)
        return NULL;

    invertTree(root->left); //Call the left substree
    invertTree(root->right); //Call the right substree
    // Swap the nodes
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root; // Return the root
}



//using stack
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    std::stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();

        // Swap the left and right children
        TreeNode* left = node->left;
        node->left = node->right;
        node->right = left;

        if (node->left != nullptr) {
            stack.push(node->left);
        }
        if (node->right != nullptr) {
            stack.push(node->right);
        }
    }

    return root;
}


//using queue "best"
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();

        // Swap the left and right children
        TreeNode* left = node->left;
        node->left = node->right;
        node->right = left;

        if (node->left != nullptr) {
            queue.push(node->left);
        }
        if (node->right != nullptr) {
            queue.push(node->right);
        }
    }

    return root;
}

int main()
{
    std::cout << "Hello World!\n";
}
