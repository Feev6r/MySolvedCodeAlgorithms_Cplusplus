#include <iostream>
#include <vector>

using namespace std;

class Trie {

    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;
public:

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {

        TrieNode* node = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isEnd = true;
    }

    bool search(string word) {

        TrieNode* node = root;

        for (char ch : word) {

            if (!node->children[ch - 'a']) {
                return false;
            }
            node = node->children[ch - 'a'];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (char c : prefix) {
            if (!temp->children[c - 'a']) {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return true;
    }
};



int main()
{
    std::cout << "Hello World!\n";
}
