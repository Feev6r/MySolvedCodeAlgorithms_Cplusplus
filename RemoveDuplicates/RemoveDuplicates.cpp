#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int removeDuplicates(vector<int>& nums) {

	int j = 1;

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[i - 1]) {
		
			nums[j] = nums[i];
			j++;
		}

	}

	return j;
	
}

int removeDuplicates2(vector<int>& nums) {

	int j = 1;

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[i - 1]) {
			nums[j] = nums[i];
			j++;
		}

	}

	return j;

}


int main()
{ 
	//0 1 2 1 1 2 2 3 3 4
	vector<int> a = { 0,1,1,1,1,2,2,3,3,4 };

	int s = removeDuplicates2(a);

	for (int i = 0; i < s; i++)
	{
		cout << a[i] << endl;
	}

}
