#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
	
	int maxValue = INT_MIN;
	int currentSum = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		currentSum += nums[i];
		if (i >= k - 1) {
			maxValue = max(maxValue, currentSum);
			currentSum -= nums[i - (k - 1)];
		}
	}

	return maxValue / k;
}


int main()
{
    std::cout << "Hello World!\n";
}