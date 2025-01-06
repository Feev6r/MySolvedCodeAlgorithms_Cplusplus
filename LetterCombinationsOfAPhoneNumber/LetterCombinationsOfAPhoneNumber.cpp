#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
	unordered_map<char, string> mp = {
		{'2', "abc"},
		{'3' , "def"},
		{'4' , "ghi"},
		{'5' , "jkl"},
		{'6' , "mno"},
		{'7' , "pqrs"},
		{'8' , "tuv"},
		{'9' , "wxyz"}
	};

public:
	void solve(string& digits, int idx, string& curComb, vector<string>& comb) {

		if (idx >= digits.size()) {
			comb.push_back(curComb);
			return;
		}

		for (int i = 0; i < mp[digits[idx]].size(); i++)
		{
			curComb.push_back(mp[digits[idx]][i]);
			solve(digits, idx + 1, curComb, comb);
			curComb.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {

		if (digits.empty()) return {};

		vector<string> comb;
		string curComb;

		solve(digits, 0, curComb, comb);
		return comb;
	}
};

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
