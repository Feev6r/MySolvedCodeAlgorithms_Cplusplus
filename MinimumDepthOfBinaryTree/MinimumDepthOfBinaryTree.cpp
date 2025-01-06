#include <iostream>
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

//solution
int preorder(TreeNode* curr) {

    if (curr == nullptr) return INT_MAX;
    if (!curr->left && !curr->right) return 1;
    
    return min(preorder(curr->left),
               preorder(curr->right)) + 1;

}

int minDepth(TreeNode* curr) {
    return preorder(curr) == INT_MAX ? 0 : preorder(curr);
}


//queue solution
int minDepth(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int depth = 1;
    
    while (!q.empty()) {
        
        int n = q.size();
        while (n--) {

            TreeNode* node = q.front();
            q.pop();

            if (!node->left && !node->right) return depth;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        depth++;
    
    }

    return depth;
}


int main()
{
    std::cout << "Hello World!\n";
}

