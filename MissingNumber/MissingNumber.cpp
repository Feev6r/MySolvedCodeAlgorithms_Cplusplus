#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int missingNumber(vector<int>& nums) {

    int n = nums.size();

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = ans ^ i;
    }

    for (int i = 0; i < nums.size(); i++) {
        ans = ans ^ nums[i];
    }

    return ans;
}

int missingNumber(vector<int>& nums) {

    int n = nums.size();
    int Tsum = (n * (n + 1)) / 2;
    //return  Tsum - accumulate(nums.begin(), nums.end(), 0);

}
//30
//hash todo n
//iterarar por el hash hasta dar con el

int main()
{

	vector<int> v = { 0,1,3 };
	missingNumber(v);
}
