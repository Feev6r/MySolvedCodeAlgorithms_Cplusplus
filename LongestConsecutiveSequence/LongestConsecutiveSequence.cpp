#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

int longestConsecutive(vector<int>& nums) {

    unordered_map<int, bool> map;

    for (int i = 0; i < nums.size(); i++) map[nums[i]] = true;

    for (int i = 0; i < nums.size(); i++) {
        if (map.count(nums[i] - 1)) {
            map[nums[i]] = false;
        }
    }

    int maxlen = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (map[nums[i]] == true) {

            int j = 0;

            while (map.count(nums[i] + j)) {
                j++;
            }
            
            maxlen = max(maxlen, j);
        }
    }
    return maxlen;
}

int longestConsecutive2(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : nums) {
        if (numSet.find(num - 1) == numSet.end()) {
            int length = 1;

            while (numSet.find(num + length) != numSet.end()) {
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}


int main()
{

    vector<int> v = { 100,4,200,1,3,2 };
    longestConsecutive2(v);
}
