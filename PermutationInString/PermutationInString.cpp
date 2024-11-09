#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


bool checkInclusion(string s1, string s2) {

    if (s1.size() > s2.size()) return false;

    vector<int> s1v(26, 0);
    int n = s1.size();
    int founded = 0;
    int start = 0;

    for (auto& c : s1) s1v[c - 'a']++;

    for (int end = 0; end < s2.size(); end++)
    {

        if (s1v[s2[end] - 'a'] > 0) {
            founded++;
            s1v[s2[end] - 'a']--;
        }
        else if (s1v[s2[end] - 'a'] == 0 && founded != 0) {

            s1v[s2[end] - 'a']--;            
            start = end - founded;

            while(s1v[s2[end] - 'a'] == -1) {
                s1v[s2[start] - 'a']++;
                start++;
            }

            founded = end - start + 1;
        }
     
        if (founded == n) return true;
    }

    return false;
}

bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int>mp, mp2;
    for (auto ch : s1) mp2[ch]++;

    int i = 0, j = 0, k = s1.size(), n = s2.size();
    while (j < n)
    {
        mp[s2[j++]]++;
        if (j - i == k)
        {
            if (mp == mp2) return true;

            mp[s2[i]]--;
            if (mp[s2[i]] == 0) mp.erase(s2[i]);
            i++;
        }
    }
    return false;
}

int main()
{
    checkInclusion("ky", "wkckifykxlribaypk");
}

