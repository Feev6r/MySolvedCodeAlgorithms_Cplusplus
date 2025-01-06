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
	int ans;

	int kthSmallest(TreeNode* root, int k) {
		solve(root, k);
		return ans;
	}

	void solve(TreeNode* root, int& k) {

		if (!root) return;

		solve(root->left, k);

		if (k-- == 0) {
			ans = root->val;
			return;
		}

		solve(root->right, k);

	}

};


//binary search

int helper(TreeNode* root) {
	if (root == nullptr) return 0;
	return 1 + helper(root->left) + helper(root->right);
}


int kthSmallest(TreeNode* root, int k) {
	int counter = helper(root->left);

	if (k <= counter) {
		return kthSmallest(root->left, k);
	}
	else if (k > counter + 1) {
		return kthSmallest(root->right, k - 1 - counter);
	}
	return root->val;
}


int main()
{
	std::cout << "Hello World!\n";
}
