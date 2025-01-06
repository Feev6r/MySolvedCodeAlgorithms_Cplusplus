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


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    if (!root) return {};

    vector<vector<int>>ans;
    queue<TreeNode*>q;

    q.push(root);
    bool flag = 1;

    while (!q.empty()) {

        int n = q.size();
        vector<int>v(n); //level order traversal fs

        for (int i = 0; i < n; i++) {

            TreeNode* temp = q.front(); q.pop();

            int idx = (flag) ? i : n - i - 1;

            v[idx] = temp->val;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        ans.push_back(v);
        flag = !flag;
    }
    return ans;
}


int main()
{
    std::cout << "Hello World!\n";
}

