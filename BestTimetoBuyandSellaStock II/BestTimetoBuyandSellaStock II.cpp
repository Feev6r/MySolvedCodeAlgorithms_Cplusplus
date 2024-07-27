#include <iostream>
#include <vector>

using namespace std;


int maxProfit(vector<int>& prices) {

    int profit = 0;

	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i - 1]) {

			profit += prices[i] - prices[i - 1];

		}
	}

	return profit;

}


int maxProfit2(vector<int>& prices) {

	int profit = 0;

	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i - 1]) {
			profit += prices[i] - prices[i - 1];
		}
	}

	return profit;

}

int main()
{
	vector<int> v = { 7,6,4,3,1 };
	std::cout << maxProfit2(v);
}

