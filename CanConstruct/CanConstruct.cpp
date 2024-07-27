#include <iostream>
#include <vector>
#include <unordered_map>

bool solve(std::string target, std::vector<std::string>& wordBank, std::unordered_map<std::string, bool>& memo) {

	if (target == "") return true;
	if (memo.count(target)) return memo[target];
	
	for (std::string word : wordBank)
	{
		if (target.find(word) == 0) {

			const std::string suffix = target.substr(word.length());

			
			if (solve(suffix, wordBank, memo) == true) {
				memo[target] = true;
				return true;
			}
			
		}
	}

	memo[target] = false;
	return false;
}


bool canConstruct(std::string target, std::vector<std::string> wordBank) {

	std::unordered_map<std::string, bool> memo;

	return solve(target, wordBank, memo);
}



int main()
{
	std::cout << std::boolalpha << canConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd" }) << std::endl;
	std::cout << std::boolalpha << canConstruct("skateboard", { "bo","rd","ate","t", "ska", "sk","boar" }) << std::endl;
	std::cout << std::boolalpha << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ee","eee", "eeee","eeeee","eeeeee" }) << std::endl;

}


