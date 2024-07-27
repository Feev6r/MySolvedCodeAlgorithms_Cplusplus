#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(int n, vector<int> cost, unordered_map<int, int> memo) {

    if (n < 0) return 0;
    if (n == 1 || n == 0) return cost[n];
    if (memo.count(n)) return memo[n];

    memo[n] = cost[n] + min(solve(n - 1, cost, memo), solve(n - 2, cost, memo));
    return memo[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    
    int n = cost.size();
    unordered_map<int, int> memo;

    return min(solve(n -1, cost, memo), solve(n - 2, cost, memo));
 
}



int main()
{
    std::cout << "Hello World!\n";
}
