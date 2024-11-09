#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& nums) {

	for (int i = 1; i < nums.size(); i++)
	{
		int temp = nums[i];
		int j = i - 1;

		while (j >= 0 && nums[j] > temp) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = temp;
	}
}

int main()
{
	vector<int> ej = { 9,2,3,1,4,5,6,7,8 };
	insertionSort(ej);
}

