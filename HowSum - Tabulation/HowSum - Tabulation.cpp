#include <iostream>
#include <vector>

using namespace std;

vector<int> howSum(int targetSum, vector<int> numbers) {

	vector<vector<int>> table(targetSum + 1, vector<int>());
	table[0] = {};

	for (int i = 0; i < targetSum; i++)
	{
		if (!table.empty() || i == 0) {

			for (int num : numbers)
			{
				if (i + num <= targetSum) {

					table[i + num] = table[i];
					table[i + num].push_back(num);
				}


			}

		}
	}

	return table[targetSum].empty() ? vector<int>() : table[targetSum];
}



int main()
{
	std::cout << "Hello World!\n";
}

