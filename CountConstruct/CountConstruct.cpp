#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(string target, vector<string> wordBank, unordered_map<string, int>& memo) {

    if (target == "") return 1;
	if (memo.count(target)) return memo[target];

	int totalCount = 0;


	for (string word : wordBank)
	{
		if (target.find(word) == 0) {

			const int numWaysForRest = solve(target.substr(word.length()), wordBank, memo);
			
			totalCount += numWaysForRest;
		}

	}

	memo[target] = totalCount;
	return totalCount;

}

int countConstruct(string target, vector<string> wordBank) {

	unordered_map<string, int> memo;

	return solve(target, wordBank, memo);

}


int main()
{
	vector<string> a = { "ab", "abc", "cd", "def", "abcd" };
	cout << countConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd" }) << endl;
	cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", { "ee","eee", "eeee","eeeee","eeeeee" }) << endl;


}

