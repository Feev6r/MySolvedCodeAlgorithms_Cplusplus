#include <iostream>
#include <unordered_map>
#include <string>


/// <summary>
/// 
/// </summary>
/// <param name="m">: Rows</param>
/// <param name="n">: Columns</param>
/// <returns></returns>
long long int Solve(int m, int n, std::unordered_map<std::string, long long int>& memo) {

    std::string key = std::to_string(n) + "," + std::to_string(m);


    if (memo.count(key)) return memo[key];
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;


                //Down                  //right
    memo[key] = Solve(m - 1, n, memo) + Solve(m, n - 1, memo);
    return memo[key];
}


long long int GridTraveler(int m, int n) {

    std::unordered_map<std::string, long long int> memo;

    return Solve(m, n, memo);

}


int main()
{


    std::cout << GridTraveler(1,1) << std::endl;
    std::cout << GridTraveler(2,3) << std::endl;
    std::cout << GridTraveler(3,2) << std::endl;
    std::cout << GridTraveler(3,3) << std::endl;
    std::cout << GridTraveler(18,18) << std::endl;
}

