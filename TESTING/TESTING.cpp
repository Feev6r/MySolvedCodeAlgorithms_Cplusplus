#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype> 
#include <string>
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

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

void addEdge(vector<vector<int>>& adj, int s, int t) {
	adj[s].push_back(t);
	adj[t].push_back(s);
}

void DFSRec(vector<vector<int>>& adj, vector<bool>& visited, int s) {

	visited[s] = true;

	// Print the current vertex
	cout << s << " ";

	// Recursively visit all adjacent vertices
	// that are not visited yet
	for (int i : adj[s]) {
		if (visited[i] == false) {
			DFSRec(adj, visited, i);
		}
	}

}

// Main DFS function that initializes the visited array
// and call DFSRec
void DFS(vector<vector<int>>& adj, int s) {
	vector<bool> visited(adj.size(), false);
	DFSRec(adj, visited, s);
}


bool inorder(TreeNode* root, int lastValue) {

	if (!root) return true;

	inorder(root->left, root->val);

	if (root->val > lastValue) return false;

	inorder(root->right, root->val);

}




void main() {


	cout << 4 % 3;

}

