#include <iostream>
#include <vector>

using namespace std;

bool canConstruct(string target, vector<string> worBank) {

    vector<bool> table(target.length() + 1, false);
    table[0] = true;

    for (int i = 0; i < target.length(); i++)
    {
        if (table[i] == true) {
            for (string word : worBank)
            {
                if (target.substr(i, i + word.length()) == word) {
                    table[i + word.length()] = true;
                }
            }
        }
    }

    return table[target.length()];
}


int main()
{
    std::cout << std::boolalpha << canConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd" }) << std::endl;
    std::cout << std::boolalpha << canConstruct("skateboard", { "bo","rd","ate","t", "ska", "sk","boar" }) << std::endl;
    std::cout << std::boolalpha << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", { "ee","eee", "eeee","eeeee","eeeeee" }) << std::endl;
}
