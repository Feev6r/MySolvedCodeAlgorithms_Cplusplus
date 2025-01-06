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


//Soy malito, ¿sere bueno?

bool isBalanced(TreeNode* root) {
    if (!root)  return true;

    return (Height(root) != -1);
}

int Height(TreeNode* root) {

    if (!root) return 0;

    int leftHeight = Height(root->left);
    int rightHight = Height(root->right);

    if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)  return -1;

    return max(leftHeight, rightHight) + 1;
}


int main()
{
    std::cout << "Hello World!\n";
}
