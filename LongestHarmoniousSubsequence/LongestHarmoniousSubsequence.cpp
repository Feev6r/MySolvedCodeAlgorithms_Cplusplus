#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> hash;

    int n = nums.size();
    for (auto& n : nums) hash[nums[n]]++;

    int res = 0;

    for (auto it : hash) {
        if (hash.count(it.first - 1)) { //if we find the -1 of each one
            res = max(res, it.second + hash[it.first - 1]); //the second one plus first one added and then we verify wich one sum is bigger
        }
    }

    return res;
}



int main()
{
    std::cout << "Hello World!\n";
}

