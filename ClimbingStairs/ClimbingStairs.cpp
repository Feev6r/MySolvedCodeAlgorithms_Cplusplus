#include <iostream>
#include <unordered_map>

using namespace std;


int solve(int n, unordered_map<int, int> &memo) {

    if (memo.count(n)) return memo[n];

    if (n == 0) return 1;
    if (n < 0) return 0;

    memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    return memo[n];

}


int climbStairs(int n) {

    unordered_map<int, int> memo;
    return solve(n, memo);

}

int main()
{
    cout << climbStairs(2);
}

