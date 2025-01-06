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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	if (!root) return nullptr;

	if (p->val < root->val && q->val < root->val) {
		return lowestCommonAncestor(root->left, p, q);
	}
	else if (p->val > root->val && q->val > root->val) {
		return lowestCommonAncestor(root->right, p, q);
	}

	return root;

}

int main()
{
    std::cout << "Hello World!\n";
}
