#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int rob(vector<int>& arr) {

    vector<int> memo(size(arr), -1);
    return rob(arr, memo, 0);
}

int rob(vector<int>& arr, vector<int>& memo, int i) {

    if (i >= size(arr)) return 0;
    if (memo[i] != -1) return memo[i];

    return memo[i] = max(rob(arr, memo, i + 1), arr[i] + rob(arr, memo, i + 2));

}


int rob(vector<int>& arr) {
    
    int prev2 = 0, prev = 0, cur = 0;

    for (auto i : arr) {
        cur = max(prev, i + prev2);
        prev2 = prev;
        prev = cur;
    }

    return cur;
}

//
//1, 2, 3, 1
//

//cur = 1
//prev2 = 0
//prev = 1
//
//
//cur = 2
//prev2 = 1
//prev = 2
//
//
//cur = max(2, 3 + 1) = 4
//prev2 = 2
//prev = 4
//
//
//cur = max(4, 1 + 2) = 4
//prev2 = 4
//prev = 4
//
//return

int main()
{
    std::cout << "Hello World!\n";
}
