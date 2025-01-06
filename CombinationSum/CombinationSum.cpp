#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void solve(vector<int>& candidates, vector<vector<int>>&  ans,vector<int>& cur, int target, int sum, int start) {

        if (sum > target) return;
        if (sum == target) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            cur.push_back(candidates[i]);
            solve(candidates, ans, cur, target, sum + candidates[i], i);
            cur.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        solve(candidates, ans, cur, target, 0, 0);
        return ans;

    }

};


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        makeCombination(candidates, target, 0, comb, 0, res);
        return res;
    }

private:
    void makeCombination(std::vector<int>& candidates, int target, int idx, vector<int>& comb, int total, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(comb);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            return;
        }

        comb.push_back(candidates[idx]);
        makeCombination(candidates, target, idx, comb, total + candidates[idx], res);
        comb.pop_back();
        makeCombination(candidates, target, idx + 1, comb, total, res);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

