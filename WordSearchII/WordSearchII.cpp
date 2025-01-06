#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {

    TrieNode* children[26] = {};
    string* word;

    void addWord(string& word) {
        TrieNode* cur = this;

        for (char ch : word) {

            ch -= 'a';
            if (!cur->children[ch]) cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }

        cur->word = &word;
    }
};

class Solution {
public:
    int m, n;
    vector<string> ans;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        m = board.size(); 
        n = board[0].size();
        TrieNode trieNode;

        for (string& word : words) trieNode.addWord(word);

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dfs(board, r, c, &trieNode);
            }       
        }

        return ans;
    }
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur) {

        if (r < 0 || r == m || c < 0 || c == n || board[r][c] == '#' || !cur->children[board[r][c] - 'a']) return;
       
        char orgChar = board[r][c];
       
        cur = cur->children[orgChar - 'a'];

        if (cur->word) {
            ans.push_back(*cur->word);
            cur->word = nullptr; // Avoid duplication!
        }

        board[r][c] = '#'; // mark as visited!

        dfs(board, r, c + 1, cur);
        dfs(board, r, c - 1, cur);
        dfs(board, r + 1, c, cur);
        dfs(board, r - 1, c, cur);

        board[r][c] = orgChar; // restore org state
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

