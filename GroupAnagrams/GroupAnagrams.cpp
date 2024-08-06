#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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

int main()
{
    std::cout << "Hello World!\n";
}

