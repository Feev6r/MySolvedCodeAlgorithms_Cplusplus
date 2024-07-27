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

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return solution(root->left, root->right);
}

bool solution(TreeNode* left, TreeNode* right) {

    if (!left && right || !right && left) return false;

    if (!left && !right) return true;

    if (left->val != right->val) return false;

    return (solution(left->left, right->right)
        && solution(left->right, right->left));

}

//no se ni como funciono esto... JAJAJKSADKJSANIFJHNBA SE0IFDHSD0-  

int main()
{
    std::cout << "Hello World!\n";
}
