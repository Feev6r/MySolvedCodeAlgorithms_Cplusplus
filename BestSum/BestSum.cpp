#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> Solve(int targetSum, const std::vector<int>& numbers, 
    std::unordered_map<int, std::vector<int>>& memo) {
    
    
    if (targetSum == 0) return {};
    if (targetSum < 0) return { INT_MIN };

    if (memo.count(targetSum)) return memo[targetSum];


    std::vector<int> shortestCombination = { INT_MIN };

    for (int num : numbers) {
        int remainder = targetSum - num;
        std::vector<int> remainderCombination = Solve(remainder, numbers, memo);

        if (remainderCombination != std::vector<int>{INT_MIN}) {

            std::vector<int> combination = remainderCombination;
            combination.push_back(num);

            if (shortestCombination == std::vector<int>{INT_MIN} ||
                combination.size() < shortestCombination.size()) {
                

                shortestCombination = combination;
            }
        }
    }

    memo[targetSum] = shortestCombination;
    return shortestCombination;
}


std::vector<int> BestNum(int targetSum, const std::vector<int>& numbers) {

    std::unordered_map<int, std::vector<int>> memo;

    return Solve(targetSum, numbers, memo);
}


int main()
{

    std::vector<int> v = { 2,3,5 };

    std::vector<int> res = BestNum(100, {1,2,5,25});

    //BestSum(8, v, res);


    std::cout << "[ ";
    for (int n : res)
    {
        std::cout << n << " ";
    }
    std::cout << "]";
}
