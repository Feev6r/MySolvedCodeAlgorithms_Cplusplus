#include <iostream>
#include <vector>
#include <queue>


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
void inOrder(TreeNode* root) {

    if (root == nullptr) return;

    inOrder(root->left);
    cout << root->val << endl;
    inOrder(root->right);

}


//POSORDER TRAVERSAL
//--------------------------------------------------------------
void posOrder(TreeNode* root) {

    if (root == nullptr) return;

    posOrder(root->left);
    posOrder(root->right);
    cout << root->val << endl;

}



//BREADTH FIRST TRAVERSAL
//--------------------------------------------------------------
void breadthFirstTraversal(TreeNode* root) {

    queue<TreeNode*> queue;
    queue.push(root);


    while (!queue.empty()) {
        const TreeNode* curr = queue.front();
        queue.pop();
        cout << curr->val;

        if (curr->left) {
            queue.push(curr->left);
        }
        if (curr->right) {
            queue.push(curr->right);
        }
    }

}



//LEVEL ORDER TRAVERSAL
//--------------------------------------------------------------
vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        int n = q.size();
        vector<int> crtLevel;

        for (int i = 0; i < n; i++) {

            TreeNode* p = q.front(); q.pop();

            crtLevel.push_back(p->val);

            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }

        result.push_back(crtLevel);
    }

    return result;
}



//DEPTH FIRST SEARCH
//--------------------------------------------------------------

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


//--------------------------------------------------------------


int main()
{

    TreeNode* node = new TreeNode(1, new TreeNode(2, new TreeNode(4)), new TreeNode(3, new TreeNode(5)));

    preorder(node); //1
    inOrder(node);  //2
    posOrder(node); //3


    //---------------------------------------------------------------------------------------------


    int V = 5;
    vector<vector<int>> adj(V);

    // Add edges
    vector<vector<int>> edges = { {1, 2},{1, 0},{2, 0},{2, 3},{2, 4} };
    for (auto& e : edges)
        addEdge(adj, e[0], e[1]);

    int s = 1; // Starting vertex for DFS
    cout << "DFS from source: " << s << endl;
    DFS(adj, s); // Perform DFS starting from the source vertex
}

