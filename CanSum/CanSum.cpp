#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

bool Solve(int TargetSum, std::vector<int> numbers, std::unordered_map<int, bool>& memo) {
	if (memo.count(TargetSum)) return memo[TargetSum];
	if (TargetSum == 0) return true;
	if (TargetSum < 0) return false;


	for (int num : numbers) {
		int Remainder = TargetSum - num;
		if (Solve(Remainder, numbers, memo) == true) {
			memo[TargetSum] = true;
			return true;
		}
	}
	memo[TargetSum] = false;
	return false;
}


bool CanSum(int TargetSum, std::vector<int> numbers) {

	std::unordered_map<int, bool> memo;

	return Solve(TargetSum, numbers, memo);

}


int main()
{

	std::vector<int> v;
	v.push_back(7);
	v.push_back(14);

	std::cout << CanSum(300, v);
}

