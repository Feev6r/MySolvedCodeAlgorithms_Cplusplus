#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {

	int currentOdds = 0;
	int start = 0;
	int PrefixEven = 0;
	int totalCount = 0;
	for (size_t end = 0; end < nums.size(); end++)
	{
		
		currentOdds += nums[end] % 2;
	

		while (start < end && (nums[start] % 2 == 0 ||  currentOdds > k))
		{
			if (nums[start] % 2 != 0) {
				PrefixEven = 0;
			}
			else {
				PrefixEven++;
			}

			currentOdds -= nums[start] % 2;
			start++;

		}

		if (currentOdds == k) {
			totalCount += 1 + PrefixEven;
		}
	}

	return totalCount;
}


//HASH MAP SOLUTION:
int numberOfSubarrays(vector<int>& nums, int k) {
	int currSum = 0, subarrays = 0;
	unordered_map<int, int> prefixSum;
	prefixSum[currSum] = 1;

	for (int i = 0; i < nums.size(); i++) {
		currSum += nums[i] % 2;
		// Find subarrays with sum k ending at i.
		if (prefixSum.find(currSum - k) != prefixSum.end()) {
			subarrays += prefixSum[currSum - k];
		}
		// Increment the current prefix sum in hashmap.
		prefixSum[currSum]++;
	}

	return subarrays;
}

int main()
{
    std::cout << "Hello World!\n";
}

