#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int maxSumSubArray(vector<int>& nums, int k) {

    int maxValue = INT_MIN;
    int currentRunningSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        currentRunningSum += nums[i];

        if (i >= (k - 1)) {
            maxValue = max(currentRunningSum, maxValue);
            currentRunningSum -= nums[i - (k - 1)];

        }

    }

    return maxValue;
}

int smallestSubArray(int targetSum, vector<int>& arr) {
    
    int minWindowSize = INT_MAX;
    int currentWindowSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        currentWindowSum += arr[windowEnd];
        
        while (currentWindowSum >= targetSum) {

            minWindowSize = min(minWindowSize, windowEnd - windowStart + 1);
            currentWindowSum -= arr[windowStart];
            windowStart++;
        }
    }

    return minWindowSize;
}


//Kadanes algorithm
int maxSubArray(vector<int>& nums) {

    int curMax = 0, maxTillNow = INT_MIN;

    for (auto c : nums) {

        curMax = max(c, curMax + c),
        maxTillNow = max(maxTillNow, curMax);
    }
    
    return maxTillNow;
}


int solve(vector<int>& arr, int i, bool mustPick, unordered_map<int, int> memo) {


    if (i >= size(arr)) return mustPick ? 0 : INT_MIN;


    if (memo.count(i)) return memo[i];
    if (mustPick) return max(0, arr[i] + solve(arr, i + 1, true, memo));

    memo[i] =  max(solve(arr, i + 1, false, memo), arr[i] + solve(arr, i + 1, true, memo));
    return memo[i];
}


//Recursive
int maxSubArrayR(vector<int>& nums) {

    unordered_map<int, int> memo;
    
    return solve(nums, 0, false, memo);
}


int main()
{
    vector<int> v = { 4,2,1,7,8,1,2,8,1,0 };
    vector<int> v2 = { 4,2,2,7,8,1,2,8,1,0 };
    vector<int> v3 = { -2,1,-3,4,-1,2,1,-5,4 };
    vector<int> v4 = { -2,4,4,4,-6};
    
    //cout << maxSubArray(v3);
    cout << maxSubArrayR(v4);
    //maxSumSubArray(v, 3);
    //cout << smallestSubArray(8, v2);
}