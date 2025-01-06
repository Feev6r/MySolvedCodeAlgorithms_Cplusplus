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

class Solution {
public:
	vector<vector<int>> ans;

	void dfs(TreeNode* root, vector<int>& curNums, int targetSum) {

		if (!root) return;
		if (!root->left && !root->right && targetSum == root->val) {
			curNums.push_back(root->val);
			ans.push_back(curNums);
			curNums.pop_back();
			return;
		}

		curNums.push_back(root->val);

		dfs(root->left, curNums, targetSum - root->val);
		dfs(root->right, curNums, targetSum - root->val);

		curNums.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> path;
		dfs(root, path, targetSum);
		return ans;

	}
};

int main()
{
    std::cout << "Hello World!\n";
}

