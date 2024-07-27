#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//[1,2,3,3,4,5,5,5]
//[2,3,4,5,5,5]

//best solution:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int i = 0, j = 0;
	
	vector<int> ans;
	
	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] == nums2[j]) {
			ans.push_back(nums1[i]);
			i++; j++;
		}
		else if (nums1[i] < nums2[j]) {
			i++;
		}
		else {
			j++;
		}
	}

	return ans;
}


vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {

	unordered_map<int, int> m;
	for (int num : nums1) m[num]++;

	vector<int> ans;
	for (auto i : nums2) {
		if (m[i] > 0) {
			ans.push_back(i);
			m[i]--;
		}
	}

	return ans;

}

int main()
{
	
	vector<int> a = { 4,9,5 };
	vector<int> b = { 9,4,9,8,4 };


	vector<int> r = intersect(a, b);


	cout << "[ ";
	for (auto& a : r) {
		cout << a << " ";
	}
	cout << "]";



}
