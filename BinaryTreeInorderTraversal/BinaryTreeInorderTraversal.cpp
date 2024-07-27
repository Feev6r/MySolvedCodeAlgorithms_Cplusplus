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

//RECURSIVE INORDER TRAVERSAL
//--------------------------------------------------------

vector<int> inorderTraversal(TreeNode* root) {
    
    vector<int> nodes;
    inorder(root, nodes);
    return nodes;
}

void inorder(TreeNode* root, vector<int>& nodes) {
    
    if (!root) return;

    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}



//ITERATIVE VERSION MORRIS TRAVERSAL
//---------------------------------------------------------

vector<int> inorderTraversal(TreeNode* root) {

    vector<int> nodes;

    while (root) {

        if (root->left) {

            TreeNode* pre = root->left;
            while (pre->right && pre->right != root) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = root;
                root = root->left;
            }
            else {
                pre->right = NULL;
                nodes.push_back(root->val);
                root = root->right;
            }
        }
        else {
            nodes.push_back(root->val);
            root = root->right;
        }
    }
    return nodes;
}


int main()
{
    std::cout << "Hello World!\n";
}

