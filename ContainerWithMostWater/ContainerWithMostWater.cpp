#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {

	int maxWater = 0;
	int i = height.size() - 1;
	int j = 0;

	while (j < i)
	{
		int minColumn = min(height[j], height[i]);
		int width = (i - j);

		maxWater = max(maxWater, minColumn * width);


		if (height[j] > height[i]) i--;
		else j++;

	}

	return maxWater;
}

int main()
{

	vector<int> v = { 1,8,6,2,5,4,8,3,7 };
	cout << maxArea(v);
}

