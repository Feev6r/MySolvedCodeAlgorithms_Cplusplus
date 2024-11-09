#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//my brute force, but im not sure if it works
int subarraySum(vector<int>& nums, int k) {

	int totalCount = 0;
	int currentSum = 0;
	int n = nums.size();

	for (size_t i = 0; i < n; i++)
	{
		currentSum = 0;
		for (size_t j = i; j < n; j++)
		{
			currentSum += nums[j];
			if (currentSum == k) totalCount++;
		}
	}
	return totalCount;
}


//[1,1,1,1,1,1,1,1]

//Brute force
int subarraySum(vector<int> nums, int k) {
    int count = 0;
    for (int start = 0; start < nums.size(); start++) {

        for (int end = start + 1; end <= nums.size(); end++) {
            int sum = 0;

			for (int i = start; i < end; i++) {
				sum += nums[i];
			}

            if (sum == k) count++;
        }
    }
    return count;
}

int subarraySum(std::vector<int>& nums, int k) {
    int count = 0, sum = 0;
    std::unordered_map<int, int> map;
    map[0] = 1; // Initialize map with sum 0

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (map.find(sum - k) != map.end()) {
            count += map[sum - k];
        }
        map[sum]++;
    }

    return count;
}

int main()
{
    std::cout << "Hello World!\n";
}

