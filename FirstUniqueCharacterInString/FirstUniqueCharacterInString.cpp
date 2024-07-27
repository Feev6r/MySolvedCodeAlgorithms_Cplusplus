#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>

using namespace std;

//my ineficient solution but it is honest work ma vrotha
int firstUniqChar2(string s) {

	unordered_map<char, pair<int, int>> m;

	for (int i = 0; i < s.length(); i++) {

		m[s[i]].first++;
		m[s[i]].second = i;
	}

	for (auto& c : s) {
		if (m[c].first < 2) return m[c].second;
	}

	return -1;

}


//
//loveleetcode
//
//
//l = 108
//a = 97
//
//v[108 - 97]
//v[11]
//
//l = 11
//
//this way you can stack the letters in the vector
//and at the moment you need to searh / iterate, each letter will have
//its count, and index

//its limit is 28 cuz there are 27-28 letters i think


//best
int firstUniqChar(string s) {

	vector<int> freq(28);

	for (auto c : s) {
		freq[c - 'a']++;
	}
	
	for (int i = 0; i < s.length(); i++) {
		if (freq[s[i] - 'a'] == 1) {
			return i;
		}
	
	}
	return -1;
}



int main()
{
	cout << firstUniqChar("loveleetcode");
}

