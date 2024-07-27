#include <iostream>
#include <vector>

using namespace std;


vector<int> bestSum(int targetSum, vector<int> numbers) {

	vector<vector<int>> table(targetSum + 1, vector<int>());
	table[0] = {};

	for (int i = 0; i < targetSum; i++)
	{
		if (!table[i].empty() || i == 0) {

			for (int num : numbers)
			{
				vector<int> combination = table[i];
				combination.push_back(num);

				if (i + num <= targetSum) {

					if (table[i + num].empty() || table[i + num].size() > combination.size()) {

						table[i + num] = combination;
					}
				}

			}

		}
	}
	return table[targetSum];
}

int main()
{

	vector<int> aas;

	cout << boolalpha << aas.empty() << endl;


	vector<int> res = bestSum(8, { 1, 4, 5 });
	vector<int> res2 = bestSum(100, { 1,2,5,25 });

	std::cout << "[ ";
	for (int n : res)
	{
		std::cout << n << " ";
	}
	std::cout << "]";
}

