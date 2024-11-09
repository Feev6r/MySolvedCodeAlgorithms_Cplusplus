#include <iostream>
#include <vector>
#include <unordered_map>
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

//    TreeNode* nodeEj = new TreeNode(1, new TreeNode(2), new TreeNode(3));


void mergeSort(vector<int>& arr, int left, int right) {

    if (arr.size() <= 0) return;


}



int main() {


}

