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


vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        int n = q.size();
        vector<int> crtLevel;

        for (int i = 0; i < n; i++) {

            TreeNode* p = q.front(); q.pop();

            crtLevel.push_back(p->val);

            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }

        result.push_back(crtLevel);
    }

    return result;
}


void breadthFirstTraversal(TreeNode* root) {

    queue<TreeNode*> queue;
    queue.push(root);


    while (!queue.empty()) {
        const TreeNode* curr = queue.front();
        
        queue.pop();
        cout << curr->val;

        if (curr->left) {
            queue.push(curr->left);
        }
        if (curr->right) {
            queue.push(curr->right);
        }
    }

}

//[ 3, [2, 5] ]

int main()
{
    TreeNode* nodeEj = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    breadthFirstTraversal(nodeEj);


}
