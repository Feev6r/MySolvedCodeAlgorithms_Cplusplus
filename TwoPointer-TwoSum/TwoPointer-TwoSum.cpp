#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>



class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::vector<std::pair<int, int>>v;

        for (int i = 0; i < nums.size(); i++) {
            v.push_back({ nums[i],i });
        }

        sort(v.begin(), v.end());

        int l = 0, r = nums.size() - 1;

        while (l < r) {

            if (v[l].first + v[r].first > target) r -= 1;

            else if (v[l].first + v[r].first < target) l += 1;

            else return { v[l].second,v[r].second };
        }

        return { -1,-1 };
    }
};

//6
//[1,2,3,4,5,6]


int main()
{
    std::cout << "Hello World!\n";
}
