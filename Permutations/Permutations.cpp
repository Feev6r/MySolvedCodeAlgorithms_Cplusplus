#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

//vector<vector<int>> permute(vector<int>& nums) {
//
//}

vector<vector<int>> permutations(vector<int> elements) {
	if (elements.size() == 0) return { {} };

	int firstEl = elements[0];
	vector<int> rest(elements.begin() + 1, elements.end());

	vector<vector<int>> permsWithoutFirst = permutations(rest);

	vector<vector<int>> allPermutations;
	for (auto perm : permsWithoutFirst) {

		for (int i = 0; i <= perm.size(); i++) {

			vector<int> permWithFirst(perm.begin(), perm.begin() + i);
			permWithFirst.push_back(firstEl);
			permWithFirst.insert(permWithFirst.end(), perm.begin() + i, perm.end());

			allPermutations.push_back(permWithFirst);
		}
	}

	return allPermutations;
}

void generatePermutations(vector<int>& arr, int start, vector<vector<int>>& result) {

	if (start == arr.size() - 1) {

		result.push_back(arr);
		return;
	}

	for (int i = start; i < arr.size(); i++) {


		swap(arr[start], arr[i]);  // Swap current element with the start
		generatePermutations(arr, start + 1, result);  // Recur for the next position
		swap(arr[start], arr[i]);  // Backtrack
	}
}

void generateUniquePermutations(vector<int>& arr, int start, vector<vector<int>>& result, unordered_map<string, bool>& mp) {

	
	if (start == arr.size() - 1) {

		string key;
		for (auto& n : arr) key += to_string(n);

		if (!mp[key]) {

			result.push_back(arr);
			mp[key] = true;
		}

		return;
	}

	for (int i = start; i < arr.size(); i++) {

		swap(arr[start], arr[i]);  // Swap current element with the start
		generateUniquePermutations(arr, start + 1, result, mp);  // Recur for the next position
		swap(arr[start], arr[i]);  // Backtrack
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {

	vector<vector<int>> ans;
	unordered_map<string, bool> mp;
	generateUniquePermutations(nums, 0, ans, mp);
	return ans;
}



int main()
{
	vector<int> v = { 1,1,2 };
	vector<vector<int>> result = permuteUnique(v);

	// Print the results
	for (const auto& perm : result) {
		for (int num : perm) {
			cout << num << " ";
		}
		cout << endl;
	}
}
