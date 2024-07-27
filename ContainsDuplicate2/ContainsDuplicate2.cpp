#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {

	unordered_map<int, int> hash;

	for (int i = 0; i < nums.size(); i++)
	{
		if (!hash.count(nums[i])) {
			hash[nums[i]] = i;
		}
		else {
			if ((i - hash[nums[i]]) <= k) return true;
		}
	}

	return false;
}


int main()
{
    std::cout << "Hello World!\n";
}

