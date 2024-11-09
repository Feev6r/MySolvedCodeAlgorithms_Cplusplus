#include <iostream>
#include <vector>
#include <unordered_map>

class Trie1 {
public:
    bool is_end;  // Indicates if the current node marks the end of a word
    vector<Trie1*> children;  // Vector to store pointers to child nodes

    Trie1(int k) : is_end(false), children(k, nullptr) {
        // Constructor initializes the children vector with 'k' nullptr elements
    }
};

class Trie2 {
public:
    bool is_end;  // Indicates if the current node marks the end of a word
    unordered_map<std::string, Trie2*> children;  // Map storing children nodes, keyed by string

    Trie2() : is_end(false) {
        // Constructor initializes an empty map for children
    }
};

class Trie3 {
public:
    bool is_end;  // Indicates if the current node marks the end of a word
    vector<Trie3*> children;  // Vector storing pointers to child nodes

    Trie3() : is_end(false) {
        // Constructor initializes an empty vector for children
    }
};

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

