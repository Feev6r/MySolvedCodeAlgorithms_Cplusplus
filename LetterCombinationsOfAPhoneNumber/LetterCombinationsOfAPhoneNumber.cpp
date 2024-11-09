#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void backtrack(string combination, string next_digits, string phone_map[], vector<string>& output) {
    
    if (next_digits.empty()) {
        output.push_back(combination);
    
    }
    else {
        string letters = phone_map[next_digits[0] - '2'];
        for (char letter : letters) {
            backtrack(combination + letter, next_digits.substr(1), phone_map, output);
        }
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    string phone_map[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    vector<string> output;

    backtrack("", digits, phone_map, output);
    
    return output;
}

int main()
{
    std::cout << "Hello World!\n";
}
