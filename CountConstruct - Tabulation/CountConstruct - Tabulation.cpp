#include <iostream>
#include <vector>

using namespace std;

int countConstruct(string target, vector<string> wordBank) {
	vector<int> table(target.length() + 1, 0);
	table[0] = 1;


	for (int i = 0; i < target.length(); i++)
	{
		for (string word : wordBank) {

			if (target.substr(i, i + word.length()) == word) {
				table[i + word.length()] += table[i];
			}
		}

	}
	
	return table[target.length()];
}


int main()
{
	cout << boolalpha << countConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd" }) << std::endl;
	cout << boolalpha << countConstruct("skateboard", { "bo","rd","ate","t", "ska", "sk","boar" }) << std::endl;
	cout << boolalpha << countConstruct("purple", { "purp", "p", "ur", "le", "purpl" }) << endl;
	cout << boolalpha << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", { "ee","eee", "eeee","eeeee","eeeeee" }) << std::endl;
}

