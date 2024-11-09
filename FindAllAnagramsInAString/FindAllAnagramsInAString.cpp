#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> findAnagrams(string s, string p) {



	vector<int> ans;
	vector<int> map(128, 0);

	int count = p.length();
	int start = 0, end = 0;
	sort(p.begin(), p.end());

	for (char c : p) {
		map[c]++;
	}

	while (end < s.length())
	{
		if (map[s[end++]]-- > 0) {
			count--;
		}

		if (count == 0) {

			//if (s.substr(start, end - start + 1) == p) {
			//	ans.push_back(start);
			//}
			string e = s.substr(start, end - start);
			sort(e.begin(), e.end());

			if (e == p) {
				ans.push_back(start);
			}

			if (map[s[start++]]++ == 0) {
				count++;
			}
		}
	}

	return ans;

}


vector<int> findAnagrams(string s, string p) {

	vector<int> pv(26, 0), sv(26, 0), res;

	if (s.size() < p.size()) return res;
	// fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
	for (int i = 0; i < p.size(); ++i)
	{
		++pv[p[i] - 'a'];
		++sv[s[i] - 'a'];
	}

	if (pv == sv) res.push_back(0);
	//here window is moving from left to right across the string. 
	//window size is p.size(), so s.size()-p.size() moves are made 
	for (int i = p.size(); i < s.size(); ++i)
	{
		// window extends one step to the right. counter for s[i] is incremented 
		++sv[s[i] - 'a'];

		// since we added one element to the right, 
		// one element to the left should be discarded. 
		//counter for s[i-p.size()] is decremented
		--sv[s[i - p.size()] - 'a'];

		// if after move to the right the anagram can be composed, 
		// add new position of window's left point to the result 
		// this comparison takes O(26), i.e O(1), since both vectors are of fixed size 26. Total complexity O(n)*O(1) = O(n)
		if (pv == sv) res.push_back(i - p.size() + 1);
	}

	return res;
}



vector<int> findAnagrams(string s, string p) {

	vector<int> sv(26, 0), pv(26, 0), ans;
	if (s.size() < p.size()) return ans;

	for (int i = 0; i < p.size(); i++)
	{
		sv[s[i] - 'a']++;
		pv[s[i] - 'a']++;
	}

	if (sv == pv) ans.push_back(0);

	for (int i = p.size(); i < s.size(); i++)
	{
		sv[s[i] - 'a']++;
		sv[s[i - p.size()] - 'a']--;
	
		if (sv == pv) ans.push_back(i - p.size() + 1);
	}

	return ans;
}

//abcabc

int main()
{
	findAnagrams("cbacbabacd", "abc");
}
