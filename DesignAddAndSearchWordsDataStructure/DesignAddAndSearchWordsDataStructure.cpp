#include <iostream>
#include <unordered_map>

using namespace std;


//MY SOLUTION - CORRECTED BY CLOUDE
class WordDictionary {
private:
    struct TrieNode {
        bool isEnd;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEnd(false) {}
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char ch : word) {

            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool searchHelper(TrieNode* node, const string& word, int index) {
        if (index == word.length()) {
            return node->isEnd;
        }

        if (word[index] == '.') {

            for (auto& pair : node->children) {
                if (searchHelper(pair.second, word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
        else {
            if (node->children.find(word[index]) == node->children.end()) {
                return false;
            }
            return searchHelper(node->children[word[index]], word, index + 1);
        }
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};


//EFFICIENT SOLUTION

class WordDictionary {
private:
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
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char c : word) {

            int index = c - 'a';

            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return searchInNode(word, root, 0);
    }

private:
    bool searchInNode(const string& word, TrieNode* node, int pos) {
        if (!node) return false;

        if (pos == word.length()) return node->isEnd;

        if (word[pos] != '.') {
            return searchInNode(word, node->children[word[pos] - 'a'], pos + 1);
        }

        // Si es un punto, probamos todas las letras posibles
        for (int i = 0; i < 26; i++) {
            if (searchInNode(word, node->children[i], pos + 1)) {
                return true;
            }
        }
        return false;
    }
};