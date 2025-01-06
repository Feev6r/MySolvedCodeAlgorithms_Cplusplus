#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


void solve(TreeNode* root, int sum, int& totalSum) {

    sum += root->val;
    sum *= 10;

    if (!root->left && !root->right) {
        totalSum += sum;
        return;
    }

    solve(root->left, sum, totalSum);
    solve(root->right, sum, totalSum);

}

int sumNumbers(TreeNode* root) {

    int totalSum = 0;
    solve(root, 0, totalSum);
    return totalSum;

}

int main()
{
    std::cout << "Hello World!\n";
}

