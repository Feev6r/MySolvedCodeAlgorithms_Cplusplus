#include <iostream>
#include <vector>

using namespace std;

//brute force
class NumArray {

    vector<int> vec;

public:
    NumArray(vector<int>& nums) {
        vec = nums;
    }

    int sumRange(int left, int right) {

        int ans = 0;

        for (int i = left; i <= right; i++)
        {
            ans += vec[i];
        }

        return ans;
    }
};


//best solution
class NumArray2 {
    vector<int> prefix;
public:
    NumArray2(vector<int>& nums) {

        prefix = vector<int>(nums.size() + 1, 0);
        
        for (size_t i = 1; i <= nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};


int main()
{
    vector<int> v = { -2, 0, 3, -5, 2, -1 };
    NumArray2 n(v);

    n.sumRange(0, 2);
}

