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

int res = INT_MIN;

int dfs(TreeNode* root) {
	if (!root) return 0;

	int l = max(dfs(root->left), 0);
	int r = max(dfs(root->right), 0);

	res = max(res, l + r + root->val);

	return (root->val) + max(l, r);
}

int maxPathSum(TreeNode* root) {
	dfs(root);
	return res;
}

int main()
{
    std::cout << "Hello World!\n";
}

