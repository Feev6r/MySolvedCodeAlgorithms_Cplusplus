#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

int maxSubArray(vector<int>& nums) {

	int	maxSum = INT_MIN;
	int curSum = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		curSum += nums[i];
		maxSum = max(maxSum, curSum);

		if (curSum < 0) curSum = 0;
	}

	return maxSum;
}

int findMaxSumSubArray(vector<int> arr, int k) {

	int maxValue = INT_MIN;
	int currentRunningSum = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		currentRunningSum += arr[i];
		if (i >= k - 1) {
			maxValue = max(maxValue, currentRunningSum);
			currentRunningSum -= arr[i - (k - 1)];
		}
	}

	return maxValue;
}

int smallestSubArray(vector<int> arr, int targetSum) {
	
	int minWindowSize = INT_MAX;
	int currentWindowsSum = 0;
	int windowStart = 0;

	for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
	{
		currentWindowsSum += arr[windowEnd];

		while (currentWindowsSum >= targetSum) {
			minWindowSize = min(minWindowSize, windowEnd - windowStart + 1);
			currentWindowsSum -= arr[windowStart];
			windowStart++;
		}
	}

	return minWindowSize;

}

int longestSubstringLength(string str, int k) {


	unordered_map<char, int> mp;
	int maxWindowsSize = 0;
	int windowStart = 0;
	for (int windowEnd = 0; windowEnd < str.size(); windowEnd++)
	{
		mp[str[windowEnd]]++;

		while (mp.size() > k)
		{
			 mp[str[windowStart]]--;
			 if (mp[str[windowStart]] == 0) mp.erase(str[windowStart]);			
		     windowStart++;
		}
	
		maxWindowsSize = max(maxWindowsSize, windowEnd - windowStart + 1);
	}

	return maxWindowsSize;
}

//4, 2, 2, 7, 8, 1, 2, 8, 10

int main()
{
	// Test Case 1
	assert(longestSubstringLength("abcba", 2) == 3);

	// Test Case 2
	assert(longestSubstringLength("abcdef", 3) == 3);

	// Test Case 3
	assert(longestSubstringLength("aaaa", 1) == 4);

	// Test Case 4
	assert(longestSubstringLength("abc", 10) == 3);

	// Test Case 5
	assert(longestSubstringLength("", 2) == 0);

	cout << "All test cases passed!" << endl;
}
