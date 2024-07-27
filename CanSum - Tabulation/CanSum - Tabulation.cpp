#include <iostream>
#include <vector>

using namespace std;

bool canSum(int targetSum, vector<int> numbers) {

	vector<bool> table(targetSum + 1, false);

	table[0] = true;
	for (int i = 0; i < targetSum; i++)
	{
		if (table[i] == true) {
			for (int& num : numbers)
			{
				if(i + num <= targetSum) table[i + num] = true;
			}
		}
	}

	return table[targetSum];
}

//N TARGET SUM,
//TIME: O(N*M);
//SPACE: O(M)

int main()
{
	std::cout << std::boolalpha << canSum(7, { 2,3 }) << endl;
	std::cout << std::boolalpha << canSum(300, { 7,14}) << endl;
}
