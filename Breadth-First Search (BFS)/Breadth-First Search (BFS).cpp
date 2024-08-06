#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left) : val(x), left(left), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//PREORDER TRAVERSAL
//--------------------------------------------------------------
void preorder(TreeNode* root) {

    if (root == nullptr) return;
    
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);

}


//INORDER TRAVERSAL
//--------------------------------------------------------------
void inorder(TreeNode* root) {

    if (root == nullptr) return;

    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);

}


//POSORDER TRAVERSAL
//--------------------------------------------------------------
void posorder(TreeNode* root) {

    if (root == nullptr) return;

    posorder(root->left);
    posorder(root->right);
    cout << root->val << endl;

}


int main()
{

    TreeNode* node = new TreeNode(1, new TreeNode(2, new TreeNode(4)), new TreeNode(3, new TreeNode(5)));

    preorder(node); //1
    inorder(node);  //2
    posorder(node); //3

}

