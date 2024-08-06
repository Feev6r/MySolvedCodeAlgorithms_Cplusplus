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

int f(TreeNode* curr) {

    if (curr == nullptr) return INT_MAX;
    if (curr->left == nullptr and curr->right == nullptr) return 1;
    return min(f(curr->left), f(curr->right)) + 1;

}
int minDepth(TreeNode* curr) {
    int ans = f(curr);
    return ans == INT_MAX ? 0 : ans;
}



int main()
{
    std::cout << "Hello World!\n";
}

