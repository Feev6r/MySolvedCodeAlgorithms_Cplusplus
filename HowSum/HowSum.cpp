#include <iostream>
#include <vector>
#include <optional>
#include <unordered_map>

bool Solve(int targetSum, const std::vector<int>& numbers, std::vector<int>& result, 
	std::unordered_map<int, bool>& memo)
{
	result.clear();

	if (memo.count(targetSum)) return memo[targetSum];
	if (targetSum == 0) return true;
	if (targetSum < 0) return false;


	for (int num : numbers) {
		const int remainder = targetSum - num;

		bool recursion_result = Solve(remainder, numbers, result, memo);

		if (recursion_result) {
			result.push_back(num);
			memo[targetSum] = true;
			return true;
		}
	}

	memo[targetSum] = false;
	return false;
}

bool HowSum(int targetSum, const std::vector<int>& numbers, std::vector<int>& result) {

	std::unordered_map<int, bool> memo;

	return Solve(targetSum, numbers, result, memo);

}


std::optional<std::vector<int>> HowSum2(int targetSum, const std::vector<int>& numbers) {

	if (targetSum == 0)
		return std::vector<int>{};
	if (targetSum < 0)
		return std::nullopt;
	for (auto number : numbers) {

		const int remainder = targetSum - number;

		auto remainderResult = HowSum2(remainder, numbers);
		if (remainderResult) {
			remainderResult->push_back(targetSum);
			return remainderResult;
		}
	}
	return std::nullopt;
}

std::vector<int> HowSum1(int TargetSum, std::vector<int>& Numbers) {

	if (TargetSum == 0) return {};
	if (TargetSum < 0) return {};


	for (int num : Numbers)
	{
		int Remainder = TargetSum - num;
		std::vector<int> RemainderResult = HowSum1(Remainder, Numbers);
		if (!RemainderResult.empty()) {

			RemainderResult.push_back(num);

			return RemainderResult;
		}
	}

	return {};
}


int main()
{
	std::vector<int> v = { 7,12 };

	std::vector<int> res(3);

	HowSum(1000, v, res);



	std::cout << "[ ";
	for (int n : res)
	{
		std::cout << n << " ";
	}
	std::cout << "]";
}
