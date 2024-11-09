#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

	unordered_map<int, int> m;
	for (int num : nums1) {
		
		if (!m.count(num)) m[num]++;
	} 

	vector<int> ans;
	for (auto i : nums2) {
		if (m[i] > 0) {
			ans.push_back(i);
			m[i]--;
		}
	}

	return ans;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> s(nums1.begin(), nums1.end());
	unordered_set<int> answer;
	for (int num : nums2) {
		if (s.count(num)) {
			answer.insert(num);
		}
	}
	return vector<int>(answer.begin(), answer.end());
}

int main()
{
    std::cout << "Hello World!\n";
}

