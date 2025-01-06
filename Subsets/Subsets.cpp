#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<int>& cur, int count, vector<vector<int>>& ans) {
        if (count >= nums.size()) {
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[count]);
        solve(nums, cur, count + 1, ans);
        cur.pop_back();
        solve(nums, cur, count + 1, ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        solve(nums, cur, 0, ans);
        return ans;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
