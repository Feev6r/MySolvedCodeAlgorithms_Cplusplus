#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {

private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;

public:
    void recoverTree(TreeNode* root) {

        traverse(root);

        // Swap the values
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }

    void traverse(TreeNode* root) {
        if (!root) return;


        traverse(root->left);

        if (prev && !first && prev->val >= root->val) {
            first = prev;
        }

        if (first && prev->val >= root->val) {
            second = root;
        }

        prev = root;


        traverse(root->right);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
