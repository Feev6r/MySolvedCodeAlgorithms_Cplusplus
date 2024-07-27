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



TreeNode* solution(int start, int end, vector<int> nums) {

    if (nums.empty()) return nullptr;

    int mid = nums.size() / 2;

    solution(mid, end, nums);
    solution(0, mid, nums);
}

TreeNode* sortedArrayToBST2(vector<int>& nums) {


    int start = 0;
    int end = nums.size();

    int mid = (start + end) / 2;

    TreeNode* node = new TreeNode(nums[mid]);

    solution(mid, end, nums);
    solution(0, mid, nums);


    return nullptr;
}

TreeNode* sortedArrayToBST(vector<int>& num) {

    if (num.size() == 0) return NULL;

    if (num.size() == 1) return new TreeNode(num[0]);


    int middle = num.size() / 2;
    TreeNode* root = new TreeNode(num[middle]);

    vector<int> leftInts(num.begin(), num.begin() + middle);
    vector<int> rightInts(num.begin() + middle + 1, num.end());

    root->left = sortedArrayToBST(leftInts);
    root->right = sortedArrayToBST(rightInts);

    return root;
}

int main()
{
    vector<int> v = { 1,2,3,4,5 };
    sortedArrayToBST(v);
}

