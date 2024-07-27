#include <iostream>
#include <vector>

using namespace std;

void moveZeroes2(vector<int>& nums) {
	int left = 0;

	for (int right = 0; right < nums.size(); right++) {
		if (nums[right] != 0) {
			swap(nums[right], nums[left]);
			left++;
		}
	}
}


void moveZeroes(vector<int>& nums) {

	int j = 0;

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[j] == 0 && nums[i] != 0) {
			nums[j] = nums[i];
			nums[i] = 0;
		}

		if (nums[j] != 0) {
			j++;
		}
	}


}

int main()
{
	vector<int> r = { 0,1,0,3,12 };
	moveZeroes(r);

	for (auto& n : r) {
		cout << n << " ";
	}
	


}
