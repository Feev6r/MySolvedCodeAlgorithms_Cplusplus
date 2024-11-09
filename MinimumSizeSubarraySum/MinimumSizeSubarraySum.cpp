#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {

	int curSum = 0;
	int start = 0;
	int minLength = INT_MAX;
	for (int end = 0; end < nums.size(); end++)
	{
		curSum += nums[end];
		while (curSum >= target) {

			minLength = min(minLength, end - start + 1);
			curSum -= nums[start];
			start++;
		}

	}

	return minLength == INT_MAX ? 0 : minLength;
}

int longestSubstring(string s, int k) {

	unordered_map<char, int> mp;
	int start = 0;
	int maxLength = 0;
	for (int i = 0; i < s.size(); i++)
	{ 
		mp[s[i]]++;

		if (mp[s[i]] >= k) {

			while (mp[s[start]] < k) {
				mp[s[start]]--;
				if (mp[s[start] == 0]) mp.erase(s[start]);
				start++;
			}

		}


	}

	return maxLength;
}


int main()
{
    std::cout << "Hello World!\n";
}

