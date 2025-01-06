#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void solve(vector<int>& curComb, vector<vector<int>>& totalComb, int totalSum, int& k, int& n, int idx) {

        if (curComb.size() > k || totalSum > n) {
            return;
        }
        
        if (totalSum == n && curComb.size() == k) {
            totalComb.push_back(curComb);
            return;
        }

        for (int i = idx; i <= 9; i++)
        {
            curComb.push_back(i);
            solve(curComb, totalComb, totalSum + i, k, n, i + 1);
            curComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> curComb;
        vector<vector<int>> totalComb;

        solve(curComb, totalComb, 0, k, n, 1);
        return totalComb;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

