#include <iostream>
#include <vector>

using namespace std;


vector<int> twoSum(int target, vector<int> nums) {

    if (target == 0 ) return {};
    if (target < 0) return {INT_MIN};

    vector<int> combination = { INT_MIN };

    for (int i = 0; i < nums.size(); i++)
    {
        const int remainder = target - nums[i];
        vector<int> v = nums;
        v.erase(v.begin() + i);

        vector<int> remainderCombination = twoSum(remainder, v);

        if (remainderCombination != vector<int>{INT_MIN}) {

            combination = remainderCombination;
            combination.push_back(i);

        }

    }

    return combination;
}

//si no funcionan, se eliminan definitivamente

int main()
{
    vector<int> result = twoSum(9, { 2,7,11,15 });

    for (auto& num : result) {

        cout << num << endl;
    }
}
