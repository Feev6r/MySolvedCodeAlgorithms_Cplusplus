#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


//My solution O(n*k)
vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> mp;
    for (int n : nums) mp[n]++;

    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        pair<int, int> p;
        for(auto& pair : mp){

            if (pair.second > p.second) {
                p.second = pair.second;
                p.first = pair.first;
            }
        }

        ans.push_back(p.first);
        mp.erase(p.first);
    }
    
    return ans;
}

//O(n)
vector<int> topKFrequent2(vector<int>& nums, int k) {
    unordered_map<int, int> counter;

    for (int n : nums) counter[n]++;

    vector<vector<int>> freq(nums.size() + 1);
    for (auto& entry : counter) {

        freq[entry.second].push_back(entry.first);
    }

    vector<int> res;

    for (int i = freq.size() - 1; i >= 0; i--) {

        for (int num : freq[i]) {

            res.push_back(num);

            if (res.size() == k) {
                return res;
            }
        }
    }

    return {};
}

int main()
{

    vector<int> v = { 1,1,1,2,2,3,2,2,2,1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,1 };
    topKFrequent2(v, 2);
}

