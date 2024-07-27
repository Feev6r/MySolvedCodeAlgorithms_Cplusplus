#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> allConstruct(string target, vector<string> wordBank) {

    vector<vector<vector<string>>> table(target.length() + 1, vector<vector<string>>());

    table[0] = { {} };

    for (int i = 0; i < target.length(); i++)
    {
        for (string word : wordBank) {

            if (target.substr(i, word.length()) == word) {

                vector<vector<string>> newCombinations = table[i];

                for (auto& subvector : newCombinations)
                {
                    subvector.push_back(word);
                    table[i + word.length()].push_back(subvector);

                }
            }

        }
    }

    return table[target.length()].empty() ? vector<vector<string>>() : table[target.length()];
     
}


void printResult(const vector<vector<string>>& result) {
    for (const auto& combination : result) {
        cout << "[-";
        for (const auto& word : combination) {
            std::cout << word << "-";
        }
        cout << "]\n";
    }
}

int main()
{
    vector<vector<string>> result1 = allConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd", "ef", "c"});
    vector<vector<string>> result2 = allConstruct("skateboard", { "bo","rd","ate","t", "ska", "sk","boar" });
    vector<vector<string>> result3 = allConstruct("purple", { "purp", "p", "ur", "le", "purpl" });
    //vector<vector<string>> result4 = allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", { "ee","eee", "eeee","eeeee","eeeeee" });

    //printResult(result3);
}

