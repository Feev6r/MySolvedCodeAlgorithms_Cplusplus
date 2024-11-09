#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	unordered_map<int, int> map; // map from x to next greater element of x
	stack<int> stack;

	for (int num : nums) {

		while (!stack.empty() && stack.top() < num) {
			map[stack.top()] = num;
			stack.pop();
		}
		
		stack.push(num);
	}

	for (int i = 0; i < findNums.size(); i++) {
		findNums[i] = map.count(findNums[i]) ? map[findNums[i]] : -1;
	}

	return findNums;
}

//my solution
vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {

	unordered_map<int, int> mp;

	int n1 = nums1.size();
	int n2 = nums2.size();

	vector<int> ans(n1, -1);

	//for (auto& n : nums1) mp[n];
	for (int i = 0; i < n1; i++) mp[nums1[i]] = i;
	for (int i = 0; i < n2; i++)
	{
		if (mp.count(nums2[i])) {
			int j = i + 1;

			while (j < n2) {

				if (nums2[j] > nums2[i]) {
					ans[mp[nums2[i]]] = nums2[j];
					break;
				}
				j++;
			}
		}
	}

	return ans;

}

int main()
{
	vector<int> v1 = { 1,3,5,2,4 };
	vector<int> v2 = { 6,5,4,3,2,1,7 };
	nextGreaterElement(v1, v2);
}
