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

vector<vector<int>> levelOrderBottom(TreeNode* root) {

    if (!root) return {};

    vector <vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);


    while (!q.empty())
    {
        int n = q.size();
        vector<int> curLv;


        while (n--)
        {
            TreeNode* cur = q.front();
            q.pop();

            curLv.push_back(cur->val);

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        ans.push_back(curLv);
    }

    reverse(ans.begin(), ans.end());
    return ans;

}


int main()
{
    std::cout << "Hello World!\n";
}

