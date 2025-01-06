#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


void solve(TreeNode* root, vector<string>& ans, string str) {
	if (!root) return;
	if (!root->left && !root->right) {
		str += to_string(root->val);
		ans.push_back(str);
		return;
	}

	str += to_string(root->val) + "->";

	solve(root->left, ans, str);
	solve(root->right, ans, str);
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> ans;
	solve(root, ans, "");
	return ans;
}

int main()
{
    std::cout << "Hello World!\n";
}

