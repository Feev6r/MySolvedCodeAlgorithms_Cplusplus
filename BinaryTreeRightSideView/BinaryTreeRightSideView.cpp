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

vector<int> rightSideView(TreeNode* root) {

	if (!root) return {};

	queue<TreeNode*> q;
	q.push(root);
	vector<int> ans;


	while (!q.empty())
	{
		int n = q.size();
		TreeNode* cur;

		while (n--)
		{
			cur = q.front(); q.pop();

			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}

		ans.push_back(cur->val);
	}

	return ans;
}


int main()
{
    std::cout << "Hello World!\n";
}

