#include <iostream>
#include <stack>


using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//recursion
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root) revPreOrder(root);
	}
private:
	TreeNode* head = nullptr;
	void revPreOrder(TreeNode* node) {
		if (node->right) revPreOrder(node->right);
		if (node->left) revPreOrder(node->left);

		node->left = nullptr;
		node->right = head; 
		head = node;
	}
};

//Morris traversal
void flatten(TreeNode* root) {
	TreeNode* curr = root;

	while (curr) {
	
		if (curr->left) {
		
			TreeNode* runner = curr->left;
			while (runner->right) runner = runner->right;
			
			runner->right = curr->right; 
			curr->right = curr->left; 
			curr->left = nullptr;
		}

		curr = curr->right;
	}
}

int main()
{

	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n6 = new TreeNode(6);

	TreeNode* n5 = new TreeNode(5, nullptr, n6);

	TreeNode* n2 = new TreeNode(2, n3, n4);

	TreeNode* n1 = new TreeNode(1, n2, n5);

	flatten(n1);
}

