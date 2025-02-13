#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};




bool isValidBST2(TreeNode* root) {
    return isValid(root, NULL, NULL);
}

bool isValid(TreeNode* root, int* lower, int* upper) {

    if (!root) return true;

    if (upper && root->val >= *upper) return false;
    if (lower && root->val <= *lower) return false;

    return isValid(root->left, lower, &(root->val)) 
        && isValid(root->right, &(root->val), upper);
}



//--------------------------------------------------
//--------------------------------------------------



bool isValidBST3(TreeNode* root) {

    TreeNode* prev = nullptr;
    return validate(root, prev);
}

bool validate(TreeNode* node, TreeNode* &prev) {

    if (!node) return true;

    if (!validate(node->left, prev)) return false;
    
    if (prev && prev->val >= node->val) return false;

    prev = node;

    return validate(node->right, prev);
}




int main()
{
    std::cout << "Hello World!\n";
}
