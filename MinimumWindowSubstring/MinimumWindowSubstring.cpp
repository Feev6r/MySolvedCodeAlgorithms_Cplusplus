#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {

	unordered_map<char, int> mp;
	unordered_map<char, int> mpTemp;
	for (auto& c : t) mp[c]++;
	mpTemp = mp;

	string ans = "";
	int minimum = INT_MAX;
	int completed = 0;
	int start = 0;

	for (int end = 0; end < s.length(); end++)
	{

		if (mpTemp[s[end]] > 0) mpTemp[s[end]]--;

		if (mpTemp[s[end]] == 0) {
			completed++;
		}

		if (completed >= t.size()) {

			if(completed % t.size() == 0) mpTemp = mp;


			while (start < end &&  mpTemp[s[start]] == 0 || mpTemp.find(s[start]) == mpTemp.end())
			{
				completed--;
				start++;
			}

			minimum = min(minimum, end - start + 1);

			//if (minimum > end - start + 1) {

			//	ans.clear();
			//	for (int i = start; i < end; i++)
			//	{
			//		ans += s[i];
			//	}

			//	minimum = ans.size();
			//}
		}
	}

	cout << minimum;
	return ans;

}

string minWindow2(string s, string t) {
    if (s.length() < t.length()) {
        return "";
    }

    unordered_map<char, int> charCount;
    for (char ch : t) {
        charCount[ch]++;
    }

    int targetCharsRemaining = t.length();
    int minWindow[2] = { 0, INT_MAX };
    int startIndex = 0;

    for (int endIndex = 0; endIndex < s.length(); endIndex++) {
        char ch = s[endIndex];
        if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
            targetCharsRemaining--;
        }
        charCount[ch]--;

        if (targetCharsRemaining == 0) {
            while (true) {
                char charAtStart = s[startIndex];
                if (charCount.find(charAtStart) != charCount.end() && charCount[charAtStart] == 0) {
                    break;
                }
                charCount[charAtStart]++;
                startIndex++;
            }

            if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
                minWindow[0] = startIndex;
                minWindow[1] = endIndex;
            }

            charCount[s[startIndex]]++;
            targetCharsRemaining++;
            startIndex++;
        }
    }

    return minWindow[1] >= s.length() ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
}

string minWindow3(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) {
        return "";
    }

    vector<int> map(128, 0);
    int count = t.length();
    int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;

    for (char c : t) map[c]++;
  
    while (end < s.length()) {

        if (map[s[end++]]-- > 0) {
            count--;
        }

        while (count == 0) {
            if (end - start < minLen) {
                startIndex = start;
                minLen = end - start;
            }

            if (map[s[start++]]++ == 0) {
                count++;
            }
        }
    }

    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}

int main()
{
	minWindow3("ADOBECODEBANC", "ABC");
}
