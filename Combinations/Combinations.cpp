#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void solve(int& n, int& k, vector<int>& curComb, vector<vector<int>>& totalComb, int idx) {

        if (curComb.size() == k) {
            totalComb.push_back(curComb);
            return;
        }
        
        for (int i = idx; i <= n; i++)
        {
            curComb.push_back(i);
            solve(n, k, curComb, totalComb, idx + (i - idx) + 1);            
            curComb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> totalComb;
        vector<int> curComb;

        if (n == k) {
            for (int i = 1; i <= n; i++) {
                curComb.push_back(i);
            }
            totalComb.push_back(curComb);
            return totalComb;
        }

        solve(n, k, curComb, totalComb, 1);
        return totalComb;
    }
};

int main()
{
    Solution s;
    s.combine(12, 6);
}
