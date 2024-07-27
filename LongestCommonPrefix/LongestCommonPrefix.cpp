#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    if (strs.empty()) return "";

    string pref = strs[0];
    int prefLen = pref.length();

    for (int i = 1; i < strs.size(); i++) {

        string s = strs[i];
        while (prefLen > s.length() || pref != s.substr(0, prefLen)) {

            prefLen--;

            if (prefLen == 0) {
                return "";
            }
            pref = pref.substr(0, prefLen);
        }
    }

    return pref;
}

//O(strs[0].lenght * strs.length)
//O(strs[0].lenght * 1 (const))
//O(strs[0].lenght)

int main()
{
    vector<string> v = { "dog","racecar","car" };
    cout << longestCommonPrefix(v);
}