#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;


//Best solution finded by me (with tricks "sort"):
bool containsDuplicate2(vector<int>& nums) {

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 1; i++) {

		if (nums[i] == nums[i + 1]) return true;
	}

	return false;
}

//brute force
bool containsDuplicate(vector<int>& nums) {

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] == nums[j]) {
				return true;
			}
		}
	}

	return false;
}

//hash map solution
bool containsDuplicate(vector<int>& nums) {

	unordered_map<int, int> map;

	for (int i = 0; i < nums.size(); i++)
	{
		for (auto& n : nums) map[i]++;
		for (auto& m : map) {
			if (m.second > 1) return true;
		} 
	}

	return false;

}


//set map solution
bool containsDuplicate(vector<int>& nums) {

	return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
}

int main()
{
    std::cout << "Hello World!\n";
}
