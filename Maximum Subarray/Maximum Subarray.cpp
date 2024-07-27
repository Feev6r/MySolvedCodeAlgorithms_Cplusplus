#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
   
    int maxSubArray(vector<int>& nums) {

        vector<vector<int>> dp(2, vector<int>(size(nums), -1));

        return solve(nums, 0, false, dp);
    }

    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {

        if (i >= size(A)) return mustPick ? 0 : -1e5;

        if (dp[mustPick][i] != -1) return dp[mustPick][i];

        if (mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i + 1, true, dp));

        return dp[mustPick][i] = max(solve(A, i + 1, false, dp), A[i] + solve(A, i + 1, true, dp));
    }
};

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = size(nums), ans = INT_MIN;

        for (int i = 0; i < n; i++)
            for (int j = i, curSum = 0; j < n; j++)

                curSum += nums[j], ans = std::max(ans, curSum);

        return ans;
    }
};

int main()
{


    std::vector<int> a;
    a.push_back(1);
    a.push_back(-1);
    a.push_back(5);
    a.push_back(-1);
    a.push_back(3);
    a.push_back(-2);
    a.push_back(1);

    Solution2 s;

	std::cout << s.maxSubArray(a);
   

}
