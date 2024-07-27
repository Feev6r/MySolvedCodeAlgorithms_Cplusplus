#include <iostream>
#include <vector>

//Basicamente es un algoritmo que solo j cuando un numero no esta repetido, tener en cuenta que el array esta ordenado
class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {

		int j = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[i - 1]) {
				nums[j] = nums[i];
				j++;
			}
		}
		return j;
	}
};

//NO FUNCIONAL
class MyTestSolution { 
public:
	int removeDuplicates(std::vector<int>& nums) {

		int s = nums.size();
		int i = 1;
		int l = s - 2;
		int f = s - 2;
		int k = 1;
		int middle = s / 2;


		while (nums[i] != nums[middle] || nums[l] != nums[middle])
		{
			if (nums[i] != nums[i - 1])
			{
				i++;
				k++;
				nums[k] = nums[i];
			}
			if (nums[l] != nums[l + 1])
			{
				l--;
				f--;
				nums[f] = nums[l];
			}
		
		}

		return f;
	}
};


//[1,2,2,3,4,5,5,6,7,8]
//[1,2,3,4,5,5,5,6,7,8]

int main()
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);

}

