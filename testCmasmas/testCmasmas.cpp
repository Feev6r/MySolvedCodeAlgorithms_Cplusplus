#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <array>

using namespace std;

//int lengthOfLongestSubstring(string s) {
//
//	int stringSize = s.length();
//
//	for (int i = 0; i < stringSize; i++)
//	{
//
//	}
//
//}
//
//int findMaxSumSubArray(vector<int> nums, int k) {
//	int maxValue = INT_MIN;
//	int currentRunnigSum = 0;
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		currentRunnigSum += nums[i];
//
//		if (i >= k - 1) {
//			maxValue = max(maxValue, currentRunnigSum);
//			currentRunnigSum -= nums[i - (k - 1)];
//		}
//	}
//
//	return maxValue;
//}


int main() {

	/*cout << findMaxSumSubArray({ 4,2,1,7,8,1,2,8,1,0 }, 3) << endl;*/
	string s = "babad";

	cout << s.substr(2, 2);

}