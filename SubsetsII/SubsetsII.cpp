#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& cur, int idx, vector<vector<int>>& res, int n) {
        res.push_back(cur);
        for (int i = idx; i < n; i++) {

            if (i != idx && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            dfs(nums, cur, i + 1, res, n);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, cur, 0, ans, n);
        return ans;
    }
};


//meh
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = { {} };
        int start;

        for (int i = 0; i < nums.size(); i++) {

            if (i == 0 || nums[i] != nums[i - 1]) start = 0;

            for (int end = result.size(); start < end; start++) {

                vector<int> clone = result[start];
                clone.push_back(nums[i]);
                result.push_back(clone);
            }
        }

        return result;
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 1,2,2 };
    s.subsetsWithDup(nums);
}
