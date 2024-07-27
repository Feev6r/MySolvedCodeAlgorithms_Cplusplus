#include <iostream>
#include <vector>


using namespace std;

int fib(int n) {

	vector<int> table(n + 1);
	table[1] = 1;

	for (int i = 0; i <= n - 2; i++)
	{
		table[i + 1] += table[i];
		table[i + 2] += table[i];
	}
	table[n] += table[n - 1];

	return table[n];
}


int main()
{
	cout << fib(8);
}
