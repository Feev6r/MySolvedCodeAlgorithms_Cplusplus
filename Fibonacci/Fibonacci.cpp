#include <iostream>
#include <unordered_map>


int fib(int n) {

	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}

/// <summary>
/// SO CRAZY
/// </summary>
/// <param name="Locura Y"></param>
/// <param name="Depresion"></param>
/// <returns></returns>
long long int solve(int n, std::unordered_map<int, long long int>& memo) {

	if (memo.count(n)) return memo[n];

	if (n <= 2) return 1;

	memo[n] = solve(n - 1, memo) + solve(n - 2, memo);

	return memo[n];
}

long long int fibb(int n) {

	std::unordered_map<int, long long int> memo;

	return solve(n, memo);
}


int main()
{
	std::cout << fibb(50);
}

