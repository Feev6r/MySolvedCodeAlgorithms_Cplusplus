#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {

	if (s.length() != t.length()) return false;

	vector<int> v(28, 0);

	for (char& c : s) v[c - 'a']++;

	for (char& c : t) {
		if (v[c - 'a'] == 0) return false;

		v[c - 'a']--;
	}

	return true;
}

int main()
{
	cout << isAnagram("anagram", "nagaram");
}
//
//int x = s[0] ^ t[0];
//for (int i = 1; i < s.length(); i++)
//{
//	x = s[i] ^ t[i];
//}
//
//if (x) return false;
//
//return true;