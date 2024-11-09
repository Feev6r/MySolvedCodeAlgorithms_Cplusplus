#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

	unordered_map<string, vector<string>> map;

	for (auto& str : strs){

		string word = str;
		sort(word.begin(), word.end());
		map[word].push_back(str);

	}

	vector<vector<string>> ans;
	for (const auto& pair : map) {
		ans.push_back(pair.second);
	}

	return ans;
}

vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    unordered_map<string, vector<string>> ans;

    for (string& s : strs) {
        array<int, 26> count = { 0 };

        // Count frequency of each letter in the string
        for (char c : s) {
            count[c - 'a']++;
        }

        string key;
        for (int num : count) {
            key += to_string(num) + "#";
        }

        ans[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& entry : ans) {
        result.push_back(move(entry.second));
    }

    return result;
}

int main()
{
    std::cout << "Hello World!\n";
}

