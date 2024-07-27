#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> solve(string target, vector<string> wordBank,
	unordered_map<string, vector<vector<string>>>& memo) {


	if (target == "") return { {} };
	if (memo.count(target)) return memo[target];

	vector<vector<string>> result;

	for (string word : wordBank)
	{
		if (target.find(word) == 0) {
			const string suffix = target.substr(word.length());
			vector<vector<string>> suffixWays = solve(suffix, wordBank, memo);

			for (vector<string>& subvector : suffixWays) {

				// Insertamos el dato al frente de cada subvector				
				subvector.insert(subvector.begin(), word);
				result.push_back(subvector);
			}

		}
	}

	memo[target] = result;
	return result;

}

vector<vector<string>> allConstruct(string target, vector<string> wordBank) {

	unordered_map<string, vector<vector<string>>> memo;
	return solve(target, wordBank, memo);

}


void printResult(const std::vector<std::vector<std::string>>& result) {
	for (const auto& combination : result) {
		std::cout << "[-";
		for (const auto& word : combination) {
			std::cout << word << "-";
		}
		std::cout << "]\n";
	}
}


int main()
{

	std::vector<std::vector<std::string>> result1 = allConstruct("purple", { "purp", "p", "ur", "le", "purpl" });
	/*std::vector<std::vector<std::string>> result4 = */allConstruct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa", { "a", "aa", "aaa", "aaaa", "aaaaa" });

	printResult(result1);
	//printResult(result4);
}

