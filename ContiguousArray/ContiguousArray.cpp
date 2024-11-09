#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findMaxLength(vector<int>& nums) {


	int count = 0;
	int total = 0;
	unordered_map<int, int> mp;

	mp[0] = -1;
	for (int i = 0; i < nums.size(); i++)
	{
		count += nums[i] == 1 ? 1 : -1;

		if (mp.find(count) != mp.end()) {
			total = max(total, i - mp[count]);
		}
		else {
			mp[count] = i;
		}
	}
	return total;
}


int findMaxLength(vector<int>& nums) {


	int count = 0;
	int total = 0;
	int n = nums.size();
	for (size_t i = 0; i < n; i++)
	{
		count += nums[i] == 1 ? 1 : 0;
	}

	total = min(n - count, count) * 2;
	return total;
}



//11000111
//000110011

//00000000000011

//()

int main()
{
	vector<int> v = { 0,1,0 };
	findMaxLength(v);
}

