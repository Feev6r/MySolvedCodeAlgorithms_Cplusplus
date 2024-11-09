#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//RECURSIVE + MEMO - MY SOLUTION
bool solve(string s, vector<string>& wordDict, unordered_map<string, bool>& memo) {

    if (memo.find(s) != memo.end()) return memo[s];
	if (s.empty()) return true;

	for (string& w : wordDict) {

		if (s.substr(0, w.size()) == w) {
            if (solve(s.substr(w.size()), wordDict, memo)) {
                memo[s] = true;
                return memo[s];
            }
		}
	}

    memo[s] = false;
	return memo[s];
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, bool> memo;
    return solve(s, wordDict, memo);
}


//DP SOLUTION
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);

    dp[0] = true;
    
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    
    for (int i = 1; i <= s.length(); i++) {
        for (auto& w : wordDict) {
    
            int x = i - w.length();
            
            if (x >= 0 && (dp[x]) && (s.substr(x, w.length()) == w)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];

}

int main()
{

}


//class Trie {
//public:
//    bool is_end;
//    unordered_map<char, Trie*> children;
//    
//    Trie() : is_end(false) {}
//
//    void insert(const string& word) {
//
//        Trie* node = this;
//
//        for (char ch : word) {
//
//            if (node->children.find(ch) == node->children.end()) {
//
//                node->children[ch] = new Trie();
//            }
//
//            node = node->children[ch];
//        }
//
//        node->is_end = true;
//    }
//
//    bool search(Trie* root, const string& word) {
//
//        Trie* node = root;
//        bool itWasEnd;
//        for (char ch : word) {
//
//            itWasEnd = false;
//
//            if (node->children.find(ch) == node->children.end()) {
//                return false;        
//            }
//
//            if (node->children[ch]->is_end) {
//            
//                itWasEnd = true; 
//                node = root;
//            } 
//            else node = node->children[ch];    
//        }
//
//        return itWasEnd;
//    }
//
//};

//bool wordBreak(string s, vector<string>& wordDict) {
//
//    Trie* node = new Trie();
//    for (string word : wordDict) {
//        node->insert(word);
//    }
//
//    return node->search(node ,s);
//}