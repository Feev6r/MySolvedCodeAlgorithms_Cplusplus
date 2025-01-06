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

class BSTIterator {

    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {

		TreeNode* runner = root;
		while (runner)
		{
			st.push(runner);
			runner = runner->left;
		}
    }

    int next() {

		TreeNode* runner = st.top()->right;
		int temp = st.top()->val;
		st.pop();

		while (runner) {
			st.push(runner);
			runner = runner->left;
		}

		return temp;
    }

    bool hasNext() {

		return !st.empty();
    }
};

class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }

    void partialInorder(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

