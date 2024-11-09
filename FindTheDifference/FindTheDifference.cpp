#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

char findTheDifference(string s, string t) {

    map<char, int> mp, mp1;
    for (auto i : s) mp[i]++;
    for (auto j : t) mp1[j]++;
    char ans;
    for (auto i : mp1) {

        if (mp[i.first] != mp1[i.first]) {
            ans = i.first;
        }
    }
    return ans;

}

char findTheDifference2(string s, string t) {

    int freq_s[26] = { 0 };
    int freq_t[26] = { 0 };

    for (char c : s) freq_s[c - 'a']++;

    for (char c : t) if (++freq_t[c - 'a'] > freq_s[c - 'a']) return c;
    return 'a';
}



int main()
{
    findTheDifference("a", "aa");
}
