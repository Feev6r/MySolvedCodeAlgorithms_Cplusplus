#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//este algoritmo me saca de quicio :L

int height(TreeNode* root) {
	return (!root) ? -1 : 1 + height(root->left);
}
int countNodes(TreeNode* root) {
	int h = height(root);

	return h < 0 ? 0 : 

		height(root->right) == h - 1 ? (1 << h) + countNodes(root->right) 
								 : (1 << h - 1) + countNodes(root->left);
}



int height(TreeNode* root) {
	return (!root) ? -1 : 1 + height(root->left);
}

int countNodes(TreeNode* root) {
	int nodes = 0;
	int h = height(root);

	while (root != nullptr) {
		if (height(root->right) == h - 1) {
			nodes += 1 << h;
			root = root->right;
		}
		else {
			nodes += 1 << (h - 1);
			root = root->left;
		}
		h--;
	}

	return nodes;
}

int main()
{
	std::cout << "Hello World!\n";
}

