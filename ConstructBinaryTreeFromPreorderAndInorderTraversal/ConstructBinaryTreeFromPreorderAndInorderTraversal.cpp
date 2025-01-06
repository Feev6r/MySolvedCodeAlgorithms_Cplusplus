#include <iostream>
#include <vector>
#include <unordered_map>

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

private:
    int preorderIndex;
    unordered_map<int, int> mp;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int pivot = mp[rootVal];

        root->left = build(preorder, start, pivot - 1);
        root->right = build(preorder, pivot + 1, end);

        return root;
    }
};



//[2,9,3,15,20,7]

int main()
{
    Solution a;

    vector<int> v1 = { 9,3,15,20,7 };
    vector<int> v2 = { 9,15,7,20,3 };

    a.buildTree(v1,v2);
}
