#include <iostream>
#include <vector>

using namespace std;

//sliding window made by me
int numberOfArithmeticSlices(vector<int>& nums) {

	int start = 0;
	int curCount = 0;
	int maxCount = 0;
	int currDiff = 0;  

	if (nums.size() >= 2) {
		currDiff = nums[0] - nums[1];
	}

	for (int end = 1; end < nums.size(); end++)
	{
		if (end - start + 1 >= 3) {
			curCount = max(curCount, end - start + 1);
		}

		if (end < nums.size() - 1 && currDiff != nums[end] - nums[end + 1]) {
			while (start < end) {
				start++;
			}
			currDiff = nums[end] - nums[end + 1];
			
			if (curCount >= 3) {
				maxCount += ((curCount - 2) * (curCount - 1)) / 2;
			}

			curCount = 0;
		}
	}

	if (curCount >= 3) maxCount += ((curCount - 2) * (curCount - 1)) / 2;
	
	return maxCount;

}

//db creo
int numberOfArithmeticSlices2(vector<int>& nums) {
	 
	int n = nums.size(), cnt = 0;
	vector<int> v(n, 0);

	for (int i = 2; i < n; i++) {

		if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) cnt++;
		else cnt = 0;

		v.push_back(cnt);
	}
	v.push_back(0);

	int ans = 0;

	for (int i = 0; i < v.size(); i++) {

		if (v[i] != 0 && v[i + 1] == 0) {
			ans += v[i] * (v[i] + 1) / 2;
		}
	}
	return ans;
}


int main()
{
	vector<int> v = { 1,2,3,4,7,1,2,3,4 };
	numberOfArithmeticSlices(v);
}

