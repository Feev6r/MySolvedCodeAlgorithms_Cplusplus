#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>


using namespace std;

class Trie {
public:
    bool is_end;  // Indicates if the current node marks the end of a word
    unordered_map<char, Trie*> children;  // Hash table to store child nodes

    Trie() : is_end(false) {}


    // Insert a word into the trie
    void insert(const string& word) {

        Trie* node = this;

        for (char ch : word) {

            if (node->children.find(ch) == node->children.end()) {

                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->is_end = true;
    }



    // Search for a word in the trie
    bool search(const string& word) {

        Trie* node = this;

        for (char ch : word) {

            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->is_end;
    }

    // Delete a word from the trie
    bool delete_word(const string& word, int depth = 0) {
        // If we reached the end of the word
        if (depth == word.size()) {
            if (!is_end) {
                return false;  // Word not found
            }
            is_end = false;  // Unmark the end of the word
            return children.empty();  // Return true if no children, allowing pruning
        }

        char ch = word[depth];
        if (children.find(ch) == children.end()) {
            return false;  // Word not found
        }

        // Recursively delete from the child node
        bool should_delete_current_node = children[ch]->delete_word(word, depth + 1);

        if (should_delete_current_node) {
            delete children[ch];  // Free the memory
            children.erase(ch);   // Remove the child node

            // Return true if no children and not the end of another word
            return children.empty() && !is_end;
        }

        return false;
    }

    // Get all words in the trie
    void get_all_words(string prefix, vector<string>& words) {
        if (is_end) {
            words.push_back(prefix);  // If at the end of a word, add it to the list
        }

        // Recursively get words from each child node
        for (const auto& child : children) {
            child.second->get_all_words(prefix + child.first, words);
        }
    }
};

int main() {
    Trie trie;

    // Insert words
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");
    trie.insert("cart");

    // Search for words
    std::cout << "Search results:\n";
    std::cout << "cat: " << (trie.search("cat") ? "Found" : "Not found") << '\n';
    std::cout << "dog: " << (trie.search("dog") ? "Found" : "Not found") << '\n';
    std::cout << "cow: " << (trie.search("cow") ? "Found" : "Not found") << '\n';

    // Delete a word
    trie.delete_word("car");
    std::cout << "\nAfter deleting 'car':\n";
    std::cout << "car: " << (trie.search("car") ? "Found" : "Not found") << '\n';
    std::cout << "cart: " << (trie.search("cart") ? "Found" : "Not found") << '\n';

    // Get all words
    std::vector<std::string> words;
    trie.get_all_words("", words);
    std::cout << "\nAll words in the trie:\n";
    for (const std::string& word : words) {
        std::cout << word << '\n';
    }

    return 0;
}
