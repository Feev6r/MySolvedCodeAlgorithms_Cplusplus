#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {

	int n = nums.size();

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] != val) {
			swap(nums[i], nums[j]);
			j++;
		}
	}
	return j;
}

int main()
{
    std::cout << "Hello World!\n";
}
